#pragma once

#include "Position.h"
#include "Color.h"

#include <iostream>
#include <string>

class Monde;

class Element
{
private:

	//
	// ATTRIBUTS
	//

	Position pos; // Variable position de l'element
	string nom;   // Nom de l'element
	
public:

	//
	// CONSTANTES
	//

	static const char affich = 'E'; // caractère d'affichage
	static const Color couleur; // Couleur blanche

	//
	// CONSTRUCTEURS
	//

	Element(void);
	Element(string nom, Position pos);
	~Element(void);

	//
	// GETTERS ET SETTERS
	//

	Position getPosition(void) const;
	string getNom(void) const;
	void setNom(string nom);
	void setPosition(Position pos);
	void setPostion(int x, int y);
	
};

#include "Monde.h"
