#include "Segment.h"

Segment::Segment(): Forme(){
    this->extremites = Vecteur2D();
    this->type = "Segment";
}

Segment::Segment(const int couleur, const Vecteur2D vecteur): Forme(couleur){
    this->extremites = vecteur;
    this->type = "segment";
}

const Vecteur2D Segment::getExtremites() const {
    return this->extremites;
}


void Segment::setExremites(const Vecteur2D vecteur){
    this->extremites = vecteur;
}

void Segment::setExtremites(const double x, const double y){
    this->extremites = Vecteur2D(x,y);
}

Segment::operator string() const {
    ostringstream & o = getDebutOSS();
    
    getDebutOSS() << this->extremites << " ]";

    return o.str();
}

Forme * Segment::translation(const Vecteur2D deplacement) const {
    return (Forme *) (new Segment(this->couleur, this->extremites + deplacement));
}

Forme * Segment::homothetie(const Vecteur2D centre, const double rapportEchelle) const {
    // TODO
    return NULL;
}

Forme * Segment::rotation(const Vecteur2D pointInvariant, const double angleRadians) const {
    // TODO
    return NULL;
}

ostream & operator <<(ostream & os, const Segment s){
    os << (string)s;

    return os;
}