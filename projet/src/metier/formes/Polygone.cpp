#include "Polygone.h"

Polygone::Polygone() : Forme(), points(vector<Vecteur2D>()){
    this->type = "polygone";
}

Polygone::Polygone(const int couleur, const vector<Vecteur2D> points) : Forme(couleur), points(points) {
    this->type = "polygone";
}

const vector<Vecteur2D> Polygone::getPoints() const {
    return this->points;
}

const Vecteur2D Polygone::getPoint(const int pos) const {
    if(pos < 0 || pos > this->points.size()) throw Erreur("indice de vecteur de points invalide");
    return this->points.at(pos);
}

Polygone::operator string() const {
    ostringstream o;

    vector<Vecteur2D>::iterator it;

    for(it = this->points.begin(), )
    
    o << getDebutOSS() << this->pointA << ", " << this->pointB << ", " << this->pointC << " ]";

    return o.str();
}

ostream & operator <<(ostream & os, const Triangle t){
    ostringstream oss;

    oss << "Triangle : " << (string) t;
    
    os << oss.str();

    return os;
}