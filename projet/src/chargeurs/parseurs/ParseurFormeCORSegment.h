/**
 * @file ParseurFormeCORSegment.h
 * @brief Definition de la classe ParseurFormeCORCercle qui hérite de la classe ParseurFormeCOR qui représente un maillon de la chaine de responsabilité servant à la lectire de différentes formes\n
 * Ce maillon traite un Segment.
 */
#ifndef PARSEUR_FORME_COR_SEGMENT
#define PARSEUR_FORME_COR_SEGMENT

#include "ParseurFormeCOR.h"
#include "../../metier/formes/Segment.h"

class ParseurFormeCORSegment : public ParseurFormeCOR {
    public:
    ParseurFormeCORSegment(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif