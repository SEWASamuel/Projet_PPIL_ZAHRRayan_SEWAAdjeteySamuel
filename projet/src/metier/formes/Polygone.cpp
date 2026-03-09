/**
 * @file Polygone.cpp
 * @brief Definition des fonctions de la classe polygone
 */
#include "Polygone.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

Polygone::Polygone() : Forme(), points(vector<Vecteur2D>()) {
    this->type = "polygone";
}

Polygone::Polygone(const int couleur, const vector<Vecteur2D> points) : Forme(couleur), points(points) {
    this->type = "polygone";
}

const vector<Vecteur2D> Polygone::getPoints() const {
    return this->points;
}

const Vecteur2D Polygone::getPoint(const unsigned int pos) const {
    if (pos < 0 || pos >= (int)this->points.size()) {
        throw Erreur("indice de vecteur de points invalide (getPoint)");
    }
    return this->points.at(pos);
}

void Polygone::setPoint(const unsigned int pos, const Vecteur2D point) {
    if (pos < 0 || pos >= (int)this->points.size()) {
        throw Erreur("indice de vecteur de points invalide (setPoint)");
    }
    this->points[pos] = point;
}

void Polygone::dessiner() const {
    cout << "POLYGONE " << points.size() << " ";

    for (int i = 0; i < (int)points.size(); i++) {
        cout << points[i].x << " " << points[i].y << " ";
    }

   cout << Forme::intToCouleur(this->couleur) << endl;
}

double Polygone::calculerAire() const {
    double aire = 0;
    int n = (int)points.size();

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        aire += points[i].x * points[j].y;
        aire -= points[j].x * points[i].y;
    }

    return abs(aire) / 2.0;
}

// const string Polygone::accepte(VisiteurForme * v) const {
//     return v->visite(this);
// }

Polygone::operator string() const {
    ostringstream o;

    o << getDebutOSS();

    int taille = (int)this->points.size();

    for (int i = 0; i < taille; i++) {
        o << this->points.at(i);
        if (i < taille - 1) {
            o << ", ";
        }
    }

    o << " ]";

    return o.str();
}

ostream & operator <<(ostream & os, const Polygone p) {
    os << "Polygone : " << (string)p;
    return os;
}