#pragma once
#include "element.h"
class Mobile :
	public Element
{
private :
	unsigned int ptVie; // Point de vie restant d'un élément
	unsigned int espVie; // Esperance de vie d'un élément
	unsigned int forceCombat; // Force au combat d'un élement
	unsigned int vitesse; // Vitesse de déplacement d'un élément
	unsigned int vision; // Vision d'un élement (une/deux/trois cases....)

public:
	Mobile(void);
	Mobile(unsigned int _vitesse, unsigned int _vision);
	~Mobile(void);

	void bouge(void);

	// GETTERS ET SETTERS

	unsigned int getVitesse()const;
	unsigned int getPtVie(void);
	unsigned int getEspVie(void) const;
	unsigned int getForceCombat(void) const;
	unsigned int getVision(void) const;
	
	void setVitesse(unsigned int);
	void setVision(unsigned int);
	void setPtVie(unsigned int);
	void setEspVie(unsigned int);
	void setForceCombat(unsigned int);
	void setVision(unsigned int);

	
};

