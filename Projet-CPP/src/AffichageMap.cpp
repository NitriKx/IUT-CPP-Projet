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
	
	//
	// Dessin du contour
	//
	//  - Ligne du haut
	for(int  i=0; i < Config::getTailleGrille().first+2; i++) {
		gotoxy(i, 0);
		cout << "=";
	}
	//  - Ligne du bas
	for(int  i=0; i < Config::getTailleGrille().first+2; i++) {
		gotoxy(i, Config::getTailleGrille().second+2);
		cout << "=";
	}
	//  - Colonne de gauche
	for(int  i=0; i < Config::getTailleGrille().second+2; i++) {
		gotoxy(0, i);
		cout << "=";
	}
	//  - Colonne de droite
	for(int  i=0; i < Config::getTailleGrille().second+2; i++) {
		gotoxy(Config::getTailleGrille().first+2, i);
		cout << "=";
	}
	

	//
	// Dessin des éléments
	//
	for(j=0;j<(*monMonde).size();j++)
	{
		Element *e = monMonde->at(j);
		gotoxy(e->getPosition().getX()+1,e->getPosition().getY()+1);
		textcolor(e->getCouleur());
		cout << e->getAffich();
	}
		
}
