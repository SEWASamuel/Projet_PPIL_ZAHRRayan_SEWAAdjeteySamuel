#include "Point.h"

Point::Point(const Vecteur2D a, const Vecteur2D b) : pointA(a), pointB(b) {}

const Vecteur2D Point::getPointA() const {
    return this->pointA;
}

const Vecteur2D Point::getPointB() const {
    return this->pointB;
}

