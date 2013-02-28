#include "Element.h"


Element::Element(void) : nom(""), pos(0,0)
{
}

Element::Element(string nom, Position pos) : nom(nom), pos(pos)
{
}


Element::~Element(void)
{
}


Position Element::getPosition(void) const
{
	return this->pos;
}


string Element::getNom(void) const
{
	return this->nom;
}


void Element::setNom(string nom)
{
	this->nom = nom;
}


void Element::setPosition(Position pos)
{
	this->pos = pos;
}


void Element::setPostion(int x, int y)
{
	Position pos(x,y);
	this->pos = pos;
}

void Element::setElement(char _element)
{
	this->element=_element;
}

void Element::setPtVie(unsigned int _ptVie)
{
	this->ptVie=_ptVie;
}

void Element::setEspVie(unsigned int _espVie)
{
	this->espVie=_espVie;
}
void Element::setForceCombat(unsigned int _forceCombat)
{
	this->forceCombat=_forceCombat;
}
void Element::setVitesseDep(unsigned int _vitesseDep)
{
	this->vitesseDep=_vitesseDep;
}
void Element::setVision(unsigned int _vision)
{
	this->vision=_vision;
}
void Element::setColor(Color _color)
{
	this->couleur=_color;
}

char Element::getElement(void) const
{
	return  this->element;
}
unsigned int Element::getPtVie(void)
{
	return this->ptVie;
}
unsigned int Element::getEspVie(void) const
{
	return this->espVie;
}
unsigned int Element::getForceCombat(void) const
{
	return this->forceCombat;
}
unsigned int Element::getVitesseDep(void) const
{
	return this->vitesseDep;
}
unsigned int Element::getVision(void) const
{
	return this->vision;
}
Color Element::getColor(void) const
{
	return this->couleur;
}