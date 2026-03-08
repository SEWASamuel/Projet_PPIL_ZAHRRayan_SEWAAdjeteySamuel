#include "ParseurFormeCORSegment.h"

ParseurFormeCORSegment::ParseurFormeCORSegment(ParseurFormeCOR * suivant) : ParseurFormeCOR(suivant) {}

Forme * ParseurFormeCORSegment::parse1(const char * ligne) const {
    char * id = "(%d, %d) (%d, %d)";
    int x1, y1, x2, y2;
    int nbValRetour;

    nbValRetour = sscanf(ligne, id, &x1, &y1, &x2, &y2);

    if(nbValRetour != 4){
        return NULL;
    }

    return (Forme *) (new Segment(COULEUR_NOIR, Matrice22(Vecteur2D(x1,y1), Vecteur2D(x2, y2))));
}