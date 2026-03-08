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