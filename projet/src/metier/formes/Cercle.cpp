#include "Cercle.h"

Cercle::Cercle() : Forme() {
    this->centre = Vecteur2D();
    this->rayon = 1;
    this->type = "cercle";
}

Cercle::Cercle(const int couleur, const Vecteur2D vecteur, const double rayon) : Forme(couleur) {
    this->type = "cercle";
    this->centre = vecteur;
    this->rayon = rayon;
}

const Vecteur2D Cercle::getCentre() const {
    return this->centre;
}

const double Cercle::getRayon() const {
    return this->rayon;
}


void Cercle::setCentre(const Vecteur2D vecteur) {
    this->centre = vecteur;
}

void Cercle::setCentre(const double x, const double y) {
    this->centre = Vecteur2D(x,y);
}

void Cercle::setRayon(const double rayon) {
    this->rayon = rayon;
}

Cercle::operator string() const{
    ostringstream o;
    
    o << getDebutOSS() << this->centre << ", " << this->rayon << " ]";

    return o.str();
}

ostream & operator <<(ostream & os, const Cercle c){
    ostringstream oss;

    oss << "Cercle : " << (string)c;

    os << oss.str();

    return os;
}