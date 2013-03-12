#pragma once

#include <vector>
#include <unordered_map>
#include "Element.h"
#include "Position.h"

typedef std::tr1::unordered_map<Position, Element*> map;

class Monde :
	public vector<Element*>
{
private:
	map carte;
public:
	Monde(void);
	~Monde(void);

	map& getCarte();

	bool supprimerElement(Element*) ;
	void ajouterElement(Position pos, Element* e);
};

