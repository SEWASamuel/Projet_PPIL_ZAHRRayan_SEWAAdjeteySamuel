#ifndef FORMAT_TXT
#define FORMAT_TXT

#include "VisiteurForme.h"

#include "../metier/formes/Forme.h"
#include "../metier/formes/Segment.h"
#include "../metier/formes/Cercle.h"
#include "../metier/formes/Triangle.h"
#include "../metier/formes/Forme_comp.h"

class FormatTXT : public VisiteurForme {
    const string visite(const Segment * s) const;
    const string visite(const Cercle * s) const;
    const string visite(const Triangle * s) const;
    const string visite(const Polygone * p) const;
    const string visite(const Forme_comp * fc) const;
};

#endif