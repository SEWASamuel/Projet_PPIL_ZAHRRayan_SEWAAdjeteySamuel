#ifndef TRANSFORMATION_ROTATION
#define TRANSFORMATION_ROTATION

#include "Transformation.h"
#include "../../elements/Vecteur2D.h"
#include "../../formes/Forme.h"
#include "../../exceptions/Erreur.h"

class TransformationRotation : public Transformation{
    Vecteur2D pointInvariant;
    double angleRadian;

    public:
    /******************** CONSTRUCTEURS ********************/
    TransformationRotation(const Vecteur2D point, const double radian) : Transformation(ROTATION) {
        if(radian < 0 || radian > 2){
            throw Erreur("Radian invalide");
        }
        this->pointInvariant = point;
        this->angleRadian = radian;
    }

    /******************** METHODES ********************/
    const Vecteur2D getPointInvariant() const { return this->pointInvariant; }
    const double getPointRadian() const { return this->angleRadian; }
    //virtual Forme & transforme();
};
#endif