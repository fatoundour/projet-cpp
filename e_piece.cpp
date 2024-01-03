#include "Piece.hpp"

Piece::Piece(int x, int y, string couleur, bool Dame) :
	m_position(x, y), m_couleur(couleur), m_Dame(Dame) {} //Constr surcharg

void Piece::move(int newX, int newY) {
	m_position = { newX,newY };
}
