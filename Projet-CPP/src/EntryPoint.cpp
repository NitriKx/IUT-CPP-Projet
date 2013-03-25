#include "Monde.h"
#include "Element.h"
#include "Mobile.h"
#include "AffichageMap.h"
#include "econio.h"
#include "Config.h"
#include "Humain.h"
#include "Gaulois.h"
#include "Gauloise.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{

	// ================================
	//				TESTS
	// ================================
	
	std::srand((unsigned int) time(0));

	Monde *monde = Monde::getInstance();

	Humain *h0 = new Humain();
	Gaulois *g0 = new Gaulois();
	Gauloise *g1 = new Gauloise();

	Mobile *m1 = new Mobile("M1", Position::random(Config::getTailleGrille().first, Config::getTailleGrille().second), 100, 5, 2000, 2, 3);
	Mobile *m2 = new Mobile("M2", Position::random(Config::getTailleGrille().first, Config::getTailleGrille().second), 100, 5, 2000, 2, 3);

	/*monde->ajouterElement(h0->getPosition(), h0);
	monde->ajouterElement(g0->getPosition(), g0);
	monde->ajouterElement(g1->getPosition(), g1);*/
	monde->ajouterElement(m1->getPosition(), m1);
	monde->ajouterElement(m2->getPosition(), m2);

	AffichageMap *map = new AffichageMap(monde);
	
	while(1) {
		map->affichageMap();
		// On place le curseur à la fin
		gotoxy(Config::getTailleGrille().second+3, Config::getTailleGrille().first+3);
		Sleep(100);
		monde->jourSuivant();
	}

	return 0;
}

