#include "Transformateur.h"

Transformateur::Transformateur(){}

Transformateur::Transformateur(Transformateur* suivant){
    this->suivant = suivant;
}

Transformateur::Transformateur(Transformateur* suivant, const string type){
    this->suivant = suivant;
    this->type = type;
}

const string Transformateur::getType() const {
    return this->type;
}

const bool Transformateur::memeType(Forme * f) const{
    return this->getType() == f->getType();
}

Forme * Transformateur::transforme(Forme & forme, const Transformation transformation) const {
    // Forme *f;

    // if(this->suivant != NULL){
    //     cout << "le transformateur : " << this->getType() << " passe au suivant" << endl; // test
    //     f = this->suivant->transforme(forme, transformation);
    // } else {
    //     cout << "le transformateur : " << this->getType() << " retourne null" << endl;
    //     return NULL;
    // }

    // if(f != NULL){
    //     return f;
    // } else {
    //     //int numTrans = transformation.getNumTransformation();
    //     switch (transformation.getNumTransformation())
    //     {
    //     case TRANSLATION:
    //         cout << "le transformateur : " << this->getType() << " tente une translation" << endl;
    //         return this->translation(&forme, &transformation);
    //         break;
    //     case HOMOTHETIE:
    //         cout << "le transformateur : " << this->getType() << " tente une homothetie" << endl;
    //         return this->homothetie(&forme, &transformation);
    //         break;
    //     case ROTATION:
    //         cout << "le transformateur : " << this->getType() << " tente une rotation" << endl;
    //         return this->rotation(&forme, &transformation);
    //         break;
    //     default:
    //         throw Erreur("Code de transformation invalide");
    //         break;
    //     }
    // }

    /*
    je passe le bail au prochain
    il me renvoie un truc

    si le bail est nul 
        si j'arrive a le traiter
            je le traite
        sinon 
            je lui fais rien
    je renvoie le bail
    */

    Forme * fr = NULL;

    if(this->suivant != NULL){
        //cout << "le transformateur : " << this->getType() << " passe au suivant" << endl; //test
        fr = this->suivant->transforme(forme, transformation);
    }

    if(fr == NULL){
        if(this->memeType(&forme)){
            switch (transformation.getNumTransformation()){
                case TRANSLATION:
                    //cout << "le transformateur : " << this->getType() << " tente une translation" << endl; //test
                    fr =  this->translation(&forme, &transformation);
                    break;
                case HOMOTHETIE:
                    //cout << "le transformateur : " << this->getType() << " tente une homothetie" << endl; //test
                    fr = this->homothetie(&forme, &transformation);
                    break;
                case ROTATION:
                    //cout << "le transformateur : " << this->getType() << " tente une rotation" << endl; //test
                    fr = this->rotation(&forme, &transformation);
                    break;
                default:
                    throw Erreur("Code de transformation invalide");
                    break;
            }
            //if(fr != NULL) cout << "le transformateur : " << this->getType() << " a reussi sa transformation" << endl; //test
        } else {
            //cout << "le transformateur : " << this->getType() << " n'est pas du bon type" << endl; //test
        }
    }

    return fr;
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