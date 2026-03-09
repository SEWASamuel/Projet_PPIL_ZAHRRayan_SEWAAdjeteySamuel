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