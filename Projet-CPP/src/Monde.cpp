#include "Monde.h"
#include "Config.h"
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

	// On recherche l'index de l'élément
	int indexElement = -1;
	for(unsigned int i = 0; i < this->size(); i++) {
		if((*this)[i] == e) {
			indexElement = i;
			break;
		}
	}

	if(indexElement < 0) {
		return false;
	}

	this->erase(this->begin() + indexElement);
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

bool Monde::isCaseLibre(Position pos) {
	
	bool result = false;
	
	// On vérifie que les coordonnées sont valides
	if(pos.getX() < 0 || pos.getY() < 0 || pos.getX() > Config::getTailleGrille().first-1 || pos.getY() > Config::getTailleGrille().second-1) 
		return false;

	// On vérifie qu'aucun éléments n'existe à cet emplacement
	try {
		this->carte.at(pos);
	} catch (const out_of_range& oor) {
		return true;
	}
	
	return false;
}

void Monde::jourSuivant()
{
	for(unsigned int i =0;i<this->size();i++)
	{
		if(typeid(*this->at(i)) == typeid(Mobile))
			this->at(i)->agir();
	}
}

// STATIQUE
Monde* Monde::getInstance() {
	if(_instance == NULL) {
		_instance = new Monde();
	}
	return _instance;
}
