#include "Mobile.h"


Mobile::Mobile(void)
{
}

Mobile::Mobile(const int _vitesse, const int _vision) : Element(),,vitesse(_vitesse), vision(_vision)
{
}


Mobile::~Mobile(void)
{
}


void Mobile::bouge(void)
{
}

int Mobile::getVision()const
{
	return this->vision;
}

int Mobile::getVitesse()const
{
	return this->vitesse;
}

void Mobile::setVision(const int _vision)
{
	this->vision = _vision;
}

void Mobile::setVitesse(const int _vitesse)
{
	this->vitesse = _vitesse;
}
