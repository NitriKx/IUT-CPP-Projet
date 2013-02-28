#pragma once
#include "element.h"
class Mobile :
	public Element
{
private :
	int vitesse;
	int vision;
public:
	Mobile(void);
	Mobile(const int _vitesse, const int _vision);
	~Mobile(void);
	int getVitesse()const;
	int getVision()const;
	void setVitesse(const int _vitesse);
	void setVision(const int _vision);
	void bouge(void);
};

