#include "AffichageMap.h"
#include "Config.h"
#include "econio.h"


AffichageMap::AffichageMap(void)
{
}

AffichageMap::AffichageMap(Monde * _monde)
{
	monMonde = _monde;
	this->dessinerGrille();
}


AffichageMap::~AffichageMap(void)
{
}

void AffichageMap::affichageMap()
{
	unsigned int j;
	
	// On réinitialise la couleur
	textcolor(WHITE);
	// On vide l'écran et on redessine la grille
	clrscr();
	this->dessinerGrille();

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

void AffichageMap::viderInterieurGrille() {
	for(int i = 1 ; i < Config::dimentions.first+1; i++) {
		for(int j = 1 ; j < Config::dimentions.second+1; j++) {
			gotoxy(i,j);
			cout << " ";
		}
	}
}

void AffichageMap::dessinerGrille() {
	
	//
	// Dessin du contour
	//
	//  - Ligne du haut
	for(int  i=0; i < Config::dimentions.first+1; i++) {
		gotoxy(i, 0);
		cout << "=";
	}
	//  - Ligne du bas
	for(int  i=0; i < Config::dimentions.first+1; i++) {
		gotoxy(i, Config::dimentions.second+1);
		cout << "=";
	}
	//  - Colonne de gauche
	for(int  i=0; i < Config::dimentions.second+2; i++) {
		gotoxy(0, i);
		cout << "=";
	}
	//  - Colonne de droite
	for(int  i=0; i < Config::dimentions.second+2; i++) {
		gotoxy(Config::dimentions.first+1, i);
		cout << "=";
	}
}