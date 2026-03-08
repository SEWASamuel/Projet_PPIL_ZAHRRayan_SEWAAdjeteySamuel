#ifndef VECTEUR2D_H
#define VECTEUR2D_H

/**
 * Représente un couple de coordonnées, un point du plan, un vecteur
 */

#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

class Vecteur2D
{
public:
    double x, y;

    /******************** CONSTRUCTEURS ********************/
    Vecteur2D() : x(0.0), y(0.0) {}
    explicit Vecteur2D(const double& x, const double& y) : x(x), y(y) {}

    operator string() const
    {
        ostringstream o;
        o << "(" << x << ", " << this->y << ")";
        return o.str();
    }

    /******************** METHODES ********************/
    // OPERATIONS ALGEBRIQUES

    const Vecteur2D operator*(const double& a) const {
        return Vecteur2D(a * x, a * y);
    }

    /**
     * produit scalaire
     */
    double operator*(const Vecteur2D& v) const {
        return x * v.x + y * v.y;
    }

    const Vecteur2D operator+(const Vecteur2D& v) const {
        return Vecteur2D(this->x + v.x, this->y + v.y);
    }

    double norme2() const {
        return *this * *this;
    }

    double norme() const {
        return sqrt(this->norme2());
    }
};

inline ostream& operator<<(ostream& os, const Vecteur2D& v) {
    os << "[" << v.x << "," << v.y << "]";
    return os;
}

#endif