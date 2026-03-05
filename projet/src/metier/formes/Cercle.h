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
    Cercle(const int couleur = 0, const Vecteur2D vecteur, const double rayon);

    /******************** METHODES ********************/
    const Vecteur2D getCentre() const ;
    const double getRayon() const ;

    void setCentre(const Vecteur2D vecteur);
    void setCentre(const double x, const double y);
    void setRayon(const double rayon);
};
#endif