#include<iostream>
#include"Pion.hpp"
#include"Grille.hpp"
#include<vector>

using namespace std;



Grille::Grille(const int h,const int l):hauteur{h},largeur{l}{};

Grille::~Grille()
{
	for(vector<Pion*>* l : gcase)
	{
		for(Pion* p : *l)
		{
		     delete p;
		}
		delete l;
	}
}

const int Grille::get_hauteur()const{return hauteur;}

const int Grille::get_largeur()const{return largeur;}

vector<vector<Pion*>*> Grille::get_gcase()const{return gcase;}

Pion* Grille::retirer(int x, int y)
{
	Pion *p = (*gcase[x])[y];
	delete (*gcase[x])[y];
	return p;
}
Pion* Grille::peut_sauter(int x , int y,int nx,int ny)
{
	/* Dans cette fonction on verifie si la pos (nx,ny) qu'on veut aller est dans l'ensemble des deplacemt possi depuis la pos (x,y) si oui et que la case sauter n'est pas vide on renvoie cette case sinon on renvoie nullptr*/
	if((*gcase[nx])[ny] != nullptr)return nullptr;
	
	if(x == nx && y==ny-2 && (*gcase[x])[y+1] != nullptr)return (*gcase[x])[y+1];
	
	if(x == nx && y==ny+2 && (*gcase[x])[y-1] != nullptr)return (*gcase[x])[y-1];
	
	if(x == nx-2 && y==ny && (*gcase[x+1])[y] != nullptr)return (*gcase[x+1])[y];
	
	if(x == nx+2 && y==ny && (*gcase[x-1])[y] != nullptr)return (*gcase[x-1])[y];
	
	if(x == nx+2 && y==ny-2 && (*gcase[x-1])[y+1] != nullptr)return (*gcase[x-1])[y+1];
	
	if(x == nx+2 && y==ny+2 && (*gcase[x-1])[y-1] != nullptr)return (*gcase[x-1])[y-1];
	
	if(x == nx-2 && y==ny+2 && (*gcase[x+1])[y-1] != nullptr)return (*gcase[x+1])[y-1];
	
	if(x == nx-2 && y==ny-2 && (*gcase[x+1])[y+1] != nullptr)return (*gcase[x+1])[y+1];
	
	return nullptr;
}
Pion* Grille::sauter(int x , int y , int nx , int ny)
{
	Pion * p = peut_sauter(x,y,nx,ny);
	if(p!= nullptr)
	{
		(*gcase[x])[y]->deplacer_pion(nx,ny);
		gcase[nx][ny] = gcase[x][y];
		delete (*gcase[x])[y];
		return p;
	}
	return p;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	    
