#include "Arbre.h"

Arbre::Arbre(void)
{
}


Arbre::~Arbre(void)
{
}

Arbre::Arbre(string nom, Position pos):Ressource(nom,pos){
}

// ***************************
//
//		CONSTANTES
//
// ***************************

char Arbre::getAffich() {
	return 'A';
}
COLORS Arbre::getCouleur() {	
	return BROWN;
}