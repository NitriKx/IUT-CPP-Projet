#include "Gaulois.h"


Gaulois::Gaulois(void)
{
}

Gaulois::Gaulois(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision) : Humain( nom, pos, _ptVie, _espVie, _forceCombat, _vitesse, _vision)
{
}


Gaulois::~Gaulois(void)
{
}

char Gaulois::getAffich() {
	return 'G';
}
COLORS Gaulois::getCouleur() {	
	return BLUE;
}

void Gaulois::bouge(void)
{

}
