#include "Plateau.hpp"
#include "Piece.hpp"

#include <iostream>

using namespace std;

Plateau::Plateau(int lignes, int colonnes) : m_lignes(lignes), m_colonnes(colonnes)
{
	//On initialise un tableau Lxl avec des pointeurs nuls partout (pr l'instant)
	m_plateau = vector <vector<Piece*>>(lignes, vector <Piece*>(colonnes, nullptr));
    //On place les pièces sur le plateau grace à une fct placer_piece
    //placerPiece();
}

//METHODE PLACER PIECE 
/*
void Plateau::placerPiece()
{
    for (int l = 0; l < 4; l++) { // On place les pièces noirs
        for (int c = 0; c < m_colonnes; c++) {
            if ((l + c) % 2 == 1) { // seulement sur les cases noires
                m_plateau[l][c] = new Piece(l, c, "NOIR", false);
            }
        }
    }
    
    for (int l = m_lignes -1; l > m_lignes - 5; l--) { // Puis les pièces blanches
        for (int c = 0; c < m_colonnes; c++) {
            if ((l + c) % 2 == 1) { 
                m_plateau[l][c] = new Piece(l, c, "BLANC", false);
            }
        }
    }
}
*/



Plateau::~Plateau() {
    for (int i = 0; i < m_lignes; i++) {
        for (int j = 0; j < m_colonnes; j++) {
            if (m_plateau[i][j] != nullptr)
            { 
                delete m_plateau[i][j];  // Libère la mémoire de chaque pièce
                m_plateau[i][j] = nullptr;  // Assurez-vous de mettre le pointeur à nullptr après la suppression
            }
            
        }
    }
}

void Plateau::afficherPlat()
{
    for (int i = 0; i < m_lignes; i++) {
        for (int j = 0; j < m_colonnes; j++) {
            if (m_plateau[i][j] == nullptr) {
                cout << "- ";  // Case vide
            }
            else {
                cout << m_plateau[i][j]->mat();  // Affiche un symbole représentant la pièce avc methode mat
            }
        }
        cout << endl;
    }
}

void Plateau::ajouterPiece(int x, int y, string couleur, bool estDame) {
    //On vérifie la position
    if (x >= 0 && x< m_lignes && y>= 0 && y< m_colonnes && m_plateau[x][y] == nullptr) {
        m_plateau[x][y] = new Piece(x, y, couleur, estDame); //On crée une piece et on la place sur le plateau, on rpl que m_plateau est de type Piece*
    }
    else {
        cout << "Erreur" << endl;
    }
}

void Plateau::deplacer(int x_act, int y_act, int x_new, int y_new)
{
    if (mouvPossible(x_act, y_act, x_new, y_new))
    {
        Piece* pieceA = m_plateau[x_act][y_act];

        m_plateau[x_new][y_new] = pieceA;
        m_plateau[x_act][y_act] = nullptr; //Est-ce utile de MAJ la position de la pièces ? 
    }
    else
    {
        cout << "Mouvement impossible" << endl;
    }
}

