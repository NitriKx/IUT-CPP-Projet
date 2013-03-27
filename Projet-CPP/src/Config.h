#pragma once

#include <iostream>

class Config
{
public:

	/* First = Largeur / Hauteur = Y */
	static std::pair<int, int> dimentions;

	// La graine d'aléatoire
	static const int seed = -1;

	static const int frequence_compactage_map = 2;
	
	// =======================================
	//				DEPART
	// =======================================
	static const int nourriture = 300;
	static const int bois = 20;
	static const int nb_arbres = 2;
	static const int nb_sanglier = 0;
	static const int nb_gaulois = 1;
	static const int nb_gauloise = 0;


	// =======================================
	//				CONSOMMATION
	// =======================================
	static const int conso_nouriture = 1;
	static const int conso_bbois = 1;

	// =======================================
	//				APPARITION
	//       (1 unité tout les X tours)
	// =======================================
	
	static const int freq_appr_arbre = 2;
	static const int freq_appr_sanglier = 2;

	// =======================================
	//			 SEUILS ALERTE
	// =======================================

	static const int alerte_nourriture = 10;
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


	// =======================================
	//				BOIS
	// =======================================

	static const int arbre_bois_donnee = 5;


};

