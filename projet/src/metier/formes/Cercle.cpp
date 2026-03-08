#include "Cercle.h"
#include "../exceptions/Erreur.h"
#include <iostream>

// Valeur de pi pour le calcul de l'aire du cercle
 const double PI = 3.14159265358979323846;

/******************** CONSTRUCTEURS ********************/
// Constructeur par défaut 
Cercle::Cercle() : Forme(), centre(Vecteur2D()), rayon(1.0) {
    this->type = "cercle";
}
// Constructeur avec paramètres
Cercle::Cercle(const Vecteur2D& centre, double rayon, int couleur)
    : Forme(couleur), centre(centre), rayon(rayon) {

    if (rayon <= 0) {
        throw Erreur("rayon invalide");
    }

    this->type = "cercle";
}

/******************** METHODES ********************/

Vecteur2D Cercle::getCentre() const {
    return this->centre;
}

double Cercle::getRayon() const {
    return this->rayon;
}

void Cercle::setCentre(const Vecteur2D& centre) {
    this->centre = centre;
}

void Cercle::setCentre(double x, double y) {
    this->centre = Vecteur2D(x, y);
}

void Cercle::setRayon(double rayon) {
    if (rayon <= 0) {
        throw Erreur("rayon invalide");
    }
    this->rayon = rayon;
}

void Cercle::afficher() const {
    std::cout << "Cercle de centre " << this->centre
              << ", rayon " << this->rayon
              << ", couleur " << this->couleur << std::endl;
}

double Cercle::calculerAire() const {
    return PI * this->rayon * this->rayon;
}