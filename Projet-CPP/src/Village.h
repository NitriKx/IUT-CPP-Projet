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
	void static consomerBois(unsigned int _bois);
	void static consomerNourriture(unsigned int _nourriture);
	void static recevoirBois(unsigned int _bois);
	void static recevoirNourriture(unsigned int _nourriture);
	//
	// GETTERS ET SETTERS
	//

	unsigned int static getBois();
	unsigned int static getNourriture();

	void static setBois(unsigned int _bois);
	void static setNourriture(unsigned int _nourriture);
	
}; 

