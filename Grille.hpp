#ifndef _GRILLE
#define _GRILLE
#include<vector>
using namespace std;

class Pion;

class Grille{
	private:
	    const int hauteur;// hauteur et largeur represente les dimensions de la grille
	    const int largeur;
	    vector<vector<Pion*>*> gcase;//vetor de pointeur qui pointent vers un vector de pointeur de pions pour faciliter la suppression totale de la grille et eviter les pertes de données
	public:
	    Grille(const int h,const int l);//constructeur
	    
	    virtual ~Grille();//libere la mémoire 
	    
	    const int get_hauteur()const;
	    
	    const int get_largeur()const;
	    
	    vector<vector<Pion*>*> get_gcase()const;
	    
	    Pion* retirer(int x, int y);//pour retirer un pion de la grille qui est à la pos (x,y) renvoie le pion si il a été retiré nullptr sinon
	    
	    Pion* peut_sauter(int x , int y , int nx , int ny);//teste si le pion à la pos (x,y) peut sauter pour aller à la pos (nx,ny) et renvoie le pion qu'il a capturé sinon renvoie nullptr
	    
	    Pion* sauter(int x , int y , int nx , int ny);//effectue le saut(la capture) si possi et renvoie le pion capturé
	    
};
#endif

