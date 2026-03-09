#include "TransPolygone.h"

TransPolygone::TransPolygone() : Transformateur(NULL, "polygone") {}

TransPolygone::TransPolygone(Transformateur * suivant) : Transformateur(NULL, "polygone") {}

Forme * TransPolygone::translation(Forme * forme, const Transformation * transformation) const {
    Polygone * p = (Polygone *) forme;
    TransformationTranslation * transAux = (TransformationTranslation *) transformation;

    vector<Vecteur2D> pointsCopie = p->getPoints();

    for(Vecteur2D point : pointsCopie){
        point = point + transAux->getDeplacement();
    }

    return new Polygone(p->getCouleur(), pointsCopie);
}

Forme * TransPolygone::homothetie(Forme * forme, const Transformation * transformation) const {
    Polygone * p = (Polygone *) forme;
    TransformationHomothetie * transAux = (TransformationHomothetie *) transformation;

    vector<Vecteur2D> pointsCopie = p->getPoints();

    for(Vecteur2D point : pointsCopie){
        point = transAux->getPointCentre() + (point * transAux->getRapportEchelle());
    }

    return new Polygone(p->getCouleur(), pointsCopie);
}

Forme * TransPolygone::rotation(Forme * forme, const Transformation * transformation) const{
    Polygone * p = (Polygone *) forme;
    TransformationRotation * transAux = (TransformationRotation *) transformation;

    vector<Vecteur2D> pointsCopie = p->getPoints();

    Matrice22 rotation = Matrice22::creeRotation(transAux->getPointRadian());

    for(Vecteur2D point : pointsCopie){
        point = rotation * point;
    }

    return new Polygone(p->getCouleur(), pointsCopie);
}