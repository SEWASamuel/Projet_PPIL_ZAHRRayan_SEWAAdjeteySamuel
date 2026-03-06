#ifndef SEGMENT
#define SEGMENT

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Segment: public Forme {
    Vecteur2D extremites;

    public:
    /******************** CONSTRUCTEURS ********************/
    Segment();
    Segment(const int couleur, const Vecteur2D vecteur);

    /******************** METHODES ********************/
    const Vecteur2D getExtremites() const ;

    void setExremites(const Vecteur2D vecteur);
    void setExtremites(const double x, const double y);

    virtual Forme * translation(const Vecteur2D deplacement);
    virtual Forme * homothetie(const Vecteur2D centre, const double rapportEchelle);
    virtual Forme * rotation(const Vecteur2D pointInvariant, const double angleRadians);
};
#endif