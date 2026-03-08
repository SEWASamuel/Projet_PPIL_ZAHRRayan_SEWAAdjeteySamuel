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