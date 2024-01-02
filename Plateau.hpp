#ifndef DEF_PLATEAU
#define DEF_PLATEAU

#include <vector>
#include <utility>
#include "Piece.hpp"

using namespace std;

class Plateau {
public:
	Plateau(int largeur, int longueur); //Const
	void placer_piece();

	bool deplacer(int x_actuel, int y_actuel, int x_new, int y_new); //pr déplacer pièce
	void prendre(int x, int y); //prendre une piece
	bool mouv_possible(int x_actuel, int y_actuel, int x_new, int y_new);
	bool prise_possible(int x_actuel, int y_actuel, int x_new, int y_new);
	bool promo_possible(int x_new, int y_new);
	bool diag_libre(int x_act, int y_act, int x_new, int y_new); //Specifique au déplacement des dames
	vector <pair<int, int>> ens_des_mouv(int x, int y);

	~Plateau(); //Dest


private:
	vector <vector<Piece*>> m_plateau; //plateau en 2D
	int m_largeur, m_longueur; //dimension du plateau
};

#endif
