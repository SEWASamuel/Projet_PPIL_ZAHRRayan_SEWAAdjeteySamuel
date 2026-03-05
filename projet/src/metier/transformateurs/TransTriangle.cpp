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

Forme * homothetie(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}

Forme * rotation(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}