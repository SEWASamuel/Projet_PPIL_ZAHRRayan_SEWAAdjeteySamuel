#ifndef FORME_COMP_H
#define FORME_COMP_H

#include <vector>
#include <memory>
#include "Forme.h"
// Classe représentant une forme composée (groupe de formes)
// Une Forme_comp est elle-même une Forme et peut contenir plusieurs formes  simples ou composées.


class Forme_comp : public Forme {
private:
// chaque element est un pointeur vers une forme (simple ou composée) 
    std::vector<Forme*> formes;

public:

    /******************** CONSTRUCTEURS ********************/


// Constructeur par défaut : crée une forme composée avec la couleur par défaut
    Forme_comp();
        // Constructeur avec couleur : permet de créer une forme composée avec une couleur donnée
    Forme_comp(int couleur);
    // destructeur : libère la mémoire allouée pour les formes contenues dans la forme composée
    virtual ~Forme_comp();

    // Ajoute une forme dans la forme composée
    void addForme(Forme* forme);

    // Supprime une forme du vecteur à l'index donné
    void delForme(int index);
    
    // Retourne la forme située à l'index donné (const car ne modifie pas l'objet)
    Forme* getForme(int index) const;
     // Retourne le nombre de formes contenues dans la forme composée
    int getNbFormes() const;

    // Affiche les informations de la forme composée override car cela redefini la methode afficher de la classe mere "Forme"
    void afficher() const override;

    //l'aire de la somme de toutes les formes contenues dans la forme composée 
    double calculerAire() const override;
};


#endif