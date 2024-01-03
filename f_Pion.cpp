#include<iostream>
#include "Pion.hpp"
#include<utility>
#include<string>

using namespace std;


Pion::Pion(string c,pair<int,int> p, int v):couleur{c},position_x_y{p},valeur{v}{};

Pion::~Pion(){}

const string Pion::get_couleur() const{return couleur;}

pair<int,int> Pion::get_position_x_y() const{return position_x_y;}

const int Pion::get_valeur() const{return valeur;}

void Pion::deplacer_pion(int nx, int ny){position_x_y = {nx,ny};}
