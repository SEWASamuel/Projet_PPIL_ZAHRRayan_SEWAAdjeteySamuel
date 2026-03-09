#ifndef VISITEUR_FORME
#define VISITEUR_FORME

#include <string>

class Forme;
class Segment;
class Cercle;
class Triangle;
class Polygone;
class Forme_comp;

class VisiteurForme {
    public:
    virtual const string visite(const Segment * s) const = 0;
    virtual const string visite(const Cercle * s) const = 0;
    virtual const string visite(const Triangle * s) const = 0;
    virtual const string visite(const Polygone * p) const = 0;
    virtual const string visite(const Forme_comp * fc) const = 0;
};

#endif