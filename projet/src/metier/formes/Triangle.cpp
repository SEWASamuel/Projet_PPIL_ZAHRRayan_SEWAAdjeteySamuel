#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

/******************** CONSTRUCTEURS ********************/

Triangle::Triangle() : Forme(), pointA(0,0), pointB(1,0), pointC(0,1) {
    this->type = "triangle";
}

Triangle::Triangle(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c, int couleur)
    : Forme(couleur), pointA(a), pointB(b), pointC(c) {
    this->type = "triangle";
}

/******************** METHODES D'ACCES ********************/

Vecteur2D Triangle::getPointA() const {
    return this->pointA;
}

Vecteur2D Triangle::getPointB() const {
    return this->pointB;
}

Vecteur2D Triangle::getPointC() const {
    return this->pointC;
}

/******************** METHODES DE MODIFICATION ********************/

void Triangle::setPointA(const Vecteur2D& vecteur) {
    this->pointA = vecteur;
}

void Triangle::setPointB(const Vecteur2D& vecteur) {
    this->pointB = vecteur;
}

void Triangle::setPointC(const Vecteur2D& vecteur) {
    this->pointC = vecteur;
}

void Triangle::setPointA(double x, double y) {
    this->pointA = Vecteur2D(x, y);
}

void Triangle::setPointB(double x, double y) {
    this->pointB = Vecteur2D(x, y);
}

void Triangle::setPointC(double x, double y) {
    this->pointC = Vecteur2D(x, y);
}

/******************** AFFICHAGE ********************/

void Triangle::afficher() const {
    cout << "Triangle de sommets "
         << this->pointA << ", "
         << this->pointB << ", "
         << this->pointC
         << ", couleur : " << this->couleur << endl;
}

/******************** CALCUL DE L'AIRE ********************/

double Triangle::calculerAire() const {
    double x1 = pointA.x;
    double y1 = pointA.y;
    double x2 = pointB.x;
    double y2 = pointB.y;
    double x3 = pointC.x;
    double y3 = pointC.y;

    double det = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    return 0.5 * abs(det);
}