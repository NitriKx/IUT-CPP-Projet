#include "Village.h"

unsigned int Village::bois = 40;
unsigned int Village::nourriture = 50;

Village::Village(void)
{
}


Village::~Village(void)
{
}

unsigned int Village::getBois()
{
	return nourriture;
}

unsigned int Village::getNourriture()
{
	return bois;
}

void Village::setBois(unsigned int _bois)
{
	bois = _bois;
}

void Village::setNourriture(unsigned int _nourriture)
{
	 nourriture = _nourriture;
}
