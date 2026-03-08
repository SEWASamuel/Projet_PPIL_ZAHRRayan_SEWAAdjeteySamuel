#ifndef PARSEUR_FORME_COR_SEGMENT
#define PARSEUR_FORME_COR_SEGMENT

#include "ParseurFormeCOR.h"
#include "../../metier/formes/Segment.h"

class ParseurFormeCORSegment : public ParseurFormeCOR {
    public:
    ParseurFormeCORSegment(ParseurFormeCOR * suivant);

    Forme * parse1(const char * ligne) const;
};

#endif