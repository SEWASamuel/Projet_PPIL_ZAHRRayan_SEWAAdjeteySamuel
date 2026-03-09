/**
 * Interface pour les transformations sur les formes
 * Ici, on déclare les différentes fonctions qui vont servir aux transformations
 */

#ifndef OP_TRANS
#define OP_TRANS

#include "../formes/Forme.h"
#include "transformations/Transformation.h"

class OpTrans {
    public:
    /******************** METHODES ********************/
    virtual Forme * transforme(Forme & forme, const Transformation * transformation) const = 0;
};

#endif