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
	map<Position, unsigned int> carte;
public:
	Monde(void);
	~Monde(void);

	map<Position, unsigned int>& getCarte();

	bool supprimerElement(Element*) ;
	void ajouterElement(Position pos, Element* e);
};