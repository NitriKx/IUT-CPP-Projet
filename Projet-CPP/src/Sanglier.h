#pragma once

// Utilisé pour désactiver un warning gênant
#pragma warning( disable : 4250 )

#include "Ressource.h"
#include "Mobile.h"

class Sanglier : public Ressource, public Mobile
{
public:

	unsigned int taille; //indice de taille du sanglier, 1, 2 ou 3

	Sanglier(void);

	Sanglier(string nom, Position pos);
	~Sanglier(void);

	// using Mobile::agir;

	void agir();

	//
	// CONSTANTES
	//

	char getAffich();
	COLORS getCouleur();

};