#pragma once

#include "Mobile.h"
#include "econio.h"

enum CIBLE {
	NOURRITURE = 0,
	BOIS = 1,
	REPRODUCTION = 2
};

class Humain :
	public Mobile
{

private:

public:
	Humain(void);
	~Humain(void);
	Humain(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);

	char getAffich();
	COLORS getCouleur();

	void agir();
	void bouger(DIRECTIONS direction);
	Position chercherPlusPres(CIBLE cible);
	DIRECTIONS Humain::calculerDirectionPourAllerPosition(Position pos);

};
