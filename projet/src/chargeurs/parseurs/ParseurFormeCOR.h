#ifndef PARSEUR_FORME_COR
#define PARSEUR_FORME_COR

#include "ParseurForme.h"
#include "../../metier/formes/Forme.h"

#include <stdio.h>

class ParseurFormeCOR : public ParseurForme {
    ParseurFormeCOR * suivant;

    public:
    ParseurFormeCOR(ParseurFormeCOR * suivant);

    Forme * parse(const char * ligne) const;
    
    virtual Forme * parse1(const char * ligne) const = 0;
};

#endif