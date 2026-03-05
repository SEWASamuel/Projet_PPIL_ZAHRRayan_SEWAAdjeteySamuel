#ifndef TRANS_TRIANGLE
#define TRANS_TRIANGLE

#include "Transformateur.h"
#include "../formes/Triangle.h"

class TransTriangle : public Transformateur {
    static string type; // TODO : code répétitifpublic:

    public:
    /******************** CONSTRUCTEURS ********************/
    TransTriangle();
    TransTriangle(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    virtual const string getType() const;

    virtual Forme * translation(Forme * forme, Transformation * transformation);
    virtual Forme * homothetie(Forme * forme, Transformation * transformation);
    virtual Forme * rotation(Forme * forme, Transformation * transformation);
};
#endif