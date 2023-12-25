#ifndef DEF_PIECE
#define DEF_PIECE

#include <string>
#include <utility> // pour le vecteur pair

using namespace std;

class Piece {
public:
	Piece(int x, int y, string color, bool Dame = 0); //Constructeur
	void move(int newX, int newY); //Methode pour se d�placer

private:
	pair <int, int> m_position; //position de la pi�ces
	string m_couleur; //couleur de la pi�ce, blanc/noir
	bool m_Dame; //Vrai si on a une dame
};

#endif