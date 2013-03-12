#pragma once
#include "Config.h"
#include "Monde.h"
class AffichageMap :
	public Config
{
private :
	Monde monMonde;
public:
	AffichageMap(void);
	AffichageMap(const Monde * _monde);
	~AffichageMap(void);
	void affichageMap();

};

