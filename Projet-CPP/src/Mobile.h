#pragma once
#include "element.h"
class Mobile :
	public Element
{
private :
	unsigned int ptVie; // Point de vie restant d'un �l�ment
	unsigned int espVie; // Esperance de vie d'un �l�ment
	unsigned int forceCombat; // Force au combat d'un �lement
	unsigned int vitesse; // Vitesse de d�placement d'un �l�ment
	unsigned int vision; // Vision d'un �lement (une/deux/trois cases....)

public:
	Mobile(void);
	Mobile(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);
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

};

