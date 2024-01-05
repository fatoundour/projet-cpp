#ifndef DEF_PIECE
#define DEF_PIECE

#include <string>
#include <utility>

class Piece {
	friend class Plateau;

public:
	Piece(int x, int y, std::string color, bool Dame = 0); //Const
	void afficher(); //A ENLEVER
	std::string mat(); //A ENLEVER
	~Piece(); //Dest

private:
	std::pair <int, int> m_position; //Position de la piece
	std::string m_couleur; // BLANC ou NOIR
	bool m_dame; //V si Dame

};

#endif
