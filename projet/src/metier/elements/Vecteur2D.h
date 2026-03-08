/**
 * Représente un couple de coordonnnees, un point du plan, un vecter, in nombre complexe
 */

#ifndef VECTEUR2D
#define VECTEUR2D

#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Vecteur2D
{
    public:
    double x,y;

    /******************** CONSTRUCTEURS ********************/
    Vecteur2D(): x(0.0), y(0.0) {} // on ajoute un constructeur par défaut, car sinon, on aura une erreur lorsqu'on déclare un contructeur pour la classe "Translation"
    explicit Vecteur2D(const double & x, const double & y):x(x), y(y){/* rien a faire*/}

    operator string() const
    {
        ostringstream o;

        o << "(" << x << ", " << this->y << ")";

        return o.str();
    }

    /******************** METHODES ********************/
    // OPERATIONS ALGEBRIQUES

    
    const Vecteur2D operator *(const double & a) const{
        return Vecteur2D(a*x, a*y);
    }

    /**
     * produit scalaire
     */
    double operator *(const Vecteur2D & v) const{
        return x*(v.x) + y*(v.y);
    }

    const Vecteur2D operator +(const Vecteur2D v) const{
        return Vecteur2D(this->x + v.x, this->y + v.y);
    }

    const Vecteur2D operator -(const Vecteur2D v) const{
        return Vecteur2D(this->x - v.x, this->y - v.y);
    }

    double norme2() const{
        return *this * *this;
    }

    double norme() const{
        return sqrt(this->norme2());
        // return sqrt(norme2())
    }

    const double distance2(const Vecteur2D v) const {
        return abs((v.x - (this->x)) + (v.y - (this->y)));
    }

    const double distance(const Vecteur2D v) const {
        return sqrt(distance2(v));
    }

    // cette fonction sert à calculer la distance de Manhattan et non la distance euclidienne
    const Vecteur2D distanceM(const Vecteur2D v) const {
        return Vecteur2D(v.x - this->x, v.y - this->y);
    }
};

ostream & operator <<(ostream & os, const Vecteur2D v){
    //os << "[" << v.x << "," << v.y << "]";
    os << (string)v;
    return os; 
}

#endif