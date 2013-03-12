#include "AffichageMap.h"
#include "Config.h"
#include "econio.h"


AffichageMap::AffichageMap(void)
{
}

AffichageMap::AffichageMap( Monde * _monde)
{
	monMonde = _monde;
}


AffichageMap::~AffichageMap(void)
{
}

void AffichageMap::affichageMap()
{
	int j;
	
	
	for(j=0;j<(*monMonde).size();j++)
	{
		(*monMonde).at(j).Element::getPosition().Position::getX();
	}
		
}
