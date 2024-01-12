#ifndef _JOUEUR
#define _JOUEUR
#include<vector>
#include<utility>
#include<string>

using namespace std;

class Piece;		//Declaration Préalable
class Plateau;	

class Joueur{
	friend class Plateau;
	friend class Piece;
	   
public:     
	Joueur(const string n,int s = 0);			//Constructeur           
	const string get_m_nom()const;	  			    	   
	bool jouerTour(int x, int y,int nx,int ny, Plateau &G);	//Déplace le Piece à la pos (x,y) choisi vers la case à la pos (nx,ny) sur la Plateau

	bool a_le_tour = false; //Public car sinon on ne peut pas le modifier

private:
	const string m_nom;				//Nom du joueur	    
};
#endif
	    
	    
	    
