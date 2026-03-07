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

    Matrice22 aux = seg->getExtremites();
    return new Segment(seg->getCouleur(), Matrice22(aux + transAux->getDeplacement()));
}

Forme * TransSegment::homothetie(Forme * forme, Transformation * transformation){
    Segment * seg = (Segment *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D distanceA = transAux->getPointCentre().distanceM(seg->getExtremites().ligneHaut);
    Vecteur2D distanceB = transAux->getPointCentre().distanceM(seg->getExtremites().ligneBas);

    Vecteur2D nvPointA = transAux->getPointCentre() + (distanceA * transAux->getRapportEchelle());
    Vecteur2D nvPointB = transAux->getPointCentre() + (distanceB * transAux->getRapportEchelle());
    
    return new Segment(seg->getCouleur(), Matrice22(nvPointA, nvPointB));
}
Forme * TransSegment::rotation(Forme * forme, Transformation * transformation){
    // TODO
}