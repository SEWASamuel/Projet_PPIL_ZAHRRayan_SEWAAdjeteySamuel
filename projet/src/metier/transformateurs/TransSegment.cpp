/**
 * @file TransSegment.h
 * @brief Definition des fonctions de la classe TransSegment
 */
#include "TransSegment.h"

TransSegment::TransSegment() : Transformateur(NULL, "segment") {}

TransSegment::TransSegment(Transformateur * suivant) : Transformateur(suivant, "segment") {}

Forme * TransSegment::translation(Forme * forme, const Transformation * transformation) const {
    Segment * seg = (Segment *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    Matrice22 aux = seg->getExtremites();
    Matrice22 nvM = aux + transAux->getDeplacement();

    return new Segment(seg->getCouleur(), nvM);
}

Forme * TransSegment::homothetie(Forme * forme, const Transformation * transformation) const {
    Segment * seg = (Segment *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D distanceA = transAux->getPointCentre().distanceM(seg->getExtremites().ligneHaut);
    Vecteur2D distanceB = transAux->getPointCentre().distanceM(seg->getExtremites().ligneBas);

    Vecteur2D nvPointA = transAux->getPointCentre() + (distanceA * transAux->getRapportEchelle());
    Vecteur2D nvPointB = transAux->getPointCentre() + (distanceB * transAux->getRapportEchelle());
    
    return new Segment(seg->getCouleur(), Matrice22(nvPointA, nvPointB));
}
Forme * TransSegment::rotation(Forme * forme, const Transformation * transformation) const {
    Segment * seg = (Segment *) forme;
    TransformationRotation * transAux = (TransformationRotation *) transformation;

    Matrice22 rotation = Matrice22::creeRotation(transAux->getPointRadian());
    Vecteur2D pointA = seg->getExtremites().ligneHaut;
    Vecteur2D pointB = seg->getExtremites().ligneBas;

    Vecteur2D nvPointA = rotation * pointA;
    Vecteur2D nvPointB = rotation * pointB;

    return new Segment(seg->getCouleur(), Matrice22(nvPointA, nvPointB));
}