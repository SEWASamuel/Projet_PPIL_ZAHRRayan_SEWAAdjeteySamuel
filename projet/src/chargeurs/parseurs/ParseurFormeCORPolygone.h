/**
 * @file ParseurFormeCORPolygone.h
 * @brief Definition de la classe ParseurFormeCORPolygone qui hérite de la classe ParseurFormeCCOR qui représente un maillon de la chaine de responsabilité servant à la lectire de différentes formes\n
 * Ce maillon traite un polygone.
 */
#ifndef PARSEUR_FORME_COR_POLYGONE
#define PARSEUR_FORME_COR_POLYGONE

#include "ParseurFormeCOR.h"
#include "../../metier/formes/Polygone.h"

class ParseurFormeCORPolygone : public ParseurFormeCOR {
    public:
    ParseurFormeCORPolygone(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif