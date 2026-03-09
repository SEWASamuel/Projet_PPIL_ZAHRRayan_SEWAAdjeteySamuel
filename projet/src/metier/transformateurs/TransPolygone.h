#ifndef TRANS_POLYGONE
#define TRANS_POLYGONE

#include "Transformateur.h"
#include "../formes/Polygone.h"

class TransPolygone : public Transformateur {

    public:
    /******************** CONSTRUCTEURS ********************/
    TransPolygone();
    TransPolygone(Transformateur * suivant);

    /******************** METHODES ********************/
    //virtual Forme & transforme(Forme & forme);

    Forme * translation(Forme * forme, const Transformation * transformation) const ;
    Forme * homothetie(Forme * forme, const Transformation * transformation) const ;
    Forme * rotation(Forme * forme, const Transformation * transformation) const ;
};
#endif