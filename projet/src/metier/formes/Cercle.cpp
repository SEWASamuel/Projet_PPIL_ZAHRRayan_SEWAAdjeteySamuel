#include "Cercle.h"

Cercle::Cercle() : Forme() {
    this->centre = Vecteur2D();
    this->rayon = 1;
    this->type = "Cercle";
}

Cercle::Cercle(const int couleur, const Vecteur2D vecteur, const double rayon) : Forme(couleur) {
    this->type = "Cercle";
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
    ostringstream & o = getDebutOSS();

    o << this->centre << ", " << this->rayon << " ]";

    return o.str();
}

Forme * Cercle::translation(const Vecteur2D deplacement) const {
    return (Forme *) (new Cercle(this->couleur, this->centre + deplacement, this->rayon));
}
Forme * Cercle::homothetie(const Vecteur2D centre, const double rapportEchelle) const {
    // TODO
    return NULL;
}
Forme * Cercle::rotation(const Vecteur2D pointInvariant, const double angleRadians) const {
    // TODO
    return NULL;
}

ostream & operator <<(ostream & os, const Cercle c){
    ostringstream oss;

    oss << "Cercle : " << (string)c;

    os << oss.str();

    return os;
}