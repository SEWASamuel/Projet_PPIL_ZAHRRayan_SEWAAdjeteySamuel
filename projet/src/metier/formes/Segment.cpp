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

Forme * Segment::translation(const Vecteur2D deplacement){
    return (Forme *) (new Segment(this->couleur, this->extremites + deplacement));
}

Forme * Segment::homothetie(const Vecteur2D centre, const double rapportEchelle){
    // TODO
    return NULL;
}

Forme * Segment::rotation(const Vecteur2D pointInvariant, const double angleRadians){
    // TODO
    return NULL;
}