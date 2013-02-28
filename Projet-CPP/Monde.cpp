#include "Monde.h"


Monde::Monde(void) : vector<Element>()
{
}


Monde::~Monde(void)
{
}

map& Monde::getCarte() {
	return carte;
}

bool Monde::supprimerElement(Element* e) {
	return this->carte.erase(e->getPosition()) > 0;
}

void Monde::ajouterElement(Position pos, Element* e) {
	this->carte[pos] = e;
}