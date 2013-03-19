#pragma once

#include <iostream>

class Config
{
public:
	Config(void);
	~Config(void);

	/* First = X / Second = Y */
	static std::pair<int,int> getTailleGrille ()  {	
		return std::pair<int, int>(10,10);
	};

};

