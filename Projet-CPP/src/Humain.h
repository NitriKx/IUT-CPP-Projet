#pragma once

#include "Mobile.h"
#include "econio.h"

class Humain :
	public Mobile
{

private :
	int vie; 
public:
	Humain(void);
	~Humain(void);
	Humain(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);

	char getAffich();
	COLORS getCouleur();

};