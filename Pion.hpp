#ifndef _PION
#define _PION
#include<vector>
#include<utility>
#include<string>

using namespace std;


class Pion{
	private:
	    const string couleur;//couleur
	    pair<int,int> position_x_y;//position sur la grille
	    const int valeur;//valeur apportée par le pion
	    
	public:
	  Pion(string c,pair<int,int> p,int v);//cons
	  
	  Pion(const Pion&) = delete;//pas de copie donc on utilisera une reference de cette classe
	  
	  const string get_couleur() const;
	  
	  pair<int,int> get_position_x_y() const;
	  
	  const int get_valeur() const;
	  
	  void deplacer_pion(int nx, int ny);// pour deplacer un pion à la pos (nx,ny)
};
#endif
	    
