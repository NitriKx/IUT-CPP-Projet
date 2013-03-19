#include "Monde.h"
#include "Mobile.h"


Monde::Monde(void) : vector<Element*>()
{
}


Monde::~Monde(void)
{
}

map<Position, unsigned int>& Monde::getCarte() {
	return carte;
}

bool Monde::supprimerElement(Element* e) {
	return this->carte.erase(e->getPosition()) > 0;
}

void Monde::ajouterElement(Position pos, Element* e) {
	this->push_back(e);

	// On récupère la position de l'élément
	int id = -1;
	for(unsigned int i = 0 ; i < this->size() ; i++) {
		if(this->at(i) == e) {
			id=i;
			break;
		}
	}

	if(id < 0)
		throw new string("L'element placé n'existe pas dans le monde.");

	this->carte[pos] = id;
	e->setPosition(pos);
}

void Monde::jourSuivant()
{
	for(unsigned int i =0;i<this->size();i++)
	{
		if(typeid(*this->at(i)) == typeid(Mobile))
			this->at(i)->agir();
	}
}