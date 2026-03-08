#include "Segment.h"
#include <iostream>

using namespace std;

/******************** CONSTRUCTEURS ********************/

// Constructeur par défaut
// Crée un segment [ (0,0) ; (0,0) ] avec la couleur par défaut
Segment::Segment() : Forme(), A(Vecteur2D()), B(Vecteur2D()) {
    this->type = "segment";
}

// Constructeur avec paramètres
// Crée un segment défini par deux points A et B et une couleur
Segment::Segment(const Vecteur2D& A, const Vecteur2D& B, int couleur)
    : Forme(couleur), A(A), B(B) {
    this->type = "segment";
}

/******************** METHODES D'ACCES ********************/

// Retourne le premier point du segment
Vecteur2D Segment::getA() const {
    return this->A;
}

// Retourne le second point du segment
Vecteur2D Segment::getB() const {
    return this->B;
}

/******************** METHODES DE MODIFICATION ********************/

// Modifie le premier point du segment
void Segment::setA(const Vecteur2D& A) {
    this->A = A;
}

// Modifie le second point du segment
void Segment::setB(const Vecteur2D& B) {
    this->B = B;
}

/******************** AFFICHAGE ********************/

// Affiche les informations du segment
void Segment::afficher() const {
    cout << "Segment de " << this->A
         << " a " << this->B
         << ", couleur : " << this->couleur << endl;
}

/******************** CALCUL DE L'AIRE ********************/

// Un segment n'a pas d'aire
double Segment::calculerAire() const {
    return 0.0;
}