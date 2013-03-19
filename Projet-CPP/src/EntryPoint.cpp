#include "Monde.h"
#include "Element.h"
#include "Mobile.h"
#include "AffichageMap.h"
#include "econio.h"
#include "Config.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{

	// ================================
	//				TESTS
	// ================================
	
	Monde *monde = Monde::getInstance();

	Element *e0 = new Element("E0", Position(0,0));
	Element *e1 = new Element("E1", Position(1,1));
	Element *e2 = new Element("E2", Position(3,3));

	Mobile *m1 = new Mobile("M1", Position(2,2), 100, 5, 2000, 2, 3);
	Mobile *m2 = new Mobile("M2", Position(2,0), 100, 5, 2000, 2, 3);

	monde->ajouterElement(e0->getPosition(), e0);
	monde->ajouterElement(e1->getPosition(), e1);
	monde->ajouterElement(e2->getPosition(), e2);
	monde->ajouterElement(m1->getPosition(), m1);
	monde->ajouterElement(m2->getPosition(), m2);

	AffichageMap *map = new AffichageMap(monde);
	
	while(1) {
		map->affichageMap();
		// On place le curseur à la fin
		gotoxy(Config::getTailleGrille().second+3, Config::getTailleGrille().first+3);
		system("PAUSE>NUL");
		monde->jourSuivant();
	}

	return 0;
}

