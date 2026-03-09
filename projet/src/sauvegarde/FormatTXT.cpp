#include "FormatTXT.h"

const string pointToString(const Vecteur2D & point){
    ostringstream oss;

    oss << "(" << point.x << ", " << point.y << ")";

    return oss.str();
}

const string FormatTXT::visite(const Segment * s) const {
    Segment sAux = *s;
    ostringstream oss;

    oss << sAux.getCouleurString() << " ";

    oss << pointToString(sAux.getExtremites().ligneHaut);
    oss << " " << pointToString(sAux.getExtremites().ligneBas);

    return oss.str();
}

const string FormatTXT::visite(const Cercle * c) const {
    Cercle cAux = *c;
    ostringstream oss;

    oss << cAux.getCouleurString() << " ";

    oss << cAux.getCentre();
    oss << " " << cAux.getRayon();

    return oss.str();
}

const string FormatTXT::visite(const Triangle * t) const {
    Triangle tAux = *t;
    ostringstream oss;

    oss << tAux.getCouleurString() << " ";

    oss << pointToString(tAux.getPointA());
    oss << " | ";
    oss << pointToString(tAux.getPointB());
    oss << " | ";
    oss << pointToString(tAux.getPointC());

    return oss.str();
}

const string FormatTXT::visite(const Polygone * p) const {
    Polygone pAux = *p;
    ostringstream oss;
    int taille = pAux.getPoints().size();

    oss << pAux.getCouleurString() << " ";

    oss << "[";

    for(int i ; i<taille ; i++){
        oss << pointToString(pAux.getPoints()[i]);
        if(i < taille - 1) oss << " ";
    }

    oss << "]";

    return oss.str();
}

const string FormatTXT::visite(const Forme_comp * fc) const {
    Forme_comp fcAux = *fc;
    // TODO
    char *message = "Visiteur \"FormatTXT\" pour Forme_comp a implementer";
    return string(message);
}