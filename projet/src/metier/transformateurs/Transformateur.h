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
    Transformateur * suivant;
    string type = "transformateur";

    public:
    /******************** CONSTRUCTEURS ********************/
    Transformateur();
    Transformateur(Transformateur * suivant);

    protected:
    Transformateur(Transformateur * suivant, const string type);

    public:

    /******************** METHODES ********************/
    // virtual Forme & transforme(Forme & forme);

    const string getType() const;

    const bool memeType(Forme * f) const;

    Forme * transforme(Forme & forme, const Transformation transformation) const;

    // virtual Forme & transforme(Forme & forme, const TransformationTranslation t);
    // virtual Forme & transforme(Forme & forme, const TransformationHomothetie t);
    // virtual Forme & transforme(Forme & forme, const TransformationRotation t);

    virtual Forme * translation(Forme * forme, const Transformation * transformation) const = 0;
    virtual Forme * homothetie(Forme * forme, const Transformation * transformation) const = 0;
    virtual Forme * rotation(Forme * forme, const Transformation * transformation) const = 0;
};
#endif