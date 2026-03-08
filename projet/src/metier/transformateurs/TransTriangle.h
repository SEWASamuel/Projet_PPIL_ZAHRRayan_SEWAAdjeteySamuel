#ifndef TRANS_TRIANGLE
#define TRANS_TRIANGLE

#include "Transformateur.h"
#include "../formes/Triangle.h"

class TransTriangle : public Transformateur {

    public:
    /******************** CONSTRUCTEURS ********************/
    TransTriangle();
    TransTriangle(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    Forme * translation(Forme * forme, const Transformation * transformation) const ;
    Forme * homothetie(Forme * forme, const Transformation * transformation) const ;
    Forme * rotation(Forme * forme, const Transformation * transformation) const ;
};
#endif