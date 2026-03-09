/**
 * @file Vecteur2D.h
 * @brief Definition de la classe Vecteur2D et ses fonctions \n
 * cette classe sert à créer des formes et les manipuler 
 */
#ifndef VECTEUR2D
#define VECTEUR2D

#include <string>
#include <sstream>
#include <cmath>
#include <ostream>

using namespace std;

class Vecteur2D
{
    public:
    double x, y;

    /******************** CONSTRUCTEURS ********************/
    Vecteur2D() : x(0.0), y(0.0) {}
    explicit Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

    operator string() const
    {
        ostringstream o;
        o << "(" << x << ", " << this->y << ")";
        return o.str();
    }

    /******************** METHODES ********************/
    const Vecteur2D operator *(const double & a) const {
        return Vecteur2D(a * x, a * y);
    }

    double operator *(const Vecteur2D & v) const {
        return x * v.x + y * v.y;
    }

    const Vecteur2D operator +(const Vecteur2D v) const {
        return Vecteur2D(this->x + v.x, this->y + v.y);
    }

    const Vecteur2D operator -(const Vecteur2D v) const {
        return Vecteur2D(this->x - v.x, this->y - v.y);
    }

    double norme2() const {
        return *this * *this;
    }

    double norme() const {
        return sqrt(this->norme2());
    }

    const double distance2(const Vecteur2D v) const {
        return abs((v.x - this->x) + (v.y - this->y));
    }

    const double distance(const Vecteur2D v) const {
        return sqrt(distance2(v));
    }

    const Vecteur2D distanceM(const Vecteur2D v) const {
        return Vecteur2D(v.x - this->x, v.y - this->y);
    }
};

inline ostream & operator <<(ostream & os, const Vecteur2D & v) {
    os << (string)v;
    return os;
}

#endif