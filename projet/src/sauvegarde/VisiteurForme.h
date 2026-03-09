#ifndef VISITEUR_FORME
#define VISITEUR_FORME

#include "../metier/formes/Forme.h"
#include "../metier/formes/Segment.h"
#include "../metier/formes/Cercle.h"
#include "../metier/formes/Triangle.h"
#include "../metier/formes/Polygone.h"

class VisiteurForme {
    public:
    virtual void visite(const Segment s) const = 0;
    virtual void visite(const Cercle s) const = 0;
    virtual void visite(const Triangle s) const = 0;
    virtual void visite(const Polygone p) const = 0;
};

#endif