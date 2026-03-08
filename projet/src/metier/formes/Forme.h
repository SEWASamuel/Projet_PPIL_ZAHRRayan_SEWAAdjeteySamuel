#ifndef FORME
#define FORME

#define COULEUR_NOIR 0
#define COULEUR_BLEU 1
#define COULEUR_ROUGE 2
#define COULEUR_VERT 3
#define COULEUR_JAUNE 4
#define COULEUR_CYAN 5
#define NB_COULEURS 6

#include <ostream>
#include <string>
#include "../exceptions/Erreur.h"
#include "../elements/Vecteur2D.h"

using namespace std;

class Forme{
    protected:
    int couleur;
    string type = "Forme"; // cet attribut est à initialiser différemment dans les consrtucteure de chaque forme

    public:
    /******************** CONSTRUCTEURS ********************/
    Forme();
    Forme(int codeCouleur);

    /******************** METHODES ********************/
    const int getCouleur() const;
    const string getType() const;

    void setCouleur(const int couleur);
    void setType(const string nomType);

    static const char * intToCouleur(const int couleur);
    const string getDebutOSS() const;
    virtual operator string() const = 0;

    virtual Forme * translation(const Vecteur2D deplacement) const = 0;
    virtual Forme * homothetie(const Vecteur2D centre, const double rapportEchelle) const = 0;
    virtual Forme * rotation(const Vecteur2D pointInvariant, const double angleRadian) const = 0;
};
ostream & operator <<(ostream os, const Forme * f);

#endif