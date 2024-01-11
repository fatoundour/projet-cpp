#include<iostream>
#include "f_Pion.hpp"
#include<utility>
#include<string>

using namespace std;


Pion::Pion(string c,pair<int,int> p, int v):m_couleur{c},m_position{p},m_valeur{v}{};

Pion::~Pion(){}

const string Pion::get_m_couleur() const{return m_couleur;}

pair<int,int> Pion::get_m_position() const{return m_position;}

const int Pion::get_m_valeur() const{return m_valeur;}

void Pion::deplacer_pion(int nx, int ny){m_position = {nx,ny};}
