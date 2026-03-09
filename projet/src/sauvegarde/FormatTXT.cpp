#include "FormatTXT.h"

const string pointToString(const Vecteur2D & point){
    ostringstream oss;

    oss << "(" << point.x << ", " << point.y << ")";

    return oss.str();
}

const string FormatTXT::visite(const Segment & s) const {
    ostringstream oss;

    //oss << s.getCouleurString() << " ";

    oss << pointToString(s.getExtremites().ligneHaut);
    oss << " " << pointToString(s.getExtremites().ligneBas);

    return oss.str();
}

const string FormatTXT::visite(const Cercle & c) const {
    ostringstream oss;

    //oss << c.getCouleurString() << " ";

    oss << c.getCentre();
    oss << " " << c.getRayon();

    return oss.str();
}

const string FormatTXT::visite(const Triangle & t) const {
    ostringstream oss;

    //oss << t.getCouleurString() << " ";

    oss << pointToString(t.getPointA());
    oss << " | ";
    oss << pointToString(t.getPointB());
    oss << " | ";
    oss << pointToString(t.getPointC());

    return oss.str();
}

const string FormatTXT::visite(const Polygone & p) const {
    ostringstream oss;
    int taille = p.getPoints().size();

    //oss << p.getCouleurString() << " ";

    oss << "[";

    for(int i ; i<taille ; i++){
        oss << pointToString(p.getPoints()[i]);
        if(i < taille - 1) oss << " ";
    }

    oss << "]";

    return oss.str();
}

const string FormatTXT::visite(const Forme_comp & fc) const {
    // TODO
    char *message = "Visiteur \"FormatTXT\" pour Forme_comp a implementer";
    return message;
}