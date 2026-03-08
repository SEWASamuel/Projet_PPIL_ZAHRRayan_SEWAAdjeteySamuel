#include "TransPolygone.h"

TransPolygone::TransPolygone() : Transformateur(NULL, "polygone") {}

TransPolygone::TransPolygone(Transformateur * suivant) : Transformateur(NULL, "polygone") {}

Forme * TransPolygone::translation(Forme * forme, const Transformation * transformation) const {
    // TODO
    return NULL;
}

Forme * TransPolygone::homothetie(Forme * forme, const Transformation * transformation) const {
    // TODO
    return NULL;
}

Forme * TransPolygone::rotation(Forme * forme, const Transformation * transformation) const{
    // TODO
    return NULL;
}