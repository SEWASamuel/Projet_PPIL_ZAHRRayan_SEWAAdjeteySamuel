/**
 * Représente un couple de coordonnnees, un point du plan, un vecter, in nombre complexe
 */

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
        return x*v.x + y*v.y;
    }

    const Vecteur2D operator +(const Vecteur2D v) const{
        return Vecteur2D(this->x + v.x, this->y + v.y);
    }


    double norme2() const{
        return *this * *this;
    }

    double norme() const{
        return sqrt(this->norme());
        // return sqrt(norme2())
    }
};

ostream & operator <<(ostream & os, const Vecteur2D v){
    os << "[" << v.x << "," << v.y << "]";
    return os; 
}