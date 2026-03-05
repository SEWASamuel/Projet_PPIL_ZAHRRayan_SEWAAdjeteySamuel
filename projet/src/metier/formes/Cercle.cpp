#include "Cercle.h"

Cercle::Cercle(){;
    this->centre = Vecteur2D();
    this->rayon = 1;
    this->type = "Cercle";
}

Cercle::Cercle(const int couleur, const Vecteur2D vecteur, const double rayon){
    this->couleur = couleur;
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