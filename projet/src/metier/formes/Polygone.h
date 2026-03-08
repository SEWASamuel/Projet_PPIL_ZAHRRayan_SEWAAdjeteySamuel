#ifndef POLYGONE
#define POLYGONE

#include "Forme.h"
#include "../elements/Vecteur2D.h"

#include <vector>

class Polygone: public Forme {
    vector<Vecteur2D> points;

    public:
    /******************** CONSTRUCTEURS ********************/
    Polygone();
    Polygone(const int couleur, const vector<Vecteur2D> points);

    /******************** METHODES ********************/
    const vector<Vecteur2D> getPoints() const;
    const Vecteur2D getPoint(const int pos) const;

    void setPoint(const int pos, const Vecteur2D point);

    virtual operator string() const;
};

ostream & operator <<(ostream & os, const Polygone t);
#endif