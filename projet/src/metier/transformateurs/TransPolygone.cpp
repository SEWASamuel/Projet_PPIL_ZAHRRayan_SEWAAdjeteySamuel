#include "TransPolygone.h"

TransPolygone::TransPolygone(){
    if(this->type != "Polygone"){
        this->type = "Polygone";
    }
    this->suivant = NULL;
}

TransPolygone::TransPolygone(Transformateur * suivant) : TransPolygone(){
    this->suivant = suivant;
}

Forme * TransPolygone::translation(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}

Forme * TransPolygone(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}

Forme * TransPolygone(Forme * forme, Transformation * transformation){
    // TODO
    return NULL;
}