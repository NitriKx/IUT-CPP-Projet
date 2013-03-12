#pragma once

#include <iostream>
#include <string>
#include "Position.h"
#include "conio.h"
#include "Color.h"


class Monde;

class Element
{
private:
	Position pos; //variable position de l'element
	string nom; //nom de l'element
	char element; //lettre associ� � un �l�ment
	unsigned int ptVie; //point de vie restant d'un �l�ment
	unsigned int espVie; //esperance de vie d'un �l�ment
	unsigned int forceCombat; //force au combat d'un �lement
	unsigned int vitesseDep; //vitesse de d�placement d'un �l�ment
	unsigned int vision; //vision d'un �lement (une/deux/trois cases....)
	Color couleur; //couleur associ�e � l'element
	unsigned int qtRessource; //quantit� de ressource pour une ressource / qt enr eserve pour le peuple
	static char affich;//caract�re d'affichage

	
public:
	Element(void);
	Element::Element(string nom, Position pos);
	~Element(void);
	

	//setteurs
	void setNom(string nom);
	void setPosition(Position pos);
	void setPostion(int x, int y);
	void setElement(char _element);
	void setPtVie(unsigned int _ptVie);
	void setEspVie(unsigned int _espVie);
	void setForceCombat(unsigned int _forceCombat);
	void setVitesseDep(unsigned int _vitesseDep);
	void setVision(unsigned int _vision);
	void setColor(Color _color);
	void setQtRessource(unsigned int _qtRessource);
	void setAffich(const char _affich);

		
	//getteurs
	Position getPosition(void) const;
	string getNom(void) const;
	char getElement(void) const;
	unsigned int getPtVie(void);
	unsigned int getEspVie(void) const;
	unsigned int getForceCombat(void) const;
	unsigned int getVitesseDep(void) const;
	unsigned int getVision(void) const;
	Color getColor(void) const;
	unsigned int getQtRessource(void) const;
	char getAffich(void)const;



};

#include "Monde.h"
