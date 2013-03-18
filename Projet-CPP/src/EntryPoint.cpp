#include "Monde.h"
#include "Element.h"
#include "Mobile.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{

	// ================================
	//				TESTS
	// ================================
	
	Monde *monde = new Monde();

	Element *e1 = new Element("E1", Position(1,1));
	Element *e2 = new Element("E2", Position(3,3));

	Mobile *m1 = new Mobile("M1", Position(2,2), 2,3);
	Mobile *m2 = new Mobile("M1", Position(2,1), 1,3);

	return 0;
}

