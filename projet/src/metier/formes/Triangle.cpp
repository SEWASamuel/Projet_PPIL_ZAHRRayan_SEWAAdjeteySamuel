#include "Triangle.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

Triangle::Triangle() : Forme() {
    this->type = "triangle";
    this->pointA = Vecteur2D(0,0);
    this->pointB = Vecteur2D(1,0);
    this->pointC = Vecteur2D(0,1);
}

Triangle::Triangle(const int couleur, const Vecteur2D a, const Vecteur2D b, const Vecteur2D c) : Forme(couleur) {
    this->type = "triangle";
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

Triangle::operator string() const {
    ostringstream o; 
    o << getDebutOSS() << this->pointA << ", " << this->pointB << ", " << this->pointC << " ]";
    return o.str();
}

double Triangle::calculerAire() const {
    double x1 = pointA.x;
    double y1 = pointA.y;
    double x2 = pointB.x;
    double y2 = pointB.y;
    double x3 = pointC.x;
    double y3 = pointC.y;

    return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

void Triangle::dessiner() const {
    cout << "TRIANGLE "
     << pointA.x << " " << pointA.y << " "
     << pointB.x << " " << pointB.y << " "
     << pointC.x << " " << pointC.y << " "
     << Forme::intToCouleur(this->couleur) << endl;
}

const string Triangle::accepte(const VisiteurForme & v) const {
    v.visite(this);
}

ostream & operator <<(ostream & os, const Triangle & t) {
    os << "Triangle : " << (string)t;
    return os;
}