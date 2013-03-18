#include "Element.h"

// ***************************
//
//		CONSTANTES
//
// ***************************

const Color Element::couleur = Color(255, 255, 255);

// ***************************
//
//		CONSTRUCTEURS
//
// ***************************

Element::Element(void) : nom(""), pos(0,0)
{
}

Element::Element(string nom, Position pos) : nom(nom), pos(pos)
{
}

Element::~Element(void)
{
}


// ***************************
//
//		GETTERS ET SETTERS
//
// ***************************

Position Element::getPosition(void) const { return this->pos; }
string Element::getNom(void) const { return this->nom; }
void Element::setNom(string nom) { this->nom = nom; }
void Element::setPosition(Position pos) { this->pos = pos; }
void Element::setPostion(int x, int y) { this->pos = Position(x,y); }


