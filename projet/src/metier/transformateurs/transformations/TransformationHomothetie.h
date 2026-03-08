#ifndef TRANSFORMATION_HOMOTHETIE
#define TRANSFORMATION_HOMOTHETIE

#include "Transformation.h"
#include "../../elements/Vecteur2D.h"
#include "../../formes/Forme.h"

class TransformationHomothetie : public Transformation{
    Vecteur2D pointCentre;
    double rapportEchelle;

    public:
    /******************** CONSTRUCTEURS ********************/
    TransformationHomothetie(const Vecteur2D point, const double echelle) : Transformation(HOMOTHETIE) {
        this->pointCentre = point;
        this->rapportEchelle = echelle;
    }

    /******************** METHODES ********************/
    const Vecteur2D getPointCentre() const { return this->pointCentre; }
    const double getRapportEchelle() const { return this->rapportEchelle; }
    //virtual Forme & transforme();
};
#endif