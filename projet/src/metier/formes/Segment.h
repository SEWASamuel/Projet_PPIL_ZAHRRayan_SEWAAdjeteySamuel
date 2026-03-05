#ifndef SEGMENT
#define SEGMENT

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Segment: public Forme {
    Vecteur2D extremites;

    public:
    /******************** CONSTRUCTEURS ********************/
    Segment();
    Segment(const int couleur = 0, const Vecteur2D vecteur);

    /******************** METHODES ********************/
    const Vecteur2D getExtremites() const ;

    void setExremites(const Vecteur2D vecteur);
    void setExtremites(const double x, const double y);
};
#endif