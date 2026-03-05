#ifndef TRANS_SEGMENT
#define TRANS_SEGMENT

#include "Transformateur.h"
#include "../formes/Segment.h"

class TransSegment : public Transformateur {
    static string type; // TODO : code répétitif

    public:
    /******************** CONSTRUCTEURS ********************/
    TransSegment();
    TransSegment(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    virtual const string getType() const;

    virtual Forme * translation(Forme * forme, Transformation * transformation);
    virtual Forme * homothetie(Forme * forme, Transformation * transformation);
    virtual Forme * rotation(Forme * forme, Transformation * transformation);
};
#endif