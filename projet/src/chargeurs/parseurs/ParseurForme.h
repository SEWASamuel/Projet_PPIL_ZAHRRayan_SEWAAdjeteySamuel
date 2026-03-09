/**
 * @file ParseurForme.h
 * @brief Definition de la classe interface ParseurForme qui servira aux maillons de la chaine de responsabilité servant à la lecture de différentes formes. 
 */
#ifndef PARSEUR_FORME
#define PARSEUR_FORME

#include "../../metier/formes/Forme.h"

class ParseurForme {
    public:
    virtual Forme * parse(const char * ligne) const = 0;
};

#endif