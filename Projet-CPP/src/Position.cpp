#include "Position.h"
#include "Config.h"

Position::Position(void) : x(0), y(0)
{
}

Position::Position(int x, int y)
{
	if(isCoordonneesValide(x,y)) {
		this->x = x;
		this->y = y;
	} else {
		leverErreurMauvaiseCoordonnees(x,y);
	}
}

Position::Position(const Position &pos) {
	this->setCoordonnees(pos.x, pos.y);
}

Position::~Position(void)
{
	
}


bool Position::isCoordonneesValide(int x, int y)
{
	return abs(x)%2 == abs(y)%2;
}

Position Position::random(unsigned int maxLargeur, unsigned int maxHauteur)
{
		Position *pos = new Position();
		
		// On tire un nombre x au hasard (en respectant les bornes)
		int x = rand() % maxLargeur;
		int y = -1;

		// On essaie des y jusqu'à ce qu'un soit valide
		do {
			y = rand() % maxHauteur;
		} while(!Position::isCoordonneesValide(x, y));

		// On inscrit les résultats
		pos->setCoordonnees(x,y);

		return *pos;
}




int Position::getX(void)
{
	return this->x;
}


void Position::setX(int x)
{
	if(this->isCoordonneesValide(x,this->getY())) {
		this->x = x;
	} else {
		leverErreurMauvaiseCoordonnees(x, this->getY());
	}
}


int Position::getY(void)
{
	return this->y;
}


void Position::setY(int Y)
{
	if(this->isCoordonneesValide(y,this->getX())) {
		this->y = y;
	} else {
		leverErreurMauvaiseCoordonnees(this->getX(), y);
	}
}


void Position::setCoordonnees(int x, int y)
{
	if(this->isCoordonneesValide(x,y)) {
		this->x = x;
		this->y = y;
	} else {
		leverErreurMauvaiseCoordonnees(x, y);
	}
}



void Position::leverErreurMauvaiseCoordonnees(int x, int y)
{
	string msg ="Erreur : Les coordonnees ne serait plus correctes x=[" + x;
	msg += "] y=[" + y ;
	msg += "]";

	throw logic_error(msg);
}

bool Position::operator<(const Position &pos) const
{
	return this->x < pos.x || (this->x == pos.x && this->y < pos.y);
}

Position& Position::operator=(const Position &pos) {
	this->x = pos.x;
	this->y = pos.y;
	return *this;
}

bool Position::operator==(Position pos) {
	return this->x == pos.x && this->y == pos.y;
}
