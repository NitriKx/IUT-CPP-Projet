#include "Sanglier.h"

Sanglier::Sanglier(void): 
	Ressource(), taille()
{


}

Sanglier::Sanglier(string nom, Position pos):Ressource(nom,pos){
}


Sanglier::~Sanglier(void)
{
}

// ***************************
//
//		CONSTANTES
//
// ***************************

char Sanglier::getAffich() {
	return 'S';
}
COLORS Sanglier::getCouleur() {	
	return YELLOW;
}