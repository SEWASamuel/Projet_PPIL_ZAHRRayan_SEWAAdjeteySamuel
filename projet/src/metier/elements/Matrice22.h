#ifndef MATRICE22_H
#define MATRICE22_H

#include <string>
#include <sstream>
#include <cmath>
#include "Vecteur2D.h"

class Matrice22 {

public:
    Vecteur2D ligneHaut, ligneBas;

    /******************** CONSTRUCTEURS ********************/
    Matrice22(const Vecteur2D& ligneHaut, const Vecteur2D& ligneBas)
        : ligneHaut(ligneHaut), ligneBas(ligneBas) {}

    explicit Matrice22(const double& a11 = 1, const double& a12 = 0,
                       const double& a21 = 0, const double& a22 = 1)
        : Matrice22(Vecteur2D(a11, a12), Vecteur2D(a21, a22)) {}

    static Matrice22 creeRotation(const double& alfa) {
        double calfa = cos(alfa);
        double salfa = sin(alfa);

        return Matrice22(calfa, -salfa, salfa, calfa);
    }

    /******************** METHODES ********************/
    operator std::string() const {
        std::ostringstream o;

        o << (std::string)ligneHaut << std::endl;
        o << (std::string)ligneBas;

        return o.str();
    }

    // OPERATIONS ALGEBRIQUES
    Vecteur2D operator*(const Vecteur2D& v) const {
        return Vecteur2D(ligneHaut * v, ligneBas * v);
    }
};

inline std::ostream& operator<<(std::ostream& o, const Matrice22& mat) {
    return o << (std::string)mat;
}

#endif