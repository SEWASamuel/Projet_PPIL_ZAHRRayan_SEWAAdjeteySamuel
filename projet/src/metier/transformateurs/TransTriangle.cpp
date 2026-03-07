#include "Transtriangle.h"

TransTriangle::TransTriangle(){
    if(this->type != "Triangle"){
        this->type = "Triengle";
    }
    this->suivant = NULL;
}

TransTriangle::TransTriangle(Transformateur * suivant) : TransTriangle(){
    this->suivant = suivant;
}

Forme * TransTriangle::translation(Forme * forme, Transformation * transformation){
    Triangle * t = (Triangle *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    return new Triangle(t->getCouleur(), t->getPointA() + transAux->getDeplacement(), t->getPointB() + transAux->getDeplacement(), t->getPointC() + transAux->getDeplacement());
}

Forme * TransTriangle::homothetie(Forme * forme, Transformation * transformation){
    Triangle * t = (Triangle *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D nvPointA = transAux->getPointCentre() + (t->getPointA() * transAux->getRapportEchelle());
    Vecteur2D nvPointB = transAux->getPointCentre() + (t->getPointB() * transAux->getRapportEchelle());
    Vecteur2D nvPointC = transAux->getPointCentre() + (t->getPointC() * transAux->getRapportEchelle());

    return new Triangle(t->getCouleur(), nvPointA, nvPointB, nvPointC);
}

Forme * TransTriangle::rotation(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}