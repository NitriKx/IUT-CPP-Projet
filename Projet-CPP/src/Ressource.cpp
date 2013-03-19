#include "Ressource.h"

// ***************************
//
//		CONSTANTES 
//
// ***************************

char Ressource::getAffich() {
	return 'M';
}
COLORS Ressource::getCouleur() {	
	return GREEN;
}


Ressource::Ressource(void)
{
}

Ressource::Ressource(string nom, Position pos) : Element(nom,pos) {}

Ressource::~Ressource(void)
{
}