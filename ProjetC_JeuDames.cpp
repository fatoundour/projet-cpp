// ProjetC_JeuDames.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <utility>
#include <vector>
#include "Piece.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int i, j, ni, nj;//variable globale qui permet de recuperer la position de l'ancien et le nouveau pion cliqué

int main() {
    Plateau P(10, 10);
    Joueur J1("Joueur 1"), J2("Joueur 2");
    RenderWindow window(VideoMode(800, 800), "Jeu de Dames");

    int tailleCase = 80;
    RectangleShape caseRect(Vector2f(tailleCase, tailleCase));

    sf::Color customLightColor(236, 183, 131, 255); // Couleur claire
    sf::Color customDarkColor(92, 39, 14, 255);     // Couleur foncée

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::MouseButtonPressed)
            {           
                i = ni;
                j = nj;
                ni = event.mouseButton.x / 80;
                nj = event.mouseButton.y / 80;
                J1.jouerTour(i, j, ni, nj, P);

            }
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(customLightColor);

        // Dessin du plateau
        for (int i = 0; i < P.getLignes(); i++) {
            for (int j = 0; j < P.getColonnes(); j++) {
                caseRect.setPosition(j * tailleCase, i * tailleCase);
                caseRect.setFillColor((i + j) % 2 == 0 ? customDarkColor : customLightColor);
                window.draw(caseRect);

                // Ajout de la logique pour les pièces
                if (P.getPlateau()[i][j] != nullptr) {
                    sf::CircleShape piece(tailleCase / 2 - 5); // Un peu plus petit que la case
                    piece.setPosition(j * tailleCase + 5, i * tailleCase + 5); // Centré dans la case

                    if (P.getPlateau()[i][j]->mat() == "B ")
                        piece.setFillColor(sf::Color::White);
                    else if (P.getPlateau()[i][j]->mat() == "N ")
                        piece.setFillColor(sf::Color::Black);

                    window.draw(piece);
                }
            }
        }

        window.display();
    }

    return 0;
}

