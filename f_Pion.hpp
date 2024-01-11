#ifndef _PION
#define _PION
#include<vector>
#include<utility>
#include<string>

using namespace std;


class Pion{
	friend class Plateau;
	friend class Joueur;
    
public:
	Pion(string c,pair<int,int> p,int v);	//Constructeur surchargé
	Pion(const Pion&) = delete;				//pas de copie donc on utilisera une reference de cette classe
	virtual ~Pion();						//Destructeur
	const string get_m_couleur() const;		//Getter
	pair<int,int> get_m_position() const;	//Getter
	const int get_m_valeur() const;			//Getter
	void deplacer_pion(int nx, int ny);		// Pour deplacer un pion à la pos (nx,ny)

private:
	const string m_couleur;					//m_couleur
	pair<int, int> m_position;				//position sur la Plateau
	const int m_valeur;						//m_valeur apportée par le pion
};
#endif
	    
