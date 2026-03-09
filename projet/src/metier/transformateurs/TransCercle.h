/**
 * @file Transcercle.h
 * @brief Definition de la classe TransCercle qui représente un maillon de la chaine de responsabilité pour la transformation de formes.
 * Ce maillon traite un cercle.
 */
#ifndef TRANS_CERCLE
#define TRANS_CERCLE

#include "Transformateur.h" 
#include "../formes/Cercle.h"

class TransCercle : public Transformateur {

    public:
    /******************** CONSTRUCTEURS ********************/
    TransCercle();
    TransCercle(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    Forme * translation(Forme * forme, const Transformation * transformation) const;
    Forme * homothetie(Forme * forme, const Transformation * transformation) const;
    Forme * rotation(Forme * forme,  const Transformation * transformation) const;
};
#endif