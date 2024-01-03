#ifndef _JOUEUR
#define _JOUEUR
#include<vector>
#include<utility>
#include<string>

using namespace std;

class Pion;
class Grille;

class Joueur{
	private:
	    const string nom;//nom du joueur
	    int score;
	    vector<Pion*> pion_capturer;//pions que le joueur a capturé
	   
	public:
	     bool a_le_tour = false;//connaitre si le joueur a le tour de jouer
	     
	    Joueur(const string n,int s = 0);//cons
	    
	   virtual ~Joueur();//supprimer les données liées au joueur
	    
	    const string get_nom()const;
	    
	    int get_score()const;
	    
	    vector<Pion*> get_pion_capturer()const;
	    
	   bool retirer_pion_jaune(int x,int y,Grille& G);//retirer pion jaune
	    
	   bool choisir_pion_jaune(int x,int y,Grille& G);//depuis la grille de jeu on recupere le pion à la pos x,y qu'il a choisi et on verifie si c'est un pion jaune et s'il est sur la grille si oui renvoie true
	    
	   bool jouer_tour(int x, int y,int nx,int ny, Grille &G);//deplace le pion à la pos x,y choisi vers la case à la pos (nx,ny) sur la grille
	   
	    friend class Grille;
	    friend class Pion;
};
#endif
	    
	    
	    
