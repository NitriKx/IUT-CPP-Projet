#pragma once

#include <iostream>

class Config
{
public:

	/* First = Largeur / Hauteur = Y */
	static std::pair<int, int> dimentions;

	// La graine d'al�atoire
	static const int seed = -1;

	static const int frequence_compactage_map = 2;
	
	// =======================================
	//				DEPART
	// =======================================
	static const int nourriture = 10;
	static const int bois = 20;

	static const int nb_arbres = 2;
	static const int nb_sanglier = 10;
	static const int nb_gaulois = 1;
	static const int nb_gauloise = 0;

	// =======================================
	//				APPARITION
	//       (1 unit� tout les X tours)
	// =======================================
	
	static const int freq_appr_arbre = 2;
	static const int freq_appr_sanglier = 2;

	// =======================================
	//			 SEUILS ALERTE
	// =======================================

	static const int alerte_nourriture = 200;
	static const int alerte_bois = 30;


	// =======================================
	//				SANGLIER
	// =======================================
	static const int sanglier_point_vie = 2;
	static const int sanglier_esperance_vie = 10;
	static const int sanglier_force_combat = 2;
	static const int sanglier_vision = 1;
	static const int sanglier_vitesse = 0;
	static const int sanglier_nourriture_donnee = 5;


};

