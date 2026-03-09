/**
 * @file ChargeurListeFormes.h
 * @brief Classe interface servant à charger des formes à partir d'un fichier
 */
#ifndef CHARGEUR_LISTE_FORMES
#define CHARGEUR_LISTE_FORMES

#include <vector>
#include "../metier/formes/Forme.h"
#include "parseurs/ParseurForme.h"

class ChargeurListeFormes {
    public:
    static const vector<Forme*> charge(FILE * fichier, ParseurForme * parseur);
};

#endif