/**
 * @file ParseurFormeCORTriangle.cpp
 * @brief Definition de la fonction "parse1"
 */
#include "ParseurFormeCORTriangle.h"

ParseurFormeCORTriangle::ParseurFormeCORTriangle(ParseurFormeCOR * suivant) : ParseurFormeCOR(suivant) {}

Forme * ParseurFormeCORTriangle::parse1(const char * ligne) const {
    //char * id = "(%d, %d) (%d, %d) (%d, %d)";
    int ax, ay, bx, by, cx, cy;
    int nbValRetour;

    //nbValRetour = sscanf(ligne, id, &ax, &ay, &bx, &by, &cx, &cy);
    nbValRetour = sscanf(ligne, "(%d, %d) | (%d, %d) | (%d, %d)", &ax, &ay, &bx, &by, &cx, &cy);

    if(nbValRetour != 6){
        return NULL;
    }

    return (Forme *) (new Triangle(COULEUR_NOIR, Vecteur2D(ax, by), Vecteur2D(bx, by), Vecteur2D(cx, cy)));
}