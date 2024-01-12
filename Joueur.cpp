#include<iostream>
#include"Joueur.hpp"
#include"Piece.hpp"
#include"Plateau.hpp"
#include<vector>
#include<string>

using namespace std;

Joueur::Joueur(const string n, int s):m_nom{n}
{
	a_le_tour = false;
}; 


const string Joueur::get_m_nom()const{return m_nom;}

bool Joueur::jouerTour(int x, int y,int nx,int ny, Plateau &G)
{
	if(a_le_tour)
	{
        G.deplacer(x, y, nx, ny);
	 }
	 return false;
}
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
  	
