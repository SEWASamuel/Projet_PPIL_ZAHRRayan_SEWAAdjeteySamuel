#ifndef PARSEUR_FORME
#define PARSEUR_FORME

#include "../../metier/formes/Forme.h"

class ParseurForme {
    public:
    virtual Forme * parse(const char * ligne) const = 0;
};

#endif