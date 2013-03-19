#pragma once

#include <iostream>

class Config
{
public:
	Config(void);
	~Config(void);

	/* First = Largeur / Hauteur = Y */
	static std::pair<int,int> getTailleGrille ()  {	
		return std::pair<int, int>(
			10, // Largeur
			10  // Hauteur
		);
	};

};

