#pragma once

#include <vector>
#include <map>
#include "Element.h"
#include "Position.h"

using namespace std;

class Monde :
	public vector<Element*>
{
private:
	//
	// CONSTANTES
	//
	map<Position, unsigned int> carte;
public:
	

	//
	// CONSTRCUTEURS
	//
	Monde(void);
	~Monde(void);
	//
	// METHODES
	//
	bool supprimerElement(Element*) ;
	void ajouterElement(Position pos, Element* e);
	void jourSuivant();
	//
	// GETTERS ET SETTERS
	//
	map<Position, unsigned int>& getCarte();

	
};