#pragma once

#include <iostream>
#include <string>
#include "Position.h"

class Element
{
private:
	Position pos;
	string nom;
public:
	Element(void);
	Element::Element(string nom, Position pos);
	~Element(void);
	

	Position getPosition(void);
	string getNom(void);
	void setNom(string nom);
	void setPosition(Position pos);
	void setPostion(int x, int y);
	Element(string nom, Position pos);
};

