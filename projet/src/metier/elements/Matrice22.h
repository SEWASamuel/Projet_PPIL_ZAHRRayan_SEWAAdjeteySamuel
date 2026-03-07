#ifndef MATRICE22_H
#define MATRICE22_H

#include <string>
#include <sstream>
#include <cmath>
#include "Vecteur2D.h"

class Matrice22{

    public:
    Vecteur2D ligneHaut, ligneBas;

    /******************** CONSTRUCTEURS ********************/
    Matrice22(const Vecteur2D ligneHaut, const Vecteur2D & ligneBas): ligneHaut(ligneHaut), ligneBas(ligneBas){/* rien a faire */}

    explicit Matrice22(const double & a11 = 1, const double & a12 = 1, const double & a21 = 0, const double & a22 = 1) : Matrice22(Vecteur2D(a11, a12), Vecteur2D(a21, a22)) {}

    static const Matrice22 creeRotation(const double & alfa){
        double calfa = cos(alfa);
        double salfa = sin(alfa);

        return Matrice22(calfa, -salfa, salfa, calfa);
    }
    
    /******************** METHODES ********************/
    operator std::string() const{
        std::ostringstream o;

        // o << (string)ligneHaut << std::endl;
        // o << (string)ligneBas;

        o << (string)ligneHaut << ", " << (string)ligneBas << endl;

        return o.str();
    }    

    // OPERATIONS ALGEBRIQUES

    const Vecteur2D operator *(const Vecteur2D & v){
        return Vecteur2D(ligneHaut*v, ligneBas*v);
    }

    const Matrice22 operator +(const Vecteur2D & v){
        return Matrice22(this->ligneHaut + v, this->ligneBas + v);
    }
};

inline std::ostream & operator <<(std::ostream & o, const Matrice22 & mat){
    return o << (string)mat;
}

#endif