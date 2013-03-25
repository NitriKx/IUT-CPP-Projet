#pragma once
#include "Element.h"

enum DIRECTIONS 
{
	NORD = 0,
	SUD = 1,
	NORD_OUEST = 2,
	NORD_EST = 3,
	SUD_OUEST = 4,
	SUD_EST = 5
};

class Mobile :
	public virtual Element
{
private :
	unsigned int ptVie;       // Point de vie restant d'un élément
	unsigned int espVie;      // Esperance de vie d'un élément
	unsigned int forceCombat; // Force au combat d'un élement
	unsigned int vitesse;     // Vitesse de déplacement d'un élément
	unsigned int vision;      // Vision d'un élement (une/deux/trois cases....)

public:

	//
	// CONSTANTES
	//

	char getAffich();
	COLORS getCouleur();	

	//
	// CONSTRCUTEURS
	//

	Mobile(void);
	Mobile(string nom, Position pos, unsigned int _ptVie, unsigned int _espVie, unsigned int _forceCombat, unsigned int _vitesse, unsigned int _vision);
	~Mobile(void);

	//
	// METHODES
	//
	void agir();
	virtual void bouge(void);

	Position calculerNouvelleCoordonnees(DIRECTIONS) const;

	//
	// GETTERS ET SETTERS
	//

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

