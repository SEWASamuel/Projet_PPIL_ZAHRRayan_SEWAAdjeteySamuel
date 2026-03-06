#include "Triangle.h"

Triangle::Triangle() : Forme() {
    this->type = "Triangle";
    this->pointA = Vecteur2D(0,0);
    this->pointB = Vecteur2D(1,0);
    this->pointC = Vecteur2D(0,1);
}

Triangle::Triangle(const int couleur, const Vecteur2D a, const Vecteur2D b, const Vecteur2D c) : Forme(couleur) {
    this->type = "Triangle";
    this->pointA = a;
    this->pointB = b;
    this->pointC = c;
}

const Vecteur2D Triangle::getPointA() const {
    return this->pointA;
}

const Vecteur2D Triangle::getPointB() const {
    return this->pointB;
}

const Vecteur2D Triangle::getPointC() const {
    return this->pointC;
}


void Triangle::setPointA(const Vecteur2D vecteur) {
    this->pointA = vecteur;
}

void Triangle::setPointB(const Vecteur2D vecteur) {
    this->pointB = vecteur;
}

void Triangle::setPointC(const Vecteur2D vecteur) {
    this->pointC = vecteur;
}


void Triangle::setPointA(double x, double y) {
    this->pointA = Vecteur2D(x,y);
}

void Triangle::setPointB(double x, double y) {
    this->pointB = Vecteur2D(x,y);
}
void Triangle::setPointC(double x, double y) {
    this->pointC = Vecteur2D(x,y);
}

Forme * Triangle::translation(const Vecteur2D deplacement){
    return (Forme *) (new Triangle(this->couleur, this->pointA + deplacement, this->pointB + deplacement, this->pointC + deplacement));
}
Forme * Triangle::homothetie(const Vecteur2D centre, const double rapportEchelle){
    // TODO
    return NULL;
}
Forme * Triangle::rotation(const Vecteur2D pointInvariant, const double angleRadians){
    // TODO
    return NULL;
}