#include "Mobile.h"
#include "Config.h"

// ***************************
//
//		CONSTANTES
//
// ***************************

Monde* Monde::_instance = NULL;

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
	Monde* monde = Monde::getInstance();
	bool coordTrouve = false;
	DIRECTIONS dir = NORD;
	Position nouvellePos;

	// Tant que on a pas trouvé de coordonnées valide
	while(!coordTrouve) {

		// On tire une direction au hasard entre 0 et 5
		int rand =std::rand() % 6;

		nouvellePos = calculerNouvelleCoordonnees((DIRECTIONS) rand);

		// Si la case est libre
		if(Monde::getInstance()->isCaseLibre(nouvellePos)) {
			coordTrouve = true;
		}
	}

	// On change la position de l'élément
	monde->supprimerElement(this);
	monde->ajouterElement(nouvellePos, this);

}

Position Mobile::calculerNouvelleCoordonnees(DIRECTIONS direction) const
{
	Position pos = this->getPosition();

	switch(direction) {
	
	case NORD:
		pos.setX(pos.getY()+2);
		break;

	case SUD:
		pos.setX(pos.getY()-2);
		break;
	
	case NORD_EST:
		pos.setX(pos.getX()+1);
		pos.setY(pos.getY()+1);
		break;
	
	case SUD_EST:
		pos.setX(pos.getX()+1);
		pos.setY(pos.getY()-1);
		break;
	
	case NORD_OUEST:
		pos.setX(pos.getX()-1);
		pos.setY(pos.getY()+1);
		break;
	
	case SUD_OUEST:
		pos.setX(pos.getX()-1);
		pos.setY(pos.getY()-1);
		break;
	}

	return pos;
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


