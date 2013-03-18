#include "Mobile.h"

// ***************************
//
//		CONSTRUCTEURS
//
// ***************************

Mobile::Mobile(void)
{
}

Mobile::Mobile(unsigned int _vitesse, unsigned int _vision) : Element(),vitesse(_vitesse), vision(_vision)
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
void Mobile::setVision(unsigned int _vision) { this->vision=_vision; }




