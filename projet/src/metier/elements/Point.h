#ifndef POINT
#define POINT

#include "Vecteur2D.h"


class Point {
    Vecteur2D pointA;
    Vecteur2D pointB;

    public:

    Point(const Vecteur2D a, const Vecteur2D b);

    const Vecteur2D getPointA() const;
    const Vecteur2D getPointB() const;

    Vecteur 

};

#endif