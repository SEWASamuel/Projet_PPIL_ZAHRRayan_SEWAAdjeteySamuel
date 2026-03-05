#ifndef TRANSFORMATION
#define TRANSFORMATION

#define TRANSLATION 1
#define HOMOTHETIE 2
#define ROTATION 3


class Transformation{
    protected:
    int numTransformation;
    public:

    /******************** METHODES ********************/
    const int getNumTransformation() const { return this->numTransformation; }
    virtual Forme & transforme();
};
#endif