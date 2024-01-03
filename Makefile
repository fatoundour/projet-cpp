CPP = g++ -Wall --std=c++11 


all : Jeu

Jeu : Jeu.o Grille.o Pion.o Joueur.o
	$(CPP) -o Jeu Jeu.o Grille.o Pion.o Joueur.o -lsfml-graphics -lsfml-window -lsfml-system
	
Jeu.o : f_Jeu.cpp f_Grille.hpp f_Pion.hpp f_Joueur.hpp
	$(CPP) -c -lsfml-graphics -lsfml-window -lsfml-system f_Jeu.cpp
	
Grille.o : f_Grille.cpp f_Pion.hpp 
	$(CPP) -c f_Grille.cpp

Pion.o : f_Pion.cpp 
	$(CPP) -c Pion.cpp
Joueur.o : f_Joueur.cpp f_Grille.hpp f_Pion.hpp
	$(CPP) -c f_Joueur.cpp
	
clean : 
	rm -f *.o test
