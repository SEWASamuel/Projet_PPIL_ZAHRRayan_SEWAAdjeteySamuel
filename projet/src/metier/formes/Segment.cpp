#include "Segment.h"
#include "../reseau/ClientTCP.h"
#include <sstream>

Segment::Segment() : Forme() {
    this->extremites = Matrice22(Vecteur2D(), Vecteur2D());
    this->type = "segment";
}

Segment::Segment(const int couleur, const Matrice22 matrice) : Forme(couleur) {
    this->extremites = matrice;
    this->type = "segment";
}

const Matrice22 Segment::getExtremites() const {
    return this->extremites;
}

void Segment::setExremites(const Matrice22 vecteur) {
    this->extremites = vecteur;
}

void Segment::setExtremites(const Vecteur2D a, const Vecteur2D b) {
    this->extremites = Matrice22(a, b);
}

Segment::operator string() const {
    ostringstream o;
    o << getDebutOSS() << this->extremites << " ]";
    return o.str();
}

void Segment::dessiner() const {
    ostringstream oss;
    oss << "SEGMENT "
        << extremites.ligneHaut.x << " " << extremites.ligneHaut.y << " "
        << extremites.ligneBas.x << " " << extremites.ligneBas.y << " "
        << this->couleur;

    string commande = oss.str();

    cout << commande << endl;
    ClientTCP::envoyerAuServeur(commande, "127.0.0.1", 9111);
}

double Segment::calculerAire() const {
    return 0;
}

ostream & operator <<(ostream & os, const Segment & s) {
    ostringstream oss;
    oss << "Segment : " << string(s);
    os << oss.str();
    return os;
}