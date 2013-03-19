#include "Gauloise.h"


Gauloise::Gauloise(void)
{
}

Gauloise::Gauloise(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision) : Humain( nom, pos, _ptVie, _espVie, _forceCombat, _vitesse, _vision)
{
}


Gauloise::~Gauloise(void)
{
}

char Gauloise::getAffich() {
	return 'G';
}
COLORS Gauloise::getCouleur() {	
	return LIGHTMAGENTA;
}

