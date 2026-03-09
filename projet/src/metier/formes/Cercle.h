/**
 * @file Cercle.h
 * @brief Definition de la classe Cercle qui dérive de la classe Forme
 */
#ifndef CERCLE
#define CERCLE

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Cercle: public Forme {
    Vecteur2D centre;
    double rayon;

    public:
    Cercle();
    Cercle(const int couleur, const Vecteur2D vecteur, const double rayon);

    const Vecteur2D getCentre() const;
    const double getRayon() const;

    void setCentre(const Vecteur2D vecteur);
    void setCentre(const double x, const double y);
    void setRayon(const double rayon);

    operator string() const;
    void dessiner() const;
    double calculerAire() const;
};

ostream & operator <<(ostream & os, const Cercle & c);

#endif