/**
 * @file TransCercle.h
 * @brief Definition des fonctions de la classe TransCercle
 */
#include "TransCercle.h"

TransCercle::TransCercle() : Transformateur(NULL, "cercle") {}

TransCercle::TransCercle(Transformateur * suivant) : Transformateur(suivant, "cercle") {}

Forme * TransCercle::translation(Forme * forme, const Transformation * transformation) const {
    Cercle * c = (Cercle *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    return new Cercle(c->getCouleur(), c->getCentre() + transAux->getDeplacement(), c->getRayon());
}
Forme * TransCercle::homothetie(Forme * forme, const Transformation * transformation) const {
    Cercle * c = (Cercle *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D distanceCentres = transAux->getPointCentre().distanceM(c->getCentre());
    
    Vecteur2D nVcentre = transAux->getPointCentre() + (distanceCentres * transAux->getRapportEchelle());
    double nvRayon = abs(c->getRayon() * transAux->getRapportEchelle());
    
    return new Cercle(c->getCouleur(), nVcentre, nvRayon);
}
Forme * TransCercle::rotation(Forme * forme, const Transformation * transformation) const {
    Cercle * c = (Cercle *) forme;
    TransformationRotation * transAux = (TransformationRotation *) transformation;

    Matrice22 rotation = Matrice22::creeRotation(transAux->getPointRadian());
    Vecteur2D centre = c->getCentre();

    Vecteur2D nvCentre = rotation * centre;

    return new Cercle(c->getCouleur(), nvCentre, c->getRayon());
}