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

using namespace std;

class Forme{
    protected:
    int couleur = COULEUR_NOIR;
    string type = ""; // cet attribut est à initialiser différemment dans les consrtucteure de chaque forme

    public:
    /******************** CONSTRUCTEURS ********************/
    Forme();
    Forme(int codeCouleur);

    /******************** METHODES ********************/
    const int getCouleur() const;
    const string getType() const;

    void setCouleur(const int couleur);
    void setType(const string nomType);
};

#endif