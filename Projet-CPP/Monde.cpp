#include "Monde.h"


Monde::Monde(void) : vector<Element>()
{
}


Monde::~Monde(void)
{
}

map& Monde::getCarte() {
	return carte;
}