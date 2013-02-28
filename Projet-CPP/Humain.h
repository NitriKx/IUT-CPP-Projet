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
	int getVie()const;
	void setVie(const int _vie);
};

