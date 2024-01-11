#ifndef _GRILLE
#define _GRILLE
#include<vector>
using namespace std;

class Pion;

class Grille{
	    friend class Pion;
	    friend class Joueur;

	public:
	    Grille(int t); //Constructeur surchargé
      void placerPions();
	    virtual ~Grille(); //Destructeur  
	    const int getTaille() const;
	    vector<vector<Pion*>> get_gcase()const;
	    
	    bool retirer(int x, int y); //Méthode pour retirer un pion de la grille qui est à la pos (x,y)
	    Pion* peut_sauter(int x , int y , int nx , int ny); //*Teste si le pion à la pos (x,y) peut sauter pour aller à la pos (nx,ny) et renvoie le pion quil a capturé sinon renvoie nullptr */
	    Pion* sauter(int x , int y , int nx , int ny); //effectue le saut(la capture) si possible et renvoie le pion capturé
	    
	    int calculValeurPion();//calcule la valeur totale des pions restants sur la grille

  private:
	    const int m_taille;//  represente le nbre de cases de la grille
	    vector<vector<Pion*>> m_gcase;//vector de vector de pointeur de pions qui sont sur la grille

	    
};
#endif
