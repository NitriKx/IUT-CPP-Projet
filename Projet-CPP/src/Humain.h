#pragma once
#include "mobile.h"
class Humain :
	public Mobile
{

private :
	int vie; 
public:
	Humain(void);
	~Humain(void);

	static const char affich = 'H';//caractère d'affichage

};

