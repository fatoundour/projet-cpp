#ifndef _GRILLE
#define _GRILLE
#include<vector>
using namespace std;

class Pion;

class Grille{
	private:
	    const int taille;//  represente le nbre de cases de la grille
	    vector<vector<Pion*>> gcase;//vector de vector de pointeur de pions qui sont sur la grille
	public:
	    Grille(const int t);//constructeur
	    
	    virtual ~Grille();//libere la mémoire 
	    
	    const int get_taille()const;
	    
	    vector<vector<Pion*>> get_gcase()const;
	    
	    void placer_pions();
	    
	    bool retirer(int x, int y);//pour retirer un pion de la grille qui est à la pos (x,y) 
	    
	    Pion* peut_sauter(int x , int y , int nx , int ny);//teste si le pion à la pos (x,y) peut sauter pour aller à la pos (nx,ny) et renvoie le pion qu'il a capturé sinon renvoie nullptr
	    
	    Pion* sauter(int x , int y , int nx , int ny);//effectue le saut(la capture) si possi et renvoie le pion capturé
	    
	    int calcule_val_pion();//calcule la valeur totale des pions restants sur la grille
	    friend class Pion;
	    friend class Joueur;
	    
};
#endif
