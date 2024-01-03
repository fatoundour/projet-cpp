#include<iostream>
#include"Pion.hpp"
#include"Grille.hpp"
#include<vector>
#include<utility>
#include <algorithm>
#include <random>
using namespace std;



Grille::Grille(const int h):taille{h}
{
	gcase = vector<vector<Pion*>>(h,vector<Pion*>(h,nullptr));
	placer_pions();
};

Grille::~Grille()
{
	for(vector<Pion*> l : gcase)
	{
		for(Pion* p : l)
		{
		     delete p;
		     p = nullptr;
		}
	}
}

void Grille::placer_pions()
{
	//vecteur contenant la position des cases de la grille
  vector<pair<int,int>> vec;
  pair<int,int> p;
  for(int i = 0;i<taille;i++)
  {
  	for(int j=0;j<taille;j++)
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
      //definition des positon pour chaque pion sur la grille de manière aléa
      int k,f,s;
      for(int i = 0;i<taille;i++)
  	{
  		for(int j = 0;j<taille;j++)
  		{
  			k = i*taille+j;
  			f = vec[k].first;
  			s = vec[k].second;
  			if(k<34)
  			{
  			   gcase[f][s] = new Pion("Yellow",vec[k],3);
  			}
  			
  			else if(k>=34 && k<54)
  			{
  			   gcase[f][s] = new Pion("Red",vec[k],2);
  			}
  			
  			else
  			{
  			   gcase[f][s] = new Pion("Black",vec[k],1);
  			}
  		}
  	}
  	
}

const int Grille::get_taille()const{return taille;}

vector<vector<Pion*>> Grille::get_gcase()const{return gcase;}

bool Grille::retirer(int x, int y)
{
	if(gcase[x][y] != nullptr)
	{
	    delete gcase[x][y];
	    gcase[x][y] = nullptr;
	   return true;
	}
	return false;
}

Pion* Grille::peut_sauter(int x , int y,int nx,int ny)
{
		/* Dans cette fonction on verifie si la pos (nx,ny) qu'on veut aller est dans l'ensemble des deplacemt possi depuis la pos (x,y) si oui et que la case sauter n'est pas vide on renvoie cette case sinon on renvoie nullptr*/
	if(gcase[nx][ny] != nullptr)return nullptr;
	
	if(x == nx && y==ny-2 && gcase[x][y+1] != nullptr)return gcase[x][y+1];
	
	if(x == nx && y==ny+2 && gcase[x][y-1] != nullptr)return gcase[x][y-1];
	
	if(x == nx-2 && y==ny && gcase[x+1][y] != nullptr)return gcase[x+1][y];
	
	if(x == nx+2 && y==ny && gcase[x-1][y] != nullptr)return gcase[x-1][y];
	
	if(x == nx+2 && y==ny-2 && gcase[x-1][y+1] != nullptr)return gcase[x-1][y+1];
	
	if(x == nx+2 && y==ny+2 && gcase[x-1][y-1] != nullptr)return gcase[x-1][y-1];
	
	if(x == nx-2 && y==ny+2 && gcase[x+1][y-1] != nullptr)return gcase[x+1][y-1];
	
	if(x == nx-2 && y==ny-2 && gcase[x+1][y+1] != nullptr)return gcase[x+1][y+1];
	return nullptr;
}

Pion* Grille::sauter(int x , int y , int nx , int ny)
{
	Pion * p = peut_sauter(x,y,nx,ny);
	if(p!= nullptr)
	{
		gcase[x][y]->deplacer_pion(nx,ny);
		gcase[nx][ny] = gcase[x][y];
		gcase[x][y] = nullptr;
		return p;
	}
	return p;
}

int Grille::calcule_val_pion()
{
  int s = 0;
  for(int i = 0;i<taille;i++)
  	{
  		for(int j = 0;j<taille;j++)
  		{
  			if(gcase[i][j] != nullptr) s = s + gcase[i][j]->get_valeur();
  		}
  	}
  	return s;
}
	
	
	
	
	
	
	
	
	
	
	
	    
