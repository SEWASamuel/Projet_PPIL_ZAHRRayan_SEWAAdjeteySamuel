#ifndef PARSEUR_FORME_COR_POLYNOME
#define PARSEUR_FORME_COR_POLYNOME

#include "ParseurFormeCOR.h"

class ParseurFormeCORPolynome : public ParseurFormeCOR {
    public:
    ParseurFormeCORPolynome(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif