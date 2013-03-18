#pragma once

#include <iostream>
#include <string>
#include "Position.h"

class Monde;

class Element
{
private:
	Position pos; // Variable position de l'element
	string nom; // Nom de l'element
	
public:
	Element(void);
	Element(string nom, Position pos);
	~Element(void);
	
	static const char affich = 'E'; // caractère d'affichage

	// Setteurs
	void setNom(string nom);
	void setPosition(Position pos);
	void setPostion(int x, int y);
		
	// Getteurs
	Position getPosition(void) const;
	string getNom(void) const;

};

#include "Monde.h"
