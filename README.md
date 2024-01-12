# projet-cpp
# Lien vers le drive : 
https://docs.google.com/document/d/1MK9sOTGi9vxHKE51hWPmlLH5aJM0NrYvMNoyhrDe85s/edit?usp=sharing
https://docs.google.com/document/d/1bAqaSc6aSq7F__r1JkGa0LCxN4gNoDbqQUj-zzZad7o/edit?usp=sharing
développement de trois  jeux : 
Jeux 1 Butin 
Jeux 2 Dames
Jeux 3 Safari
akefile:31: avertissement : surchargement de la recette pour la cible « JeuDame »
Makefile:28: avertissement : ancienne recette ignorée pour la cible « JeuDame »
g++ -Wall --std=c++11  -c JoueurButin.cpp
g++ -Wall --std=c++11  -c -lsfml-graphics -lsfml-window -lsfml-system JeuDame.cpp
g++ -Wall --std=c++11  -o JeuButin JeuButin.o PlateauButin.o PieceButin.o JoueurButin.o Plateau.o Piece.o -lsfml-graphics -lsfml-window -lsfml-system
