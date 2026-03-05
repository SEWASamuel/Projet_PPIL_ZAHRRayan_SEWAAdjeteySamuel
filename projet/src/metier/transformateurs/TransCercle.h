#ifndef TRANS_CERCLE
#define TRANS_CERCLE

#include "Transformateur.h" 
#include "../formes/Cercle.h"

class TransCercle : public Transformateur {
    static string type; // TODO : code répétitif

    public:
    /******************** CONSTRUCTEURS ********************/
    TransCercle();
    TransCercle(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    virtual const string getType() const;

    virtual Forme * translation(Forme * forme, Transformation * transformation);
    virtual Forme * homothetie(Forme * forme, Transformation * transformation);
    virtual Forme * rotation(Forme * forme, Transformation * transformation);
};
#endif