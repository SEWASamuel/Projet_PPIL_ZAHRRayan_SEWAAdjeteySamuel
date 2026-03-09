#ifndef POLYGONE
#define POLYGONE

#include "Forme.h"
#include "../elements/Vecteur2D.h"
#include <vector>
#include <ostream>

class Polygone : public Forme {
    private:
    vector<Vecteur2D> points;

    public:
    /******************** CONSTRUCTEURS ********************/
    Polygone();
    Polygone(const int couleur, const vector<Vecteur2D> points);

    /******************** METHODES ********************/
    const vector<Vecteur2D> getPoints() const;
    const Vecteur2D getPoint(const unsigned int pos) const;

    void setPoint(const unsigned int pos, const Vecteur2D point);

    operator string() const;
    void dessiner() const;
    double calculerAire() const;

    const string accepte(VisiteurForme * v) const;
};

ostream & operator <<(ostream & os, const Polygone p);
#endif