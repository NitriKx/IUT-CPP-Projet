#pragma once
class Village
{
private :

public:	

	//
	// CONSTANTES
	//

	static unsigned int nourriture;
	static unsigned int bois;

	//
	// CONSTRCUTEURS
	//
	Village(void);
	Village(unsigned int _nourriture, unsigned int _bois);
	~Village(void);
	

	//
	// METHODES
	//
	void consomerBois(unsigned int _bois);
	void consomerNourriture(unsigned int _nourriture);
	void recevoirBois(unsigned int _bois);
	void recevoirNourriture(unsigned int _nourriture);
	//
	// GETTERS ET SETTERS
	//

	unsigned int getBois();
	unsigned int getNourriture();

	void setBois(unsigned int _bois);
	void setNourriture(unsigned int _nourriture);
	
}; 

