#include<iostream>
#include"Joueur.hpp"
#include"Pion.hpp"
#include"Grille.hpp"
#include<vector>
#include<string>

using namespace std;

Joueur::Joueur(const string n,int s,bool alt):nom{n},score{s},a_le_tour{alt}{}; 

Joueur::~Joueur()
{
	for(Pion *e: pion_capturer) delete e;
}

bool Joueur::get_a_le_tour()const{return a_le_tour;}

const string Joueur::get_nom()const{return nom;}

int Joueur::get_score()const{return score;}

vector<Pion*> Joueur::get_pion_capturer()const{return pion_capturer;}

Pion * choisir_pion_jaune(Pion &p,Grille& G)
{
	pair<int,int> c = p.get_position_x_y();
	int x = c.first, y = c.second;
	if(p.get_couleur() == "Yellow" && x < G.get_largeur() && y < G.get_hauteur() && x>=0 && y>=0)
	{
		return &p;
	}
	return nullptr;
}
void Joueur::jouer_tour(Pion &pi,int nx,int ny, Grille & G)
{
	if(a_le_tour)
	{
	   Pion * q ;
	   if(choisir_pion_jaune(pi,G) != nullptr)
	   {
	     pair<int,int> c = pi.get_position_x_y();
	     int x = c.first, y = c.second;
	     q = G.sauter(x,y,nx,ny);
	     //ici q represente le pion capturé(sauté)
	     if(q!=  nullptr)
	     {
	       pion_capturer.push_back(q);
	       //on retire apres le pion capturé de la grille
	       G.retirer(q->get_position_x_y().first, q->get_position_x_y().second);
	       
	     }
	   }
	 }
}
  	
int Joueur::calcule_scoref()
{
	int s = 0;
	for(Pion * e : pion_capturer) s = s + e->get_valeur();
  	return s; 
}
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
