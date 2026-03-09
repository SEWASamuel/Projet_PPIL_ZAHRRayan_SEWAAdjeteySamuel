#ifndef VISITEUR_FORME
#define VISITEUR_FORME

#include "../metier/formes/Forme.h"
#include "../metier/formes/Segment.h"
#include "../metier/formes/Cercle.h"
#include "../metier/formes/Triangle.h"
#include "../metier/formes/Polygone.h"
#include "../metier/formes/Forme_comp.h" 

class VisiteurForme {
    public:
    virtual const string visite(const Segment * s) const = 0;
    virtual const string visite(const Cercle * s) const = 0;
    virtual const string visite(const Triangle * s) const = 0;
    virtual const string visite(const Polygone * p) const = 0;
    virtual const string visite(const Forme_comp * fc) const = 0;
};

#endif