bool Plateau::mouvPossible(int x_act, int y_act, int x_new, int y_new)
{
    //1. Vérification limites du plateau
    if (x_act < 0 || x_act >= m_lignes || y_act < 0 || y_act >= m_colonnes
        || x_new < 0 || x_new >= m_lignes || y_new < 0 || y_new >= m_colonnes)
    {    return false; }

    //2. On vérifie qu'on à bien une pièce à déplacer
    if (m_plateau[x_act][y_act] == nullptr)
    {    return false;}

    //3.On vérifie que la case de destination est vide : 
    if (m_plateau[x_new][y_new] != nullptr)
    {  return false;}

    //4. On récupère le pointeur de la piece qu'on veut déplacer
    Piece* pieceA = m_plateau[x_act][y_act];
    
    //5. On stock la couleur de la pièce et la direction de déplacement 
    string couleurA = pieceA->m_couleur;

    int dx = x_act - x_new;
    int dy = y_act - y_new;
    int x_int = (x_act + x_new) / 2; //Pour la prise des pions
    int y_int = (y_act + y_new) / 2;

    //6. Cas des Dames  :
    if (pieceA->m_dame)
    {
        //Cas dame blanche
        if (pieceA->m_couleur == "BLANC")
        {
            if (diagLibre(x_act, y_act, x_new, y_new))
            {
                return true;
            }
            else
            {
                if (priseDame(x_act, y_act, x_new, y_new,  "BLANC"))
                {
                    return true;
                }
            }
        }
        //return false;
    }

    //7. Cas des pions 

    //Pour les BLANCS

    else if (!pieceA->m_dame && couleurA == "BLANC")
    {
        //Deplacement SANS prise 
        if (dx == 1 && dy == -1) { return true; } //Deplacement à droite en haut (piece blanche)
        else if (dx == 1 && dy == 1) { return true; } //à gauche en haut (piece blanche)

        //Deplacement AVEC prise 
        else if (dx == 2 && dy == 2) //haut gauche (blanc)
        {
            if (prisePossiblePion(x_int, y_int, "BLANC"))
            {
                prendrePion(x_int, y_int);
                return true;
            }
            else { return false; }
                  
        }
        else if (dx == 2 && dy == -2) //haut droite (blanc)
        {
            if (prisePossiblePion(x_int, y_int, "BLANC"))
            {
                prendrePion(x_int, y_int);
                return true;
            }
            else { return false; }
        }

        else { return false; }
    }

    //Pour les NOIRS 
    else if (!pieceA->m_dame && couleurA == "NOIR")
    {
        //Deplacement SANS prise
        if (dx == -1 && dy == -1) { return true; } //deplacement en bas à droite (piece noir)
        else if (dx == -1 && dy == 1) { return true; }//deplcmtn en bas à gauche (piece noir)

        //Deplacement AVEC prise 
        else if (dx == -2 && dy == -2) //bas droite (noir)
        {
            if (prisePossiblePion(x_int, y_int, "NOIR"))
            {
                prendrePion(x_int, y_int);
                return true;
            }
            else { return false; }
        }
        else if (dx == -2 && dy == 2)
        {
            if (prisePossiblePion(x_int, y_int, "NOIR"))
            {
                prendrePion(x_int, y_int);
                return true;
            }
            else { return false; }
        }
        else { return false; }
    }
   
}

bool Plateau::prisePossiblePion(int x_int, int y_int, string couleurPiece)
{
    if (m_plateau[x_int][y_int] != nullptr && m_plateau[x_int][y_int]->m_couleur != couleurPiece) //On a une piece ET de couleurs différentes
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Plateau::priseDame(int x_act, int y_act, int x_new, int y_new, std::string couleurPiece)
{
    //Vérifie si diag_libre avant la piece
    return true;
}

bool Plateau::diagLibre(int x_act, int y_act, int x_new, int y_new)
{
    int dx = x_act - x_new;
    int dy = y_act - y_new;

    if (dx > 0 && dy > 0) //Deplcmt haut gauche
    {
        for (int i = 1; i < abs(dx); i++) //i ne va pas jusqu'à x_new mais jusqu'a |dx| ! De plus i vérifie seulement les cases avant (x_new,y_new) et pas la case (x_new, y_new déjà vérifié avant)
        {
            if (m_plateau[x_act-i][y_act-i] != nullptr)
            {
                return false;
            }
        }
        return true; //La diag est vide
    }

    else if (dx > 0 && dy<0) //haut droit
    {
        for (int i = 1; i < abs(dx); i++) 
        {
            if (m_plateau[x_act - i][y_act + i] != nullptr)
            {
                return false;
            }
        }
        return true; //La diag est vide
    }

    else if (dx < 0 && dy >0) //bas gauche
    {
        for (int i = 1; i < abs(dx); i++)
        {
            if (m_plateau[x_act + i][y_act - i] != nullptr)
            {
                return false;
            }
        }
        return true; //La diag est vide
    }

    else if (dx < 0 && dy < 0) //bas droit
    {
        for (int i = 1; i < abs(dx); i++)
        {
            if (m_plateau[x_act + i][y_act + i] != nullptr)
            {
                return false;
            }
        }
        return true; //La diag est vide
    }

    else { return false; }
}

void Plateau::prendrePion(int x_int, int y_int) //Prend une position en paramètre, delete la piece associé, et met la case en nullptr
{
    if (m_plateau[x_int][y_int] != nullptr)
    {
        delete m_plateau[x_int][y_int];  // Libère la mémoire de la pièce
        m_plateau[x_int][y_int] = nullptr;
    }
    else {
        cout << "Prise impossible, pas de pièces présentes" << endl;
    }
}
