#include "Humain.h"


Humain::Humain(void) : Mobile(3,3), vie(100)
{
}


Humain::~Humain(void)
{
}

int Humain::getVie()const
{
	return this->vie;
}

void Humain::setVie(const int _vie)
{
	this->vie = _vie;
}
