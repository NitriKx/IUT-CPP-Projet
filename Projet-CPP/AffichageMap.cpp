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
	unsigned int j;
	
	for(j=0;j<(*monMonde).size();j++)
	{
		gotoxy(monMonde->at(j)->getPosition().getX(),monMonde->at(j)->getPosition().getY());
		cout << monMonde->at(j)->affich;
	}
		
}
