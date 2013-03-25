#pragma once

#include "Humain.h"

class Gauloise :
	public Humain
{

public:
	
	//
	// CONSTANTES
	//

	char getAffich();
	COLORS getCouleur();

	//
	// CONSTRCUTEURS
	//

	Gauloise(void);
	~Gauloise(void);
	Gauloise(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);
	

};

