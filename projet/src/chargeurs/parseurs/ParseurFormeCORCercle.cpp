#include "ParseurFormeCORCercle.h"

ParseurFormeCORCercle::ParseurFormeCORCercle(ParseurFormeCOR * suivant) : ParseurFormeCOR(suivant) {}

Forme * ParseurFormeCORCercle::parse1(const char * ligne) const {
    char * id = "(%d, %d) %d";
    int cx, cy, r;
    int nbValRetour;

    nbValRetour = sscanf(ligne, id, &cx, &cy, &r);

    if(nbValRetour != 3){
        return NULL;
    }

    return (Forme *) (new Cercle(COULEUR_NOIR, Vecteur2D(cx, cy), r));
}