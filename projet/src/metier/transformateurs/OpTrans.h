/**
 * @file OpTrans.h
 * @brief Interface servant à la mise en place d'une chaine de responsabilité pour transformer différentes formes
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