#include "Forme.h"
#include "../exceptions/Erreur.h"
#include <ostream>
#include <sstream>

Forme::Forme(){
    this->couleur = COULEUR_NOIR;
}

Forme::Forme(int codeCouleur){
    if(codeCouleur < 0 || codeCouleur >= NB_COULEURS) throw Erreur("code couleur invalide");
    this->couleur = codeCouleur;
}

const int Forme::getCouleur() const {
    return this->couleur;
}

const string Forme::getType() const {
    return this->type;
}

void Forme::setCouleur(const int couleur){
    if(couleur < 0 || couleur >= NB_COULEURS){
        throw Erreur("code couleur invalide");
    }
    this->couleur = couleur;
}

void Forme::setType(const string nomType){
    if(nomType == ""){
        throw Erreur("nom de type forme vide");
    }
    this->type = nomType;
}

// Forme::~Forme() {
// }

const char* Forme::intToCouleur(const int codeCouleur){
    switch (codeCouleur)
    {
    case 0:
        return "Noir";
    case 1:
        return "Bleu";
    case 2:
        return "Rouge";
    case 3:
        return "Vert";
    case 4:
        return "Jaune";
    case 5:
        return "Cyan";
    default:
        throw Erreur("code couleur invalide");
    }
}

const char * Forme::getCouleurString() const {
    return intToCouleur(this->couleur);
}

const string Forme::getDebutOSS() const {
    ostringstream o;
    o << "[ " << Forme::intToCouleur(this->couleur) << ", ";
    return o.str();
}

ostream & operator <<(ostream & os, const Forme * f){
    os << (string)*f;
    return os;
}