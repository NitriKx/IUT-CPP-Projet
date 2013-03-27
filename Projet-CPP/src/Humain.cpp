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
	Monde* monde = Monde::getInstance();
	bool trouver = false;
	for(unsigned int i = 0; i < this->getVitesse() && !trouver; i++) {
	
		// On trouve la direction adapté pour se rendre à la cible la plus proche
		DIRECTIONS directionCible = this->calculerDirectionPourAllerPosition(positionCible);
		Position nouvellePos = this->calculerNouvelleCoordonnees(this->getPosition(), directionCible);
		
		// Si la position sur laquelle on est , n'est pas déjà la bonne
		if(nouvellePos != this->getPosition()) {

			// On vérifie si il y ades ressource à obtenir	
			// Si il ya un sanglier sur sa case et que l'homme cherche de la nourriture
			if(cible == NOURRITURE && monde->getTypeOccupant(nouvellePos) == SANGLIER) {
				// Si la position existe dans la map
				if(monde->getCarte().count(nouvellePos) > 0) {
					Element* aSupprimer = (*monde)[monde->getCarte()[nouvellePos]];
					Monde::getInstance()->supprimerElement(aSupprimer);
					Village::recevoirNourriture(Config::sanglier_nourriture_donnee);
					trouver = true; // on sort de la boucle vu qu'on a attein l'objectif
				}
			// On vérifie si il y ades ressource à obtenir	
			// Si il ya un abre sur sa case et que l'homme cherche de la bois
			}else if ( cible == BOIS && monde->getTypeOccupant(nouvellePos) == ARBRE){
				int indiceElement = monde->getCarte()[nouvellePos];
				Element* aSupprimer = (*monde)[indiceElement];
				Monde::getInstance()->supprimerElement(aSupprimer);
				Village::recevoirBois(Config::arbre_bois_donnee);
				trouver = true;
			}
			// On consomme des ressources
			Village::consomerBois;
			Village::consomerNourriture;
			// On bouge
			this->bouger(directionCible);

		}
	}
}

void Humain::bouger(DIRECTIONS direction) {
	Position nouvellePos = this->calculerNouvelleCoordonnees(this->getPosition(), direction);
	Monde::getInstance()->deplacerElement(this, nouvellePos);
}



Position Humain::chercherPlusPres(CIBLE cible) {

	DIRECTIONS ordreParcours[6] = {SUD_EST, SUD, SUD_OUEST, NORD_OUEST, NORD, NORD_EST};

	Position centre = this->getPosition();

	// On cherche dans les "cercle" du plus près au plus loin (jusqu'à la vision maximale).
	for(unsigned int i = 1; i < this->getVision()+1; i++) {

		Position curseur = centre;

		// Au fur et à mesure que l'on s'éloigne du point d'origine, un observe des "cercles" à 6 côtés
		// chaque côté étant de (vision-1)+2 cases.
		// REMARQUE - Cette technique est peu optimisé vu qu'on l'on teste certaines cases plusieurs fois

		// Case la plus au nord
		curseur = Position(centre.getX(), centre.getY()-(2*i));

		// On parcours les "directions". Toute les i+2 cases on change de direction
		for(unsigned int j = 0; j < 6; j++) {

			// On parcourt les cases du coté en cours (on fait pour la case "départ" mais pas pour la case "fin")
			for(unsigned int k = 1; k < 2+i-1; k++) {
				
				// Si l'humain doit trouver de la nourriture
				if(cible == NOURRITURE) {
					// Si il y a un sanglier
					if(Monde::getInstance()->getTypeOccupant(curseur) == SANGLIER) {
						return curseur;
					}
				// si l'humain doit trouver du bois
				}else if(cible == BOIS) {
					// si il y a un arbres dans la position testée
					if(Monde::getInstance()->getTypeOccupant(curseur) == ARBRE) {
						return curseur;
					}
				}

				// On calcule la position de la case suivante
				curseur = calculerNouvelleCoordonnees(curseur, ordreParcours[j]);

			}
		}
	}

	// Si l'on a trouvé personne dans le cercle on donne une position au hasard (qui n'est pas l'actuelle)
	Position alea;
	// Tant que la position n'est pas différente de l'actuelle ou qu'elle n'est pas valide
	do {
		alea = Position::random(Config::dimentions.first-1, Config::dimentions.second-1);
	} while ((alea.getX() == this->getPosition().getX() && alea.getY() == this->getPosition().getY())
		|| Monde::getInstance()->isCaseLibre(alea) == false);
	
	return alea;
}




DIRECTIONS Humain::calculerDirectionPourAllerPosition(Position pos) {
	Position current = this->getPosition();

	int xdiff = pos.getX() - current.getX();
	int ydiff = pos.getY() - current.getY();

	// Déjà sur la bonne case ?
	if(xdiff == 0 && ydiff == 0) {
		return IMMOBILE;
	}

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

	throw new string("Impossible de déterminer un chemin ?!");
}

char Humain::getAffich() {
	return 'H';
}

COLORS Humain::getCouleur() {
	return RED;
}