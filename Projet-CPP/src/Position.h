#pragma once

#include <iostream>
#include <stdexcept>

#include <time.h>

using namespace std;

class Position
{
private:
	int x;
	int y;
public:
	Position(void);
	Position(int x, int y);
	Position(const Position &pos);
	~Position(void);
	
	static bool isCoordonneesValide(int x, int y);
	
	// Génère une Position aléatoire en respectant les dimention de grille passées
	// en paramètre. Les coordonnées seront entre 0 et maxLargeur-1 (respectivement 0 et maxHauteur).
	static Position random(unsigned int maxLargeur, unsigned int maxHauteur);
	
	int getX(void);
	int getY(void);
	void setX(int x);
	void setY(int Y);
	void setCoordonnees(int x, int y);

	void leverErreurMauvaiseCoordonnees(int x, int y);	

	bool operator<(const Position &pos) const;
	bool operator==(Position pos);
	Position& operator=(const Position &pos);
};