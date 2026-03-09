/**
 * @file TransSegment.h
 * @brief Definition de la classe TransSegment qui représente un maillon de la chaine de responsabilité pour la transformation de formes.
 * Ce maillon traite un segment.
 */
#ifndef TRANS_SEGMENT
#define TRANS_SEGMENT

#include "Transformateur.h"
#include "../formes/Segment.h"

class TransSegment : public Transformateur {

    public:
    /******************** CONSTRUCTEURS ********************/
    TransSegment();
    TransSegment(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    Forme * translation(Forme * forme, const Transformation * transformation) const ;
    Forme * homothetie(Forme * forme, const Transformation * transformation) const ;
    Forme * rotation(Forme * forme, const Transformation * transformation) const ;
};
#endif