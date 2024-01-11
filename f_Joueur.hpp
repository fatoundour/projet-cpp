#ifndef _JOUEUR
#define _JOUEUR
#include<vector>
#include<utility>
#include<string>

using namespace std;

class Pion;		//Declaration Préalable
class Plateau;	

class Joueur{
	friend class Plateau;
	friend class Pion;
	   
public:     
	Joueur(const string n,int s = 0);			//Constructeur    
	virtual ~Joueur();							//supprimer les données liées au joueur        
	const string get_m_nom()const;	    
	int get_m_score()const;	    	    
	vector<Pion*> get_m_pionCapturer()const;
	bool a_le_tour = false;							//Connaitre si le joueur a le tour de jouer	
	bool retirerPionJaune(int x,int y,Plateau& G);	//Retirer pion jaune	    	   
	bool choisirPionJaune(int x,int y,Plateau& G);	//Depuis la Plateau de jeu on récupère le pion à la pos x,y qu'il a choisi et on verifie si c'est un pion jaune et s'il est sur la Plateau si oui renvoie true	    	   
	bool jouerTour(int x, int y,int nx,int ny, Plateau &G);	//Déplace le pion à la pos (x,y) choisi vers la case à la pos (nx,ny) sur la Plateau

private:
	const string m_nom;				//Nom du joueur
	int m_score;					//Score du joueur
	vector<Pion*> m_pionCapturer;	//Pions que le joueur a capturé
	    
};
#endif
	    
	    
	    
