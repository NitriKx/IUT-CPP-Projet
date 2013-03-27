#include "Village.h"
#include "Config.h"

unsigned int Village::bois = Config::bois;
unsigned int Village::nourriture = Config::nourriture;

Village::Village(void)
{
}


Village::~Village(void)
{
}

unsigned int Village::getBois()
{
	return Village::nourriture;
}

unsigned int Village::getNourriture()
{
	return Village::bois;
}

void Village::setBois(unsigned int _bois)
{
	bois = _bois;
}

void Village::setNourriture(unsigned int _nourriture)
{
	 nourriture = _nourriture;
}

void Village::consomerBois(unsigned int _bois)
{
		Village::bois -= _bois;
}
void Village::consomerNourriture(unsigned int _nourriture)
{
		Village::nourriture -= _nourriture;
}

void Village::recevoirBois(unsigned int _bois)
{
	Village::bois += _bois;
}

void Village::recevoirNourriture(unsigned int _nourriture)
{
	Village::nourriture += _nourriture;
}
