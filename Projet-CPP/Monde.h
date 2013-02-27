#pragma once

#include <iostream>
#include <vector>
#include "Element.h"

class Monde
{
private:
	vector<Element> elements;
public:
	Monde(void);
	~Monde(void);
	vector<Element>& getElements(void);
};

