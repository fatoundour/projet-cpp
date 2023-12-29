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
	    bool a_le_tour;//connaitre si le joueur a le tour de jouer
	public:
	    Joueur(const string n,int s = 0 ,bool alt = false);//cons
	    
	    virtual ~Joueur();//suppriler les données liées au joueur
	    
	    bool get_a_le_tour()const;
	    
	    const string get_nom()const;
	    
	    int get_score()const;
	    
	    vector<Pion*> get_pion_capturer()const;
	    
	    Pion * choisir_pion_jaune(Pion &p,Grille& G);//depuis la grille de jeu on recupere le pion p qu'il a choisi et on verifie si c'est un pion jaune et s'il est sur la grille si oui renvoie le pion sinon nullptr
	    
	    void jouer_tour(Pion &pi,int nx,int ny, Grille &G);//deplace le pion pi choisi vers la case à la pos (nx,ny) 
	    
	    int calcule_scoref();//calcule le score finale à la fin du jeu
};
#endif
	    
	    
	    
