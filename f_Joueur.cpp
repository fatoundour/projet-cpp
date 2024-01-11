#include<iostream>
#include"f_Joueur.hpp"
#include"f_Pion.hpp"
#include"f_Plateau.hpp"
#include<vector>
#include<string>

using namespace std;

Joueur::Joueur(const string n, int s):m_nom{n},m_score{s}
{
	a_le_tour = false;
	m_pionCapturer= vector<Pion*>(64,nullptr);
}; 

Joueur::~Joueur()
{
	for(Pion *e: m_pionCapturer) 
	{ 
	   e = nullptr;
	   delete e;
	}
}

const string Joueur::get_m_nom()const{return m_nom;}

int Joueur::get_m_score()const{return m_score;}

vector<Pion*> Joueur::get_m_pionCapturer()const{return m_pionCapturer;}

bool Joueur::retirerPionJaune(int x,int y,Plateau& G)
{
	if(a_le_tour && G.get_m_plateau()[x][y] != nullptr && G.get_m_plateau()[x][y]->get_m_couleur() == "Yellow")
	{
		G.retirer(x,y);
		return true;
	}
	return false;
}

bool Joueur::choisirPionJaune(int x,int y,Plateau& G)
{
	if(G.get_m_plateau()[x][y] != nullptr && G.get_m_plateau()[x][y]->get_m_couleur() == "Yellow")
	{
		return true;
	}
	return false;
}
bool Joueur::jouerTour(int x, int y,int nx,int ny, Plateau & G)
{
	if(a_le_tour)
	{
	   if(choisirPionJaune(x,y,G))
	   {
	     Pion* q = G.sauter(x,y,nx,ny);
	     //ici q represente le pion capturé(sauté)
	     if(q!=  nullptr)//c'est à dire qu'il a sauté q
	     {
	       m_pionCapturer.push_back(q);
	       m_score = m_score + q->get_m_valeur();
	       //on retire apres le pion capturé de la Plateau
	       G.retirer(q->get_m_position().first, q->get_m_position().second);
	       
	     }
	   }
	 }
	 return false;
}
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
