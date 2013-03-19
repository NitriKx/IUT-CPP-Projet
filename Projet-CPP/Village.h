#pragma once
class Village
{
private :
	static unsigned int nourriture;
	static unsigned int bois;

public:	

	//
	// CONSTANTES
	//


	//
	// CONSTRCUTEURS
	//
	Village(void);
	Village(unsigned int _nourriture, unsigned int _bois);
	~Village(void);
	

	//
	// METHODES
	//


	//
	// GETTERS ET SETTERS
	//

	unsigned int getBois();
	unsigned int getNourriture();

	void setBois(unsigned int _bois);
	void setNourriture(unsigned int _nourriture);
};

