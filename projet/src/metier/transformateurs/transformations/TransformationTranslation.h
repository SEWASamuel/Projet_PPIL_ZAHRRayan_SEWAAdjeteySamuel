#ifndef TRANSFORMATION_TRANSLATION
#define TRANSFORMATION_TRANSLATION

#include "Transformation.h"
#include "../../elements/Vecteur2D.h"
#include "../../formes/Forme.h"

class TransformationTranslation : public Transformation{
    Vecteur2D deplacement;

    public:
    /******************** CONSTRUCTEURS ********************/
    TransformationTranslation(const Vecteur2D depl) : Transformation(TRANSLATION) {
        this->deplacement = depl;
    }

    /******************** METHODES ********************/
    const Vecteur2D getDeplacement() const { return deplacement; }
    //virtual Forme & transforme();
};
#endif