#ifndef SEGMENT
#define SEGMENT

#include "Forme.h"
#include "../elements/Vecteur2D.h"
#include "../elements/Matrice22.h" 

class Segment: public Forme {
    Matrice22 extremites;

    public:
    /******************** CONSTRUCTEURS ********************/
    Segment();
    Segment(const int couleur, const Matrice22 matrice);

    /******************** METHODES ********************/
    const Matrice22 getExtremites() const ;

    void setExremites(const Matrice22 vecteur);
    void setExtremites(const Vecteur2D a, const Vecteur2D b);

    virtual operator string() const;
};

ostream & operator <<(ostream & os, const Segment s);
#endif