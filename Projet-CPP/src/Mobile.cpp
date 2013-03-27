#include <time.h>

#include "Mobile.h"
#include "Config.h"
#include <sstream>

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

void Mobile::agir(void)
{
	this->Mobile::bouge();
}

void Mobile::bouge(void)
{
	string debugMessage("L'élément ");
	debugMessage.append(this->getNom());
	debugMessage.append(" est en train de bouger.");
	OutputDebugString(L"Bouge\n");

	Monde* monde = Monde::getInstance();
	bool coordTrouve = false;
	DIRECTIONS dir = NORD;
	Position nouvellePos(this->getPosition());
	int i = 0;

	// On tire une direction au hasard entre 0 et 5
	int rand = std::rand() % 6;

	// Tant que on a pas trouvé de coordonnées valide et que l'on ne les 
	// a pas toutes testés
	while(!coordTrouve && i < 6) {

		nouvellePos = calculerNouvelleCoordonnees(this->getPosition(), (DIRECTIONS) rand);

		// Si la case est libre (et qu'elle existe)
		if(Monde::getInstance()->isCaseLibre(nouvellePos)) {
			coordTrouve = true;
		}

		if(rand == 5) {
			rand = 0;
		} else {
			rand++;
		}

		i++;
	}

	// Si l'élément n'a pas été bloqué on le déplace
	if(coordTrouve) {
		// On change la position de l'élément
		monde->deplacerElement(this, nouvellePos);	
	} else {
		OutputDebugString(L"Element bloqué !\n");
	}

	
}

Position Mobile::calculerNouvelleCoordonnees(Position posDepart, DIRECTIONS direction) const
{
	Position pos;

	switch(direction) {
	
	case NORD:
		pos.setCoordonnees(posDepart.getX(), posDepart.getY()-2);
		break;

	case SUD:
		pos.setCoordonnees(posDepart.getX(), posDepart.getY()+2);
		break;
	
	case NORD_EST:
		pos.setCoordonnees(posDepart.getX()+1, posDepart.getY()-1);
		break;
	
	case SUD_EST:
		pos.setCoordonnees(posDepart.getX()+1, posDepart.getY()+1);
		break;
	
	case NORD_OUEST:
		pos.setCoordonnees(posDepart.getX()-1, posDepart.getY()-1);
		break;
	
	case SUD_OUEST:
		pos.setCoordonnees(posDepart.getX()-1, posDepart.getY()+1);
		break;
	default:
		OutputDebugString(L"Direction inconnue !");
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


