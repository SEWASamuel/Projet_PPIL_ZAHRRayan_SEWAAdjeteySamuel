#include "TransSegment.h"

TransSegment::TransSegment(){
    if(this->type != "Segment"){
        this->type = "Segment";
    }
    this->suivant = NULL;
}

TransSegment::TransSegment(Transformateur * suivant) : TransSegment(){
    this->suivant = suivant;
}

Forme * TransSegment::translation(Forme * forme, Transformation * transformation){
    Segment * seg = (Segment *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    return new Segment(seg->getCouleur(), Vecteur2D(seg->getExtremites() + transAux->getDeplacement()));
}

Forme * TransSegment::homothetie(Forme * forme, Transformation * transformation){
    // TODO
}
Forme * TransSegment::rotation(Forme * forme, Transformation * transformation){
    // TODO
}