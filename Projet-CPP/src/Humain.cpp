#include "Mobile.h"
#include "Humain.h"
#include "Config.h"
#include "Village.h"

Humain::Humain(void) : Mobile() {
}

Humain::~Humain(void)
{
}

Humain::Humain(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision) : Mobile( nom, pos, _ptVie, _espVie, _forceCombat, _vitesse, _vision)
{
}

void Humain::agir() {

	CIBLE cible = NOURRITURE;

	// Si le stock de nourriture est en dessous du seuil 
	if(Village::nourriture < Config::alerte_nourriture) {
		cible = NOURRITURE;
	} 
	else if (Village::bois < Config::alerte_bois) {
		cible = BOIS;
	} 
	else {
		cible = REPRODUCTION;
	}

	// On recherche la cible la plus proche
	Position positionCible = this->chercherPlusPres(cible);
	// On trouve la direction adapt� pour se rendre � la cible la plus proche
	DIRECTIONS directionCible = this->calculerDirectionPourAllerPosition(positionCible);
	this->bouger(directionCible);
}

void Humain::bouger(DIRECTIONS direction) {
	Monde::getInstance()->deplacerElement(this, this->calculerNouvelleCoordonnees(this->getPosition(), direction));
}



Position Humain::chercherPlusPres(CIBLE cible) {

	DIRECTIONS ordreParcours[6] = {SUD_EST, SUD, SUD_OUEST, NORD_OUEST, NORD, NORD_EST};

	// On r�cup�re les milliseconde, secondes et minutes actuelles pour avoir un nombre vraiment al�atoire
	SYSTEMTIME st;
	GetSystemTime(&st);
	std::srand(st.wMinute * 1000 * 60 + st.wSecond*1000 + st.wMilliseconds);

	Position centre = this->getPosition();

	// On cherche dans les "cercle" du plus pr�s au plus loin (jusqu'� la vision maximale).
	for(unsigned int i = 0; i < this->getVision(); i++) {

		Position curseur = centre;

		// Au fur et � mesure que l'on s'�loigne du point d'origine, un observe des "cercles" � 6 c�t�s
		// chaque c�t� �tant de i+2 cases.
		// REMARQUE - Cette technique est peu optimis� vu qu'on l'on teste certaines cases plusieurs fois

		// Case la plus au nord
		curseur = Position(centre.getX(), centre.getY()+(2*i));

		// On parcours les "directions". Toute les i+2 cases on change de direction
		for(unsigned int j = 0; j < 6; j++) {

			// On parcourt les cases du cot� en cours (on fait pour la case "d�part" mais pas pour la case "fin")
			for(unsigned int k = 1; k < 2+i; k++) {
				
				// Si l'humain doit trouver de la nourriture
				if(cible == NOURRITURE) {
					// Si il y a un sanglier
					if(Monde::getInstance()->getTypeOccupant(curseur) == SANGLIER) {
						return curseur;
					}
				}

				// On calcule la position de la case suivante
				curseur = calculerNouvelleCoordonnees(curseur, ordreParcours[j]);

			}
		}
	}

	// Si l'on a trouv� personne dans le cercle on donne une position au hasard (qui n'est pas l'actuelle)
	Position alea;
	// Tant que la position n'est pas diff�rente de l'actuelle ou qu'elle n'est pas valide
	do {
		alea = Position::random(Config::dimentions.first-1, Config::dimentions.second-1);
	} while ((alea.getX() == this->getPosition().getX() && alea.getY() == this->getPosition().getY())
		|| Monde::getInstance()->isCaseLibre(alea) == false);
	
	return alea;
}




DIRECTIONS Humain::calculerDirectionPourAllerPosition(Position pos) {
	Position current = this->getPosition();

	// Case courante
	if(current.getX() == pos.getX() && current.getY() == pos.getY()) {
		throw new string("Le mobile est d�j� sur la case !");
	}

	int xdiff = pos.getX() - current.getX();
	int ydiff = pos.getY() - current.getY();

	// SUD
	if(ydiff > 0 && xdiff == 0) {
		return SUD;
	}

	// NORD 
	if(ydiff < 0 && xdiff == 0) {
		return NORD;
	}

	// SUD_EST
	if(ydiff > 0 && xdiff > 0) {
		return SUD_EST;
	}

	// NORD_EST
	if(ydiff < 0 && xdiff > 0) {
		return NORD_EST;
	}

	// SUD_OUEST
	if(ydiff > 0 && xdiff < 0) {
		return SUD_OUEST;
	}

	// NORD_OUEST
	if(ydiff < 0 && xdiff < 0) {
		return NORD_OUEST;
	}


	// GAUCHE
	if(ydiff == 0 && xdiff < 0) {
		
		// Si l'on peut passer par "en haut"
		if(Monde::getInstance()->isCaseLibre(calculerNouvelleCoordonnees(pos, NORD_OUEST))) {
			return NORD_OUEST;
		}
		// Sinon on passe par le bas
		return SUD_OUEST;
	}

	// DROITE
	if(ydiff == 0 && xdiff > 0) {
		// Si l'on peut passer par "en haut"
		if(Monde::getInstance()->isCaseLibre(calculerNouvelleCoordonnees(pos, NORD_EST))) {
			return NORD_EST;
		}
		// Sinon on passe par le bas
		return SUD_EST;
	}

	throw new string("Impossible de d�terminer un chemin ?!");
}

char Humain::getAffich() {
	return 'H';
}

COLORS Humain::getCouleur() {
	return RED;
}