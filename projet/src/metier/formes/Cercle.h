#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Cercle : public Forme {

private:

    Vecteur2D centre;
    double rayon;

public:

    /******************** CONSTRUCTEURS ********************/

    Cercle();
    Cercle(const Vecteur2D& centre, double rayon, int couleur);

    /******************** METHODES ********************/

    Vecteur2D getCentre() const;
    double getRayon() const;

    void setCentre(const Vecteur2D& centre);
    void setCentre(double x, double y);

    void setRayon(double rayon);

    void afficher() const override;

    double calculerAire() const override;
};

#endif