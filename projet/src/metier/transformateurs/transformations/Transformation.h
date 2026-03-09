/**
 * @file Transformation.h
 * @brief Definition de la classe abstraite Transformation qui sert à représenter une transformation pour une forme.
 */
#ifndef TRANSFORMATION
#define TRANSFORMATION

#define TRANSLATION 1
#define HOMOTHETIE 2
#define ROTATION 3


class Transformation{
    int numTransformation;
    public:

    Transformation(const int numTransformation): numTransformation(numTransformation) {}

    /******************** METHODES ********************/
    const int getNumTransformation() const { return this->numTransformation; }
    //virtual Forme & transforme();
};
#endif