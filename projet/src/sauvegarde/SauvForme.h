#ifndef SAUV_FORME
#define SAUV_FORME

#include "VisiteurForme.h"

class SauvForme{
    public:
    virtual const string accepte(VisiteurForme & v) const = 0;
};

class SauvSegment : public SauvForme {
    Segment s;
    public:

    SauvSegment(Segment s) : s(s) {}

    const string accepte(VisiteurForme & v) const {
        return v.visite(this->s);
    }
};

class SauvCercle : public SauvForme {
    Cercle c;
    public:

    SauvCercle(Cercle c) : c(c) {}

    const string accepte(VisiteurForme & v) const {
        return v.visite(this->c);
    }
};

class SauvTriangle : public SauvForme {
    Triangle t;
    public:

    SauvTriangle(Triangle t) : t(t) {}

    const string accepte(VisiteurForme & v) const {
        return v.visite(this->t);
    }
};


class SauvPolygone : public SauvForme {
    Polygone p;
    public:

    SauvPolygone(Polygone p) : p(p) {}

    const string accepte(VisiteurForme & v) const {
        return v.visite(this->p);
    }
};

class SauveForme_comp : public SauvForme {
    Forme_comp fc;
    public:

    SauveForme_comp(Forme_comp fc) : fc(fc) {}

    const string accepte(VisiteurForme & v) const {
        return v.visite(this->fc);
    }
};

#endif