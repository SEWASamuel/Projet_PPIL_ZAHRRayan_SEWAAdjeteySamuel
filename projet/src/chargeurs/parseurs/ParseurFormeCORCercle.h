/**
 * @file ParseurFormeCORCercle.h
 * @brief Definition de la classe ParseurFormeCORCercle qui hérite de la classe ParseurFormeCOR qui représente un maillon de la chaine de responsabilité servant à la lectire de différentes formes\n
 * Ce maillon traite un cercle.
 */
#ifndef PARSEUR_FORME_COR_CERCLE
#define PARSEUR_FORME_COR_CERCLE

#include "ParseurFormeCOR.h"
#include "../../metier/formes/Cercle.h"

class ParseurFormeCORCercle : public ParseurFormeCOR {
    public:
    ParseurFormeCORCercle(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif