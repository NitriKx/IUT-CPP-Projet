#pragma once

#include <iostream>

class Config
{
public:

	/* First = Largeur / Hauteur = Y */
	static std::pair<int, int> dimentions;
	
	// Ressources de départ
	static const int nourriture = 20;
	static const int bois = 20;

	// Elements de départ
	static const int nb_arbres = 10;
	static const int nb_sanglier = 6;
	static const int nb_gaulois = 4;
	static const int nb_gauloise = 4;
	
};

