#ifndef CERCLE
#define CERCLE

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Cercle: public Forme {
    Vecteur2D centre;
    double rayon;

    public:
    /******************** CONSTRUCTEURS ********************/
    Cercle();
    Cercle(const int couleur, const Vecteur2D vecteur, const double rayon);

    /******************** METHODES ********************/
    const Vecteur2D getCentre() const ;
    const double getRayon() const ;

    void setCentre(const Vecteur2D vecteur);
    void setCentre(const double x, const double y);
    void setRayon(const double rayon);

    virtual operator string() const;

    virtual Forme * translation(const Vecteur2D deplacement) const;
    virtual Forme * homothetie(const Vecteur2D centre, const double rapportEchelle) const;
    virtual Forme * rotation(const Vecteur2D pointInvariant, const double angleRadians) const;
};

ostream & operator <<(ostream & os, const Cercle c);
#endif