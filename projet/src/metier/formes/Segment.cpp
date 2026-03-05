#include "Segment.h"

Segment::Segment(){
    this->extremites = Vecteur2D();
    this->type = "Segment";
}

Segment::Segment(const int couleur = 0, const Vecteur2D vecteur){
    this->couleur = couleur;
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