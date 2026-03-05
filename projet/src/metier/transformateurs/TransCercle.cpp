#include "TransCercle.h"

TransCercle::TransCercle(){
    if(this->type != "Cercle"){
        this->type = "Cercle";
    }
    this->suivant = NULL;
}

TransCercle::TransCercle(Transformateur * suivant) : TransCercle(){
    this->suivant = suivant;
}

Forme * TransCercle::translation(Forme * forme, Transformation * transformation) {
    Cercle * c = (Cercle *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    return new Cercle(c->getCouleur(), c->getCentre() + transAux->getDeplacement(), c->getRayon());
}
Forme * TransCercle::homothetie(Forme * forme, Transformation * transformation) {
    // TODO
    return NULL;
}
Forme * TransCercle::rotation(Forme * forme, Transformation * transformation) {
    return NULL;
    // TODO
}