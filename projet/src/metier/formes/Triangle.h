#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Triangle : public Forme {

private:

    Vecteur2D pointA;
    Vecteur2D pointB;
    Vecteur2D pointC;

public:

    /******************** CONSTRUCTEURS ********************/

    Triangle();
    Triangle(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c, int couleur);

    /******************** METHODES ********************/

    Vecteur2D getPointA() const;
    Vecteur2D getPointB() const;
    Vecteur2D getPointC() const;

    void setPointA(const Vecteur2D& vecteur);
    void setPointB(const Vecteur2D& vecteur);
    void setPointC(const Vecteur2D& vecteur);

    void setPointA(double x, double y);
    void setPointB(double x, double y);
    void setPointC(double x, double y);

    void afficher() const override;
    double calculerAire() const override;
};

#endif