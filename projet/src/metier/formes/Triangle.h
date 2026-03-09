#ifndef TRIANGLE
#define TRIANGLE

#include "Forme.h"
#include "../elements/Vecteur2D.h"
#include <ostream>

class Triangle : public Forme {
    private:
    Vecteur2D pointA;
    Vecteur2D pointB;
    Vecteur2D pointC;

    public:
    /******************** CONSTRUCTEURS ********************/
    Triangle();
    Triangle(const int couleur, const Vecteur2D a, const Vecteur2D b, const Vecteur2D c);

    /******************** METHODES ********************/
    const Vecteur2D getPointA() const;
    const Vecteur2D getPointB() const;
    const Vecteur2D getPointC() const;

    void setPointA(const Vecteur2D vecteur);
    void setPointB(const Vecteur2D vecteur);
    void setPointC(const Vecteur2D vecteur);

    void setPointA(const double x, const double y);
    void setPointB(const double x, const double y);
    void setPointC(const double x, const double y);

    operator string() const;
    void dessiner() const;
    double calculerAire() const;

    const string accepte(const VisiteurForme & v) const;
};

ostream & operator <<(ostream & os, const Triangle & t);

#endif