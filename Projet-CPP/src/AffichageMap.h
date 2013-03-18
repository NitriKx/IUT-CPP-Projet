#pragma once
#include "Config.h"
#include "Monde.h"
class AffichageMap :
	public Config
{
private :
	Monde * monMonde;
public:
	AffichageMap(void);
	AffichageMap( Monde * _monde);
	~AffichageMap(void);
	void affichageMap();

};

