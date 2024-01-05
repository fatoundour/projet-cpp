#ifndef DEF_PLATEAU
#define DEF_PlATEAU

#include <vector>
#include <utility>
#include "Piece.hpp"

class Plateau {
public:
	Plateau(int lignes, int colonnes); 
	// void placerPiece(); //en commentaire
	void afficherPlat();
	void ajouterPiece(int x, int y, std::string couleur, bool estDame);
	void deplacer(int x_act, int y_act, int x_new, int y_new);
	bool mouvPossible(int x_act, int y_act, int x_new, int y_new);
	bool prisePossiblePion(int x_int, int y_int, std::string couleurPiece);
	void prendrePion(int x_int, int y_int);
	bool priseDame(int x_act, int y_act, int x_new, int y_new, std::string couleurPiece);
	bool diagLibre(int x_act, int y_act, int x_new, int y_new);
	~Plateau();


private:
	int const m_lignes, m_colonnes;
	std::vector <std::vector <Piece*>> m_plateau;

};
#endif
