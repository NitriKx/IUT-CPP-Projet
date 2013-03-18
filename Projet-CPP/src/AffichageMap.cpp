#include "AffichageMap.h"
#include "Config.h"
#include "econio.h"


AffichageMap::AffichageMap(void)
{
}

AffichageMap::AffichageMap(Monde * _monde)
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
		Element *e = monMonde->at(j);
		gotoxy(e->getPosition().getX(),e->getPosition().getY());
		textcolor(e->getCouleur());
		cout << e->getAffich();
	}
		
}
