/**
 * Classe abtstraite représentant un noeud de la chaine de responsabilité servant aux diverses transformations
 */

#ifndef TRANSFORMATEUR
#define TRANSFORMATEUR

#include <string>
#include "OpTrans.h"
#include "transformations/TransformationTranslation.h"
#include "transformations/TransformationHomothetie.h"
#include "transformations/TransformationRotation.h"

#include "../elements/Matrice22.h"
#include "../formes/Forme.h"

class Transformateur : public OpTrans{
    protected:
    Transformateur * suivant;

    public:
    /******************** CONSTRUCTEURS ********************/
    Transformateur(){}
    Transformateur(Transformateur * suivant);

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    virtual const string getType() const;

    const bool memeType(Forme * f) const;

    Forme * transforme(Forme * forme, const Transformation transformation);

    // virtual Forme & transforme(Forme & forme, const TransformationTranslation t);
    // virtual Forme & transforme(Forme & forme, const TransformationHomothetie t);
    // virtual Forme & transforme(Forme & forme, const TransformationRotation t);

    virtual Forme * translation(Forme * forme, Transformation transformation) = 0;
    virtual Forme * homothetie(Forme * forme, Transformation transformation) = 0;
    virtual Forme * rotation(Forme * forme, Transformation transformation) = 0;
};
#endif