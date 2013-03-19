#pragma once
#include "Ressource.h"
class Sanglier : public Ressource
{
public:

	unsigned int taille; //indice de taille du sanglier, 1, 2 ou 3

	Sanglier(void);

	Sanglier(string nom, Position pos);
	~Sanglier(void);

	//
	// CONSTANTES
	//

	char getAffich();
	COLORS getCouleur();

};