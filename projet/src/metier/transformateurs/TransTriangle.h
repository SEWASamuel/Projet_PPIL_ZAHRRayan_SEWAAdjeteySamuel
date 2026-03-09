/**
 * @file TransTriangle.h
 * @brief Definition de la classe TransTriangle qui représente un maillon de la chaine de responsabilité pour la transformation de formes.
 * Ce maillon traite un triangle.
 */
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