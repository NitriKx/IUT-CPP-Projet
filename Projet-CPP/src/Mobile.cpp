#include "Mobile.h"

// ***************************
//
//		CONSTANTES
//
// ***************************

char Mobile::getAffich() {
	return 'M';
}
COLORS Mobile::getCouleur() {	
	return GREEN;
}

// ***************************
//
//		CONSTRUCTEURS
//
// ***************************

Mobile::Mobile(void) 
	: Element(),ptVie(100), espVie(5), forceCombat(1), vitesse(1), vision(1)
{
}

Mobile::Mobile(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision) 
	: Element(nom, pos),ptVie(_ptVie), espVie(_espVie), forceCombat(_forceCombat), vitesse(_vitesse), vision(_vision)
{
}


Mobile::~Mobile(void)
{
}


// ***************************
//
//		   PUBLIC
//
// ***************************


void Mobile::bouge(void)
{



}


// ***************************
//
//		GETTERS ET SETTERS
//
// ***************************

unsigned int Mobile::getVitesse(void) const { return this->vitesse; }
unsigned int Mobile::getPtVie(void) { return this->ptVie; }
unsigned int Mobile::getEspVie(void) const { return this->espVie; }
unsigned int Mobile::getForceCombat(void) const { return this->forceCombat; }
unsigned int Mobile::getVision(void) const { return this->vision; }

void Mobile::setVision(unsigned int _vision) { this->vision = _vision; }
void Mobile::setVitesse(unsigned int _vitesse) { this->vitesse = _vitesse; }
void Mobile::setPtVie(unsigned int _ptVie) { this->ptVie=_ptVie; }
void Mobile::setEspVie(unsigned int _espVie) { this->espVie=_espVie; }
void Mobile::setForceCombat(unsigned int _forceCombat) { this->forceCombat=_forceCombat; }


