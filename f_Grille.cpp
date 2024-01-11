#include"f_Pion.hpp"
#include"f_Plateau.hpp"

#include<iostream>
#include<vector>
#include<utility>

#include <algorithm>//Initialisation d'un plateau avec pièces placées aléatoirement
#include <random>

using namespace std;

Plateau::Plateau(const int h):m_taille{h}
{
	m_plateau = vector<vector<Pion*>>(h,vector<Pion*>(h,nullptr));
	placer_pions();
};

Plateau::~Plateau()
{
	for(vector<Pion*> l : m_plateau)
	{
		for(Pion* p : l)
		{
		     delete p;
		     p = nullptr;
		}
	}
}

void Plateau::placer_pions()
{
//Vecteur contenant la position des cases du Plateau
  vector<pair<int,int>> vec;
  pair<int,int> p;
  for(int i = 0;i<m_taille;i++)
  {
  	for(int j=0;j<m_taille;j++)
  	{
  		p = {i,j};
  		vec.push_back(p);
  		
  	}
  }
	// Initialisation du générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());

    // Mélanger l'ordre des éléments dans le vecteur
    shuffle(vec.begin(), vec.end(), gen);

     //definition des positions pour chaque pion sur la Plateau de manière aléatoire

      int k,f,s;
      for(int i = 0;i<m_taille;i++)
  	{
  		for(int j = 0;j<m_taille;j++)
  		{
  			k = i*m_taille+j;
  			f = vec[k].first;
  			s = vec[k].second;
  			if(k<34)
  			{
  			   m_plateau[f][s] = new Pion("Yellow",vec[k],3);
  			}
  			
  			else if(k>=34 && k<54)
  			{
  			   m_plateau[f][s] = new Pion("Red",vec[k],2);
  			}
  			
  			else
  			{
  			   m_plateau[f][s] = new Pion("Black",vec[k],1);
  			}
  		}
  	}
  	
}

const int Plateau::get_m_taille()const{return m_taille;}

vector<vector<Pion*>> Plateau::get_m_plateau()const{return m_plateau;}

bool Plateau::retirer(int x, int y)
{
	if(m_plateau[x][y] != nullptr)
	{
		delete m_plateau[x][y];
		m_plateau[x][y] = nullptr;
		return true;
	}
	
	return false;
}

Pion* Plateau::peutSauter(int x , int y,int nx,int ny)
{
		/* Dans cette fonction on verifie si la pos (nx,ny) qu'on veut aller est dans l'ensemble des deplacemt possi depuis la pos (x,y) si oui et que la case sauter n'est pas vide on renvoie cette case sinon on renvoie nullptr*/
	if(m_plateau[nx][ny] != nullptr)return nullptr;
	
	if(x == nx && y==ny-2 && m_plateau[x][y+1] != nullptr)return m_plateau[x][y+1];
	
	if(x == nx && y==ny+2 && m_plateau[x][y-1] != nullptr)return m_plateau[x][y-1];
	
	if(x == nx-2 && y==ny && m_plateau[x+1][y] != nullptr)return m_plateau[x+1][y];
	
	if(x == nx+2 && y==ny && m_plateau[x-1][y] != nullptr)return m_plateau[x-1][y];
	
	if(x == nx+2 && y==ny-2 && m_plateau[x-1][y+1] != nullptr)return m_plateau[x-1][y+1];
	
	if(x == nx+2 && y==ny+2 && m_plateau[x-1][y-1] != nullptr)return m_plateau[x-1][y-1];
	
	if(x == nx-2 && y==ny+2 && m_plateau[x+1][y-1] != nullptr)return m_plateau[x+1][y-1];
	
	if(x == nx-2 && y==ny-2 && m_plateau[x+1][y+1] != nullptr)return m_plateau[x+1][y+1];
	return nullptr;
}

Pion* Plateau::sauter(int x , int y , int nx , int ny)
{
	Pion * p = peutSauter(x,y,nx,ny);
	if(p!= nullptr)
	{
		m_plateau[x][y]->deplacer_pion(nx,ny);
		m_plateau[nx][ny] = m_plateau[x][y];
		m_plateau[x][y] = nullptr;
		return p;
	}
	return p;
}

int Plateau::calculValeurPion()
{
  int s = 0;
  for(int i = 0;i<m_taille;i++)
  	{
  		for(int j = 0;j<m_taille;j++)
  		{
  			if(m_plateau[i][j] != nullptr) s = s + m_plateau[i][j]->get_m_valeur();
  		}
  	}
  	return s;
}
	
	
	
	
	
	
	
	
	
	
	
	    
