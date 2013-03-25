#include "Monde.h"
#include "Config.h"
#include "Mobile.h"
#include "Arbre.h"
#include "Sanglier.h"
#include "Gaulois.h"
#include "Gauloise.h"

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

// Ajout l'élément au monde
// Doit être placé plus tard
void Monde::ajouterElement(Position pos, Element* e) {
	this->push_back(e);
	int id = getIndexDansListe(e);
	this->carte[pos] = id;
	e->setPosition(pos);
}

void Monde::deplacerElement(Element *e, Position nouvellePos) {
	int id = this->getIndexDansListe(e);

	if(id < 0)
		throw new string("L'element placé n'existe pas dans le monde.");

	this->getCarte().erase(e->getPosition());
	e->setPosition(nouvellePos);
	this->carte[nouvellePos] = id;
}

int Monde::getIndexDansListe(Element *e) {
	// On récupère la position de l'élément
	int id = -1;
	for(unsigned int i = 0 ; i < this->size() ; i++) {
		if(this->at(i) == e) {
			id=i;
			break;
		}
	}
	return id;
}

bool Monde::isCaseLibre(Position pos) {
		
	// On vérifie que les coordonnées sont valides
	if(pos.getX() < 0 || pos.getY() < 0 || pos.getX() > (Config::dimentions.first-1) || pos.getY() > (Config::dimentions.second-1) )
		return false;

	// Si la case est occupée
	if(this->carte.count(pos) > 0) {
		return false;
	}

	OutputDebugString(L"Case libre ! \n");
	return true;
}

void Monde::jourSuivant()
{
	for(unsigned int i = 0; i < this->size(); i++)
	{
		try {
		
			if(typeid(*this->at(i)) == typeid(Gaulois))
				dynamic_cast<Gaulois *>(this->at(i))-> Gaulois::agir();
			if(typeid(*this->at(i)) == typeid(Gauloise))
				dynamic_cast<Gauloise *>(this->at(i))-> Gauloise::agir();
			if(typeid(*this->at(i)) == typeid(Sanglier)) {
				Sanglier *sanglier = dynamic_cast<Sanglier *>(this->at(i));
				sanglier->agir();
			}
		
		} catch(const std::logic_error & e) {
			OutputDebugStringA(e.what());
		}
	}
}

// STATIQUE
Monde* Monde::getInstance() {
	if(_instance == NULL) {
		_instance = new Monde();
	}
	return _instance;
}


void Monde::initialiserMonde() {

	std::srand((unsigned int) time(0));

	// On ajoute les arbres
	for(int i = 0; i < Config::nb_arbres; i++) {
		Position pos = Position::random(Config::dimentions.first, Config::dimentions.second);
		this->ajouterElement(pos, new Arbre("A", pos));
	}

	// On ajoute les sangliers
	for(int i = 0; i < Config::nb_sanglier; i++) {
		Position pos = Position::random(Config::dimentions.first, Config::dimentions.second);
		Element *elem = dynamic_cast<Element *>(new Sanglier("S", pos));
		this->ajouterElement(pos, elem);
	}

	// On ajoute des gauloise
	for(int i = 0; i < Config::nb_gauloise; i++) {
		Position pos = Position::random(Config::dimentions.first, Config::dimentions.second);
		this->ajouterElement(pos, new Gauloise("", pos, 20, 5, 3, 2, 3));
	}

	// On ajoute des gaulois
	for(int i = 0; i < Config::nb_gaulois; i++) {
		Position pos = Position::random(Config::dimentions.first, Config::dimentions.second);
		this->ajouterElement(pos, new Gaulois("", pos, 20, 5, 3, 2, 3));
	}
}