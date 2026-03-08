#include "Forme.h"
#include "../exceptions/Erreur.h"

Forme::Forme(){ 
    this->couleur = COULEUR_NOIR;
    this->type = "";
}

Forme::Forme(int codeCouleur){
    if(codeCouleur < 0 || codeCouleur >= NB_COULEURS) {
        throw Erreur("code couleur invalide");
    }
    this->couleur = codeCouleur;
    this->type = "";
}


 int Forme::getCouleur() const {
    return this->couleur;
}

 string Forme::getType() const {
    return this->type;
}

void Forme::setCouleur( int couleur){
    if(couleur < 0 || couleur >= NB_COULEURS){
        throw Erreur("code couleur invalide");
    }
    this->couleur = couleur;
}

void Forme::setType(string nomType){
    if(nomType == ""){
        throw Erreur("nom de type forme vide");
    }
    this->type = nomType;
}

void Forme::afficher() const {
    cout << "Forme de type: " << this->type << ", Couleur: " << this->couleur << endl;
}
