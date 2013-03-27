#pragma once

#include <vector>
#include <map>
#include "Element.h"
#include "Position.h"

using namespace std;

enum OCCUPANT {
	ARBRE,
	SANGLIER,
	GAULOIS,
	GAULOISE,
	VIDE
};

class Monde :
	public vector<Element*>
{

private:
	//
	// CONSTANTES
	//
	map<Position, unsigned int> carte;

	static Monde *_instance;

	Monde(void);
	~Monde(void);

public:
	map<Position, unsigned int>& getCarte();

	bool supprimerElement(Element*) ;

	void ajouterElement(Position pos, Element* e);
	void ajouterElementPositionAleatoireEtVide(Element *e);

	void deplacerElement(Element *e, Position nouvellePos);

	int getIndexDansListe(Element *e);

	bool isCaseLibre(Position pos);
	OCCUPANT getTypeOccupant(Position pos);

	void jourSuivant();
	void initialiserMonde();

	static Monde* getInstance();

};