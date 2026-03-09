/**
 * @file ParseurFormeCORTriangle.h
 * @brief Definition de la classe ParseurFormeCORCercle qui hérite de la classe ParseurFormeCOR qui représente un maillon de la chaine de responsabilité servant à la lectire de différentes formes\n
 * Ce maillon traite un Traingle.
 */
#ifndef PARSEUR_FORME_COR_TRIANGLE
#define PARSEUR_FORME_COR_TRIANGLE

#include "ParseurFormeCOR.h"
#include "../../metier/formes/Triangle.h"

class ParseurFormeCORTriangle : public ParseurFormeCOR {
    public:
    ParseurFormeCORTriangle(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif