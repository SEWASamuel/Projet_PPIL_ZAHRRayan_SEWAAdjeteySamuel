/**
 * @file Forme_comp.cpp
 * @brief Definition des fonctions de la classe Forme_comp
 */
#include "Forme_comp.h"
#include <iostream>
#include <sstream>
#include "../exceptions/Erreur.h"

using namespace std;

/******************** CONSTRUCTEURS ********************/

Forme_comp::Forme_comp() : Forme() {
    this->type = "groupe";
}

Forme_comp::Forme_comp(int couleur) : Forme(couleur) {
    this->type = "groupe";
}

/******************** DESTRUCTEUR ********************/

Forme_comp::~Forme_comp() {
    for (Forme* f : formes) {
        delete f;
    }
}

/******************** GESTION DES FORMES ********************/

void Forme_comp::addForme(Forme* forme) {
    if (forme == nullptr) {
        throw Erreur("forme nulle");
    }

    formes.push_back(forme);
}

void Forme_comp::delForme(int index) {
    if (index < 0 || index >= (int)formes.size()) {
        throw Erreur("index invalide");
    }

    delete formes[index];
    formes.erase(formes.begin() + index);
}

Forme* Forme_comp::getForme(int index) const {
    if (index < 0 || index >= (int)formes.size()) {
        throw Erreur("index invalide");
    }

    return formes[index];
}

int Forme_comp::getNbFormes() const {
    return (int)formes.size();
}

/******************** DESSIN ********************/

void Forme_comp::dessiner() const {
    for (Forme* f : formes) {
        f->dessiner();
    }
}

/******************** CALCUL AIRE ********************/

double Forme_comp::calculerAire() const {
    double aireTotal = 0.0;

    for (Forme* f : formes) {
        aireTotal += f->calculerAire();
    }

    return aireTotal;
}

/******************** CONVERSION STRING ********************/

Forme_comp::operator string() const {
    ostringstream o;

    o << getDebutOSS();

    for (int i = 0; i < (int)formes.size(); i++) {
        o << (string)(*formes[i]);
        if (i < (int)formes.size() - 1) {
            o << ", ";
        }
    }

    o << " ]";

    return o.str();
}

// const string Forme_comp::accepte(VisiteurForme * v) const {
//     return v->visite(this);
// }