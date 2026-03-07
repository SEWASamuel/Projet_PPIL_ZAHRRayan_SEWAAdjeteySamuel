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
    Cercle * c = (Cercle *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D distanceCentres = transAux->getPointCentre().distanceM(c->getCentre());
    
    Vecteur2D nVcentre = transAux->getPointCentre() + (distanceCentres * transAux->getRapportEchelle());
    double nvRayon = abs(c->getRayon() * transAux->getRapportEchelle());
    
    return new Cercle(c->getCouleur(), nVcentre, nvRayon);
}
Forme * TransCercle::rotation(Forme * forme, Transformation * transformation) {
    return NULL;
    // TODO
}