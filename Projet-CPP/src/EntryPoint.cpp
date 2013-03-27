#include "Monde.h"
#include "Element.h"
#include "Mobile.h"
#include "AffichageMap.h"
#include "econio.h"
#include "Config.h"
#include "Arbre.h"
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

	// On initialise la graine
	if(Config::seed < 0) {
		std::srand((unsigned int) time(0));
	} 
	else {
		std::srand(Config::seed);
	}
	
	Monde *monde = Monde::getInstance();
	monde->initialiserMonde();

	AffichageMap *map = new AffichageMap(monde);
	
	while(1) {
		map->affichageMap();
		// On place le curseur à la fin
		gotoxy(Config::dimentions.second+3, Config::dimentions.first+3);
		getchar();
		monde->jourSuivant();
	}

	return 0;
}

