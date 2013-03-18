#include "Humain.h"

char Humain::getAffich() {
	return 'H';
}

COLORS Humain::getCouleur() {
	return RED;
}

Humain::Humain(void) : Mobile() {
}

Humain::~Humain(void)
{
}
