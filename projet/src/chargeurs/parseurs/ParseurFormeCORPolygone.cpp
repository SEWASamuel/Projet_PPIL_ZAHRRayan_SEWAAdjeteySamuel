/**
 * @file ParseurFormeCORPolygone.cpp
 * @brief Definition de la fonction "parse1"
 */
#include "ParseurFormeCORPolygone.h"
#include <vector>
#include <string.h>

ParseurFormeCORPolygone::ParseurFormeCORPolygone(ParseurFormeCOR * suivant) : ParseurFormeCOR(suivant) {}

Forme * ParseurFormeCORPolygone::parse1(const char * ligne) const {
    char *init = strchr(ligne, '[');
    if(init == NULL) return NULL;
    //else cout << "On a trouve le crochet" << endl; // test

    char *fin = strchr(ligne, ']');

    int x,y;
    int nbValRetour;
    char * finPoint;
    int longChainePoint;
    char donnees[50];
    char *delimiteurChaineDonnees;
    vector<Vecteur2D> points = vector<Vecteur2D>();


    while(init <= fin){
        finPoint = strchr(init, ')');
        if(finPoint != NULL){
            longChainePoint = finPoint - init;
            strncpy(donnees, init+1, longChainePoint);
            delimiteurChaineDonnees = donnees+longChainePoint;
            *delimiteurChaineDonnees = '\0';
            nbValRetour = sscanf(donnees, "(%d, %d) ", &x, &y);
            //if(nbValRetour == 2) cout << "On a trouve 2 valeurs pour : " << donnees << endl; // test
            points.push_back(Vecteur2D(x, y));
        }
        init = init + longChainePoint + 1;
    }
    
    return (Forme *) (new Polygone(COULEUR_NOIR, points));
}