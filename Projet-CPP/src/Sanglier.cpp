#include "Sanglier.h"
#include "Config.h"

Sanglier::Sanglier(void): 
	Ressource(), taille(), 
	Mobile("", Position(0,0),
		Config::sanglier_point_vie,
		Config::sanglier_esperance_vie,
		Config::sanglier_force_combat,
		Config::sanglier_vitesse,
		Config::sanglier_vision)
{


}

Sanglier::Sanglier(string nom, Position pos):Ressource(nom,pos), 
	Mobile(nom, pos,
		Config::sanglier_point_vie,
		Config::sanglier_esperance_vie,
		Config::sanglier_force_combat,
		Config::sanglier_vitesse,
		Config::sanglier_vision){
}


Sanglier::~Sanglier(void)
{
}

void Sanglier::agir() 
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