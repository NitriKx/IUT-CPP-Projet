#include "Humain.h"

Humain::Humain(void) : Mobile() {
}

Humain::~Humain(void)
{
}

Humain::Humain(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision) : Mobile( nom, pos, _ptVie, _espVie, _forceCombat, _vitesse, _vision)
{
}

char Humain::getAffich() {
	return 'H';
}

COLORS Humain::getCouleur() {
	return RED;
}


