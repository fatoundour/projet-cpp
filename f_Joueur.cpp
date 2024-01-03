#include<iostream>
#include"Joueur.hpp"
#include"Pion.hpp"
#include"Grille.hpp"
#include<vector>
#include<string>

using namespace std;

Joueur::Joueur(const string n, int s):nom{n},score{s}
{
	a_le_tour = false;
	pion_capturer= vector<Pion*>(64,nullptr);
}; 

Joueur::~Joueur()
{
	for(Pion *e: pion_capturer) 
	{ 
	   e = nullptr;
	   delete e;
	}
}

const string Joueur::get_nom()const{return nom;}

int Joueur::get_score()const{return score;}

vector<Pion*> Joueur::get_pion_capturer()const{return pion_capturer;}

bool Joueur::retirer_pion_jaune(int x,int y,Grille& G)
{
	if(a_le_tour && G.get_gcase()[x][y] != nullptr && G.get_gcase()[x][y]->get_couleur() == "Yellow")
	{
		G.retirer(x,y);
		return true;
	}
	return false;
}

bool Joueur::choisir_pion_jaune(int x,int y,Grille& G)
{
	if(G.get_gcase()[x][y] != nullptr && G.get_gcase()[x][y]->get_couleur() == "Yellow")
	{
		return true;
	}
	return false;
}
bool Joueur::jouer_tour(int x, int y,int nx,int ny, Grille & G)
{
	if(a_le_tour)
	{
	   if(choisir_pion_jaune(x,y,G))
	   {
	     Pion* q = G.sauter(x,y,nx,ny);
	     //ici q represente le pion capturé(sauté)
	     if(q!=  nullptr)//c'est à dire qu'il a sauté q
	     {
	       pion_capturer.push_back(q);
	       score = score + q->get_valeur();
	       //on retire apres le pion capturé de la grille
	       G.retirer(q->get_position_x_y().first, q->get_position_x_y().second);
	       
	     }
	   }
	 }
	 return false;
}
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
