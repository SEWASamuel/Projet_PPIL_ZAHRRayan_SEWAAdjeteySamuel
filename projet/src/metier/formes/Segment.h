#ifndef SEGMENT_H
#define SEGMENT_H

#include "Forme.h"
#include "../elements/Vecteur2D.h"

class Segment : public Forme {

private:

    // Un segment est défini par deux points
    Vecteur2D A;
    Vecteur2D B;

public:

    /******************** CONSTRUCTEURS ********************/

    Segment();
    Segment(const Vecteur2D& A, const Vecteur2D& B, int couleur);

    /******************** METHODES ********************/

    Vecteur2D getA() const;
    Vecteur2D getB() const;

    void setA(const Vecteur2D& A);
    void setB(const Vecteur2D& B);

    void afficher() const override;

    double calculerAire() const override;
};

#endif