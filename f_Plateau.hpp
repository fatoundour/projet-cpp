#ifndef _Plateau
#define _Plateau
#include<vector>
using namespace std;

class Pion;

class Plateau{
	friend class Pion;
	friend class Joueur;
	
public:
	Plateau(const int t);	//Constructeur
	void placer_pions();	//Propre au constructeur
	virtual ~Plateau();		//Libére la mémoire 

	const int get_m_taille()const;				//Getter
	vector<vector<Pion*>> get_m_plateau()const;	//Getter

	bool retirer(int x, int y);							//Pour retirer un pion de le Plateau qui est à la post (x,y) 
	Pion* peutSauter(int x , int y , int nx , int ny);	//Test si le pion à la pos (x,y) peut sauter pour aller à la pos (nx,ny) et renvoie le pion qu'il a capturé sinon renvoie nullptr
	Pion* sauter(int x , int y , int nx , int ny);		//Effectue la capture si possible et renvoie le pion capturé
	int calculValeurPion();								//Calcul la valeur totale des pions restants sur le Plateau
private:
	const int m_taille;				//Represente le nbre de cases de la Plateau
	vector<vector<Pion*>> m_plateau;//Vector de vector de pointeur de pions qui sont sur la Plateau	    
};
#endif
