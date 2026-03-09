#ifndef FORME_COMP_H
#define FORME_COMP_H

#include <vector>
#include <memory>
#include "Forme.h"

class Forme_comp : public Forme {
private:
    std::vector<Forme*> formes;

public:
    Forme_comp();
    Forme_comp(int couleur);
    /* virtual */ ~Forme_comp();

    void addForme(Forme* forme);
    void delForme(int index);
    Forme* getForme(int index) const;
    int getNbFormes() const;
    
    void dessiner() const;
    double calculerAire() const;
    operator string() const;

    //const string accepte(VisiteurForme * v) const;
};

#endif