#ifndef TRANS_POLYGONE
#define TRANS_POLYGONE

#include "Transformateur.h"

class TransPolygone : public Transformateur {
    static string type; // TODO : code répétitif

    public:
    /******************** CONSTRUCTEURS ********************/
    TransPolygone();
    TransPolygone(Transformateur * suivant);

    /******************** METHODES ********************/
    //virtual Forme & transforme(Forme & forme);

    virtual const string getType() const;

    virtual Forme * translation(Forme * forme, Transformation * transformation);
    virtual Forme * homothetie(Forme * forme, Transformation * transformation);
    virtual Forme * rotation(Forme * forme, Transformation * transformation);
};
#endif