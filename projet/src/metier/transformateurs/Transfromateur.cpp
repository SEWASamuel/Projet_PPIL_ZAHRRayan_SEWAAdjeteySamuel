#include "Transformateur.h"
#include "Erreur.h"

Transformateur::Transformateur(){}

Transformateur::Transformateur(Transformateur* suivant){
    this->suivant = suivant;
}

const bool Transformateur::memeType(Forme * f) const{
    return this->getType() == f->getType();
}

Forme * Transformateur::transforme(Forme * forme, const Transformation transformation){
    Forme *f;

    if(this->suivant != NULL){
        f = this->suivant->transforme(f, transformation);
    } else {
        return NULL;
    }

    if(f != NULL){
        return f;
    } else {
        int numTrans = transformation.getNumTransformation();
        switch (numTrans)
        {
        case 1:
            return this->translation(forme, transformation);
            break;
        case 2:
            return this->homothetie(forme, transformation);
            break;
        case 3:
            return this->rotation(forme, transformation);
            break;
        default:
            throw Erreur("Code de transformation invalide");
            break;
        }
    }
}

// Forme & Transformateur::transforme(Forme & forme, const TransformationTranslation){
//     // TODO
// }

// Forme & Transformateur::transforme(Forme & forme, const TransformationHomothetie){
//     // TODO
// }

// Forme & Transformateur::transforme(Forme & forme, const TransformationRotation){
//     // TODO
// }

// Forme * Transformateur::translation(Forme * forme, Transformation transformation){
//     // TODO
// }
// Forme * Transformateur::homothetie(Forme * forme, Transformation transformation){
//     // TODO
// }
// Forme * Transformateur::rotation(Forme * forme, Transformation transformation){
//     // TODO
// }