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
    if(pos < 0 || pos > this->points.size()) throw Erreur("indice de vecteur de points invalide (getPoint)");
    return this->points.at(pos);
}

void Polygone::setPoint(const int pos, const Vecteur2D point){
    if(pos < 0 || pos < this->points.size()) throw Erreur("indice de vecteur de points invalide (setPoint)");
    this->points[pos] = point;
}

Polygone::operator string() const {
    ostringstream o;

    o << getDebutOSS();

    int taille = this->points.size();

    for(int i=0 ; i<taille ; i++){
        o << this->points.at(i);
        if(i < taille-1) o << ", ";
    }

    o << " ]";

    return o.str();
}

ostream & operator <<(ostream & os, const Polygone p){
    ostringstream oss;

    oss << "Polygone : " << (string) t;
    
    os << oss.str();

    return os;
}