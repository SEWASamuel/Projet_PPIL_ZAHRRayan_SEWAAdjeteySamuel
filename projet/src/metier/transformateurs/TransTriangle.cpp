#include "Transtriangle.h"

TransTriangle::TransTriangle() : Transformateur(NULL, "triangle") {}

TransTriangle::TransTriangle(Transformateur * suivant) : Transformateur(suivant, "triangle") {}

Forme * TransTriangle::translation(Forme * forme, const Transformation * transformation) const {
    Triangle * t = (Triangle *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    return new Triangle(t->getCouleur(), t->getPointA() + transAux->getDeplacement(), t->getPointB() + transAux->getDeplacement(), t->getPointC() + transAux->getDeplacement());
}

Forme * TransTriangle::homothetie(Forme * forme, const Transformation * transformation) const {
    Triangle * t = (Triangle *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    Vecteur2D nvPointA = transAux->getPointCentre() + (t->getPointA() * transAux->getRapportEchelle());
    Vecteur2D nvPointB = transAux->getPointCentre() + (t->getPointB() * transAux->getRapportEchelle());
    Vecteur2D nvPointC = transAux->getPointCentre() + (t->getPointC() * transAux->getRapportEchelle());

    return new Triangle(t->getCouleur(), nvPointA, nvPointB, nvPointC);
}

Forme * TransTriangle::rotation(Forme * forme, const Transformation * transformation) const {
    Triangle * tr = (Triangle *) forme;
    TransformationRotation * transAux = (TransformationRotation *) transformation;

    Matrice22 rotation = Matrice22::creeRotation(transAux->getPointRadian());
    Vecteur2D pointA = tr->getPointA();
    Vecteur2D pointB = tr->getPointB();
    Vecteur2D pointC = tr->getPointC();

    Vecteur2D nvPointA = rotation * pointA;
    Vecteur2D nvPointB = rotation * pointB;
    Vecteur2D nvPointC = rotation * pointC;

    return new Triangle(tr->getCouleur(), nvPointA, nvPointB, nvPointC);
}