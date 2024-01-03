#include<iostream>
#include "Grille.hpp"
#include "Pion.hpp"
#include "Joueur.hpp"
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

int nb_tape=0;//variable globale qui permet aus joueurs de retirer un pion jaune au debut de la partie

int i,j,ni,nj;//variable globale qui permet de recuperer la position de l'ancien et le noveau pion cliqué

int main()
{
  	//génération des instances de classes
      Grille  G(8);
      Joueur j1("Joueur1"), j2("Joueur2");
      j1.a_le_tour = true;
      
    // Créer une fenêtre SFML
   RenderWindow window(VideoMode(900, 640), "Jeu Butin");
   
    // Boucle principale
    while (window.isOpen()) {
        // Gérer les événements
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::MouseButtonPressed)
              {
              	 nb_tape++;
              	 i = ni;
              	 j = nj;
              	 ni = event.mouseButton.x/80;
              	 nj = event.mouseButton.y/80;
              	 if(nb_tape<3)
              	 {
              	    if(j1.retirer_pion_jaune(ni,nj,G))
              	      {
              	         j1.a_le_tour = false;
              	         j2.a_le_tour = true;
              	      }
              	     else if(j2.retirer_pion_jaune(ni,nj,G))
              	      {
              	         j2.a_le_tour = false;
              	         j1.a_le_tour = true;
              	      }
              	   }
              	   else
              	   {
              	      j1.jouer_tour(i,j,ni,nj,G);
              	      j2.jouer_tour(i,j,ni,nj,G);
              	   }
              	 
              }
              /*si le joueur ayant le tour de jouer appuie sur le bouton entrée 
              alors il signale la non possibilité de encore jouer avec le pion de départ
              ou qu'il ne veut plus sauter*/
              if(event.type == Event::KeyPressed) 
              {
                  if (event.key.code == sf::Keyboard::Enter) 
                  {
                      if(j1.a_le_tour)
                      {
                        j1.a_le_tour = false;
                        j2.a_le_tour = true;
                        //j1.retirer_pion(G);
                      }
                      else 
                      {
                        j1.a_le_tour = true;
                        j2.a_le_tour = false;
                        //j2.retirer_pion(G);
                      }
                  }
                  //fin de partie
                  if (event.key.code == sf::Keyboard::F) 
                  {
                     if(j1.a_le_tour)
                      {
                         window.clear(Color::White);
                          Font font;
         		  font.loadFromFile("/usr/share/fonts/truetype/liberation2/LiberationSans-Regular.ttf");
         		  Text t;
   	 		  t.setFont(font);
   	 		  int x = j2.get_score() - G.calcule_val_pion();
   	 		  int y = j1.get_score();
   	 		  if(x > y)t.setString("FIN DE PARTI : " + j2.get_nom() + " GAGNE " + to_string(x) + " a " + to_string(y));
    	 		  else t.setString("FIN DE PARTI : " + j1.get_nom() + " GAGNE " + to_string(y) + " a " + to_string(x));
   			  t.setCharacterSize(40);
    		       	  t.setFillColor(Color::Blue);
    	 		  t.setPosition(0,320);
    	 	          window.draw(t);
        		  window.display();
        		  sleep(seconds(5));
        		  window.close();
                         
                      }
                      else 
                      {
                        window.clear(Color::White);
                          Font font;
         		  font.loadFromFile("/usr/share/fonts/truetype/liberation2/LiberationSans-Regular.ttf");
         		  Text t;
   	 		  t.setFont(font);
   	 		  int x = j1.get_score() - G.calcule_val_pion();
   	 		  int y = j2.get_score();
   	 		  if(x > y)t.setString("FIN DE PARTI : " + j1.get_nom() + " GAGNE " + to_string(x) + " a " + to_string(y));
    	 		  else t.setString("FIN DE PARTI : " + j2.get_nom() + " GAGNE " + to_string(y) + " a " + to_string(x));
   			  t.setCharacterSize(40);
    		       	  t.setFillColor(Color::Black);
    	 		  t.setPosition(0,320);
    	 	          window.draw(t);
        		  window.display();
        		  sleep(seconds(5));
        		  window.close();
                      }
                   }
                  	
             }
             
        }

        // Effacer l'écran (remplir avec une couleur)
        window.clear(Color::White);

        // Dessiner les cases 
        for(int i =0;i<G.get_taille();i++)
	   {
	      for(int j =0;j<G.get_taille();j++)
	        {
	          // Créer un carré 
		    RectangleShape square(Vector2f(80, 80));
		    square.setFillColor(Color::White);
		    square.setPosition(i*80, j*80);
		    square.setOutlineThickness(3); // Épaisseur de la bordure
    		    square.setOutlineColor(Color::Black); // Couleur de la bordure
                    window.draw(square);
		}
	}
	
	//dessiner les pions
	for(int i =0;i<G.get_taille();i++)
	   {
	      for(int j =0;j<G.get_taille();j++)
	        {
	        	// Créer un cercle
                    Pion* p = G.get_gcase()[i][j];
                    if(p!=nullptr){
                    int x = p->get_position_x_y().first;
                    int y = p->get_position_x_y().second;
                    CircleShape shape;
		    shape.setRadius(30);
		    shape.setOrigin(x+40, y+40);
		    if(p->get_couleur() == "Red") shape.setFillColor(Color::Red);
		    else if(p->get_couleur() == "Yellow") shape.setFillColor(Color::Yellow);
		    else shape.setFillColor(Color::Black);
		    shape.setPosition(x*80 + 52, y*80 + 52); 
                    window.draw(shape);}
                 }
                 
             }
             
         // afficher le joueur ayant le tour
         Font font;
         font.loadFromFile("/usr/share/fonts/truetype/liberation2/LiberationSans-Regular.ttf");
         Text t;
   	 t.setFont(font);
    	 if(j1.a_le_tour)t.setString("Tour du joueur : " + j1.get_nom());
    	 else t.setString("Tour du joueur : " + j2.get_nom());
   	 t.setCharacterSize(20);
    	 t.setFillColor(Color::Black);
    	 t.setPosition(650, 0);
    	 window.draw(t);
        // Afficher ce qui a été dessiné
        
        window.display();
    }

    return 0;
}



