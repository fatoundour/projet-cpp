#include "Piece.hpp"
#include <iostream>

using namespace std; 

Piece::Piece(int x, int y, string couleur, bool Dame) : m_position(x, y), m_couleur(couleur), m_dame (Dame) {}

void Piece::afficher()
{
	cout << boolalpha;
	cout << "Position : "  << "( " << m_position.first << ";" << " " ;
	cout << m_position.second << " )" << endl;
	cout << "Couleur : " << m_couleur << endl;
	cout << "Est-ce une Dame ? : " << m_dame << endl;
}

Piece::~Piece ()
{}

string Piece::mat()
{
	if (m_dame && m_couleur == "BLANC")
	{
		return "DB";
	}
	else if (m_dame && m_couleur == "NOIR")
	{
		return "DN";
	}
	else if (!m_dame && m_couleur == "BLANC")
	{
		return "B ";
	}
	else if (!m_dame && m_couleur == "NOIR"){
		return "N ";
	}
	else { return "Error"; }
}

pair <int, int> Piece::getPosition() const {
	return m_position;
}

string Piece::getCouleur() const {
	return m_couleur;
}

bool Piece::getDame() const {
	return m_dame;
}