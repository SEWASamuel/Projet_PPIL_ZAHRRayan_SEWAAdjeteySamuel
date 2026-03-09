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

void Segment::dessiner() const {
    cout << "SEGMENT "
         << extremites.ligneHaut.x << " " << extremites.ligneHaut.y << " "
         << extremites.ligneBas.x << " " << extremites.ligneBas.y << " "
         << Forme::intToCouleur(this->couleur) << endl;
}
double Segment::calculerAire() const {
    return 0;
}

const string Segment::accepte(VisiteurForme * v) const {
    return v->visite(this);
}

ostream & operator <<(ostream & os, const Segment s){

    ostringstream oss;
    
    oss << "Segment : " << string(s);

    os << oss.str();

    return os;
}