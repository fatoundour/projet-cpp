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
		for (int j = ((i + 1) % 2); j < m_largeur; j+= 2)
		{
			m_plateau[j][i] = new Piece(j, i, "noir", 0); //PENSER  A GERER LE DESTRUCTEUR
		}
	}
}

//Deplacer
/*bool Plateau::deplacer(int x_actuel, int y_actuel, int x_new, int y_new)
{
	if (!mouv_possible(x_actuel, y_actuel, x_new, y_new)) //On v�rif si le depl est autoris�
	{
		return false; //refuse si pas possibole
	}
	else
	{
		return true;
		//Voir si on peut prendre ou pas
	}

	//On v�rif si on a une promotion possible
	if (promo_possible (x_new,y_new))
	{
		m_plateau[y_new][x_new]->m_Dame = true;
	}

} */

//Prend une case en entr�e et v�rif si il y a une piece sur cette case et que
bool Plateau::promo_possible(int x_new, int y_new)
{
	Piece* piece = m_plateau[y_new][x_new];
	if (piece && piece->m_Dame != true) //On v�rif que ce n'est pas une dame et qu'on � bien une piece, if(piece) verifie que le pointeur est non nul 
	{
		if (piece->m_couleur == "blanc" && y_new == m_longueur - 1)
		{
			return true;
		}
		else if (piece->m_couleur == "noir" && y_new == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else 
	{
		return false;
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

	 //On stock la couleur et la direction de d�placement
	string couleur = piece->m_couleur;
	int dx = x_actuel - x_new;
	int dy = y_actuel - y_new;


	
	//Distinction des cas si on � une dame ou pas
	if (piece->m_Dame)
	{
		//Distinguer si on a une piece noir / blanche 
		if (diag_libre (x_actuel, y_actuel, x_new, y_new))
		{
			return true;
		}

		else 
		{
			return false;
		}
		//Ajouter le cas ou une prise possible

	}
	else
	{
		//Cas piece blanche
		if (piece->m_couleur == "blanc")
		{
			//Cas piece haut, droite
			if (dx == 1 && dy == -1) //Pas besoin de v�rif que la case est vide on a v�rif pr�cedemnt
			{
				return true;
			}
			//piece haut, gauche 
			else if (dx == -1 && dy == -1)
			{
				return true;
			}
			else if (prise_possible(x_actuel, y_actuel, x_new, y_new)) //Si on est ps dans les diag adj, alors regarde si il y a une prise possible, si c'est le cas on prend
			{//Attention � l'arg, mettre la couleur ds prise possible
				prendre(x_new, y_new); 
				return true;
			}

			else
			{
				return false;
			}
		}

		//Cas Piece noir
		else
		{
			//Cas piece bas, gauche
			if (dx == -1 && dy == 1) //Pas besoin de v�rif que la case est vide on a v�rif pr�cedemnt
			{
				return true;
			}
			//piece bas, droite 
			else if (dx == 1 && dy == 1)
			{
				return true;
			}
			else if (prise_possible(x_actuel, y_actuel, x_new, y_new)) //Si on est ps dans les diag adj, alors regarde si il y a une prise possible, si c'est le cas on prend
			{//Attention � l'arg, mettre la couleur ds prise possible
				prendre(x_new, y_new);
				return true;
			}

			else
			{
				return false;
			}
		}
	}
}

bool Plateau::diag_libre(int x_act, int y_act, int x_new, int y_new)
{
	int dx = x_act - x_new;
	int dy = y_act - y_new;
	if (dx < 0) { dx = -1; }
	else if (dx > 0) { dx = 1; }
	else { return false; } //Eviter le cas ligne droite avant
	if (dy < 0) { dy = -1; }
	else if (dy > 0) { dy = 1; }
	else { return false; }

	int x = x_act + dx;
	int y = y_act + dy;

	while (x != x_new && y != y_new) {
		if (m_plateau[y][x] != nullptr)
		{
			return false;
		}
		x += dx;
		y += dy;
	}

	return true;

	//Diag_libre mais marche pas
	/*
	if (dx < 0 && dy <0) //D�plct vers la droite en haut
	{
		for (int i = x_act; i <= x_new; i++)
		{
			if (m_plateau[y_act + i][x_act + i] != nullptr) { return false; }
		}
		return true;
	}

	else if (dx > 0) //D�plc vers la gauche 
	{
		for (int i = x_act; i >= x_new; i--)
		{
			if (m_plateau[y_act + i][x_act - i] != nullptr) { return false; }
		}
		return true;
	}
	else if (dx == 0 || dy == 0)
	{
		return false;
	}
} */


bool Plateau::prise_possible(int x_actuel, int y_actuel, int x_new, int y_new) //peut etre ajouter la couleur en argument
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

	//On r�cup�re la couleur de la pi�ce : 
	string couleur_piece = piece->m_couleur;
	//On r�cup�re les directions de la piece
	int dx = x_actuel - x_new;
	int dy = y_actuel - y_new;


	//V�rif que il y a une piece adverse entre la case de destination et la case actuel : // A FAIRE
	if (m_plateau[y_new][x_new] == nullptr || m_plateau[y_new][x_new]->m_couleur == couleur_piece)
	{
		return false;
	}


	// Distinction des cas si on � une dame ou pas
	if (piece->m_Dame)
	{
		if (dx < 0 && dy > 0) //Prise en bas, � droite
		{
			if (diag_libre(x_actuel, y_actuel, x_new - 1, y_new + 1) && m_plateau[y_new - 1][x_new + 1] == nullptr)
			{
				return true;
			}

		}

		else if (dx > 0 && dy < 0) //Prise en bas, � gauche
		{
			if (diag_libre(x_actuel, y_actuel, x_new + 1, y_new + 1) && m_plateau[y_new - 1][x_new - 1] == nullptr)
			{
				return true;
			}
		}

		else if (dx < 0 && dy < 0) //Prise en haut � gauche
		{
			if (diag_libre(x_actuel, y_actuel, x_new - 1, y_new - 1) && m_plateau[y_new + 1][x_new + 1] == nullptr)
			{
				return true;
			}
		}

		else if (dx > 0 && dy > 0) //Prise en haut, � droite 
		{
			if (diag_libre(x_actuel, y_actuel, x_new - 1, y_new - 1) && m_plateau[y_new + 1][x_new + 1] == nullptr)
			{
				return true;
			}
		}

		else //Tester si pas d'autres cas
		{
			return false;
		}
	}

	//CAS PION
	else 
	{
		if (piece->m_couleur == "blanc")
		{
			if (dx == 0) //La case n'est pas en diagonale 
			{
				return false;
			} //Rajouter les y

			else if (dx < 0 && dy > 0 //On est dans une position devant, et � droite
				&& m_plateau[y_actuel +1][x_actuel +1] != nullptr  //Si il y a une piece en face
				&& m_plateau[y_actuel + 1][x_actuel + 1]->m_couleur != couleur_piece //Et quelle est de couleurs diff�rentes 
				&& m_plateau[y_new][x_new] == nullptr) //Et que la case d'apr�s est vide	
			{
				return true;
			}

			else if (dx > 0 && dy>0
				&& m_plateau[y_actuel + 1][x_actuel - 1] != nullptr 
				&& m_plateau[y_actuel + 1][x_actuel - 1]->m_couleur != couleur_piece
				&& m_plateau[y_new][x_actuel]->m_couleur != couleur_piece)
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		else //Cas piece noir
		{

		}
		
		//On diff�rencie les cas si on a une piece blanche 
		//Cas 1 : (x_new,y_new) est une case diag a � une dist exactmnt 2 : 
			//si on a une piece adverse entre (x_act, y_act) et que la case (x_new, y_new) est libre, on peut prendre 
			// sinon pas possible
		if (dx )
	
		if (m_plateau[y_new + 1][x_new + 1] == nullptr) //Probleme, ne marche que si on veut prendre � droite
		{
			return true;
		}
		//Cas 2: Sinon on renvoie faux.

	}



}

/*vector <pair<int, int>> Plateau::ens_des_mouv(int x, int y)
{
	return <<x, y>>;
} */

