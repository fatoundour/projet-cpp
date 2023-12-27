#include "Plateau.hpp"
#include "Piece.hpp"

Plateau::Plateau(int largeur, int longueur): m_largeur(largeur), m_longueur(longueur)
{
	//On initialise un tableau Lxl avec des pointeurs nuls partout (pr l'instant)
	m_plateau = vector<vector<Piece*>>(largeur, vector<Piece*>(longueur, nullptr));
	//On place les pi�ces sur le plateau grace � une fct placer_piece
	placer_piece();
}

void Plateau::placer_piece()
{
	//Pour les pi�ces blanches 
	for (int i = 0; i < 3; i++) //On les places sur les 4 premi�res lignes
	{
		for (int j = (i % 2); j < m_largeur; j += 2) //On alterne piece/case vide
		{
			m_plateau[j][i] = new Piece(j, i, "blanc", 0);
		}
	}

	//Pour les pi�ces noirs, pareil mais on place en haut du plateau
	for (int i = m_longueur - 3; i < m_longueur; i++)
	{
		for (int j = ((i + 1) % 2); i < m_largeur; i += 2)
		{
			m_plateau[j][i] = new Piece(j, i, "noir", 0);
		}
	}
}



bool Plateau::deplacer(int x_actuel, int y_actuel, int x_new, int y_new)
{
	if (!mouv_possible(x_actuel, y_actuel, x_new, y_new)) //On v�rif si le depl est autoris�
	{
		return false; //refuse si pas possibole
	}

}

void Plateau::prendre(int x, int y)
{

}

bool Plateau::mouv_possible(int x_actuel, int y_actuel, int x_new, int y_new)
{
	//On v�rifie les limites du plateau
	if (x_actuel < 0 || x_actuel >= m_largeur || y_actuel < 0 || y_actuel >= m_longueur 
		|| x_new < 0 || x_new >= m_largeur || y_new < 0 || y_new >= m_longueur)
	{
		return false;
	}

	//On v�rif qu'on a bien une piece � d�placer
	if (m_plateau[y_actuel][x_actuel] == nullptr)
	{
		return false;
	}

	//Si on a une piece on l'associe � la case correspondantes
	Piece* piece = m_plateau[y_actuel][x_actuel];

	//V�rif que la case de destination est vide :
	if (m_plateau[y_new][x_new] != nullptr)
	{
		return false;
	}

	//Distinction des cas si on � une dame ou pas
	if (piece->m_Dame)
	{
		//Mouvement possible pour dame
	}
	else
	{

	}
}

vector <pair<int, int>> Plateau::ens_des_mouv(int x, int y)
{

}

