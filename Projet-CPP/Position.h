#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

class Position
{
private:
	int x;
	int y;
public:
	Position(void);
	Position(int x, int y);
	~Position(void);
	
	bool isCoordonneesValide(int x, int y);
	int getX(void);
	int getY(void);
	
	/**
		Modifie la valeur de X.
		Peut lever une exception.
	**/
	void setX(int x);

	/**
		Modifie la valeur de Y.
		Peut lever une exception.
	**/
	void setY(int Y);

	/**
		Modifie la valeur de X et de Y.
		Peut lever une exception.
	**/
	void setCoordonnees(int x, int y);

	/**
		Lève une exception indiquant que les coordonnées données sont incompatibles.
	**/
	void leverErreurMauvaiseCoordonnees(int x, int y);
	
	bool operator<(Position pos);
	bool operator==(Position pos);

};

