#include "Segment.h"

Segment::Segment(): Forme(){
    this->extremites = Matrice22(Vecteur2D(), Vecteur2D());
    this->type = "Segment";
}

Segment::Segment(const int couleur, const Matrice22 matrice): Forme(couleur){
    this->extremites = matrice;
    this->type = "segment";
}

const Matrice22 Segment::getExtremites() const {
    return this->extremites;
}


void Segment::setExremites(const Matrice22 vecteur){
    this->extremites = vecteur;
}

void Segment::setExtremites(const Vecteur2D a, const Vecteur2D b){
    this->extremites = Matrice22(a,b);
}

Segment::operator string() const {
    ostringstream o;
    
    o << getDebutOSS() << this->extremites << " ]";

    return o.str();
}

ostream & operator <<(ostream & os, const Segment s){

    ostringstream oss;
    
    oss << "Segment : " << string(s);

    os << oss.str();

    return os;
}