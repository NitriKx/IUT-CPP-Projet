#pragma once

#include "Mobile.h"
#include "econio.h"

class Humain :
	public Mobile
{

private :
	

public:
	Humain(void);
	~Humain(void);

	char getAffich();
	COLORS getCouleur();

};

