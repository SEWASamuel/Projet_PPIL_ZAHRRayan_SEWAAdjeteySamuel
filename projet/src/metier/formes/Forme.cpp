#include "Forme.h"
#include "../exceptions/Erreur.h"

Forme::Forme(){ this->couleur = COULEUR_NOIR; }
Forme::Forme(int codeCouleur){
    if(codeCouleur == NB_COULEURS) throw Erreur("code couleur invalide");
    this->couleur = couleur;
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