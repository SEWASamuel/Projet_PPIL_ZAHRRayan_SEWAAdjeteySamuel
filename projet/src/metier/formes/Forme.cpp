#include "Forme.h"
#include "../exceptions/Erreur.h"

#include <ostream>

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
}

void Forme::setType(const string nomType){
    if(nomType == ""){
        throw Erreur("nom de type forme vide");
    }
}

const char* Forme::intToCouleur(const int codeCouleur){
    switch (codeCouleur)
    {
    case 0:
        return "Noir";
        break;
    
    case 1:
        return "Bleu";
        break;
    
    case 2:
        return "Rouge";
        break;
    
    case 3:
        return "Vert";
        break;

    case 4:
        return "Jaune";
        break;
    
    case 5:
        return "Cyan";
        break;
    
    default:
        ostringstream oss;
        oss << "code couleur invalide : " << codeCouleur;
        string chaineS = oss.str();
        const char *chaineC = chaineS.c_str();

        throw Erreur(chaineC);
        break;
    }
}

const string Forme::getDebutOSS() const {
    ostringstream o;
    o << "[ "<< Forme::intToCouleur(this->couleur) << ", ";

    return o.str();
}

ostream & operator <<(ostream & os, const Forme * f){
    os << (string)*f;

    return os;
}