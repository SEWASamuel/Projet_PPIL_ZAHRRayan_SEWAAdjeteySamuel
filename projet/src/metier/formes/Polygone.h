#ifndef POLYGONE_H
#define POLYGONE_H

#include "Forme.h"
#include "../elements/Vecteur2D.h"
#include <vector>

/*
    Classe Polygone

    Un polygone est une forme définie par plusieurs sommets (points).
    et les sommets sont stockés dans un vecteur de Vecteur2D.
*/

class Polygone : public Forme {

private:

    // liste des sommets du polygone
    std::vector<Vecteur2D> sommets;

public:

    /******************** CONSTRUCTEURS ********************/

    // constructeur par défaut
    Polygone();

    // constructeur avec une liste de points et une couleur
    Polygone(const std::vector<Vecteur2D>& points, int couleur);

    /******************** METHODES ********************/

    // retourne un sommet du polygone
    Vecteur2D getSommet(int index) const;

    // retourne le nombre de sommets
    int getNbSommets() const;

    // ajoute un sommet au polygone
    void ajouterSommet(const Vecteur2D& point);

    // redéfinition de l'affichage de la classe Forme
    void afficher() const override;

    // calcul de l'aire du polygone
    double calculerAire() const override;
};

#endif