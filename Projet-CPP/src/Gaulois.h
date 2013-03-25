#pragma once
#include "Humain.h"
class Gaulois :
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

	Gaulois(void);
	~Gaulois(void);
	Gaulois(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);
	


};

