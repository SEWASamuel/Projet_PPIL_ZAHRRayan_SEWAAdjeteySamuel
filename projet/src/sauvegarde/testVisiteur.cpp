#include "VisiteurForme.h"
#include "FormatTXT.cpp"
#include "SauvForme.h"

#include "../metier/formes/Forme.cpp"
#include "../metier/formes/Segment.cpp"
#include "../metier/formes/Cercle.cpp"
#include "../metier/formes/Triangle.cpp"
#include "../metier/formes/Polygone.cpp"
#include "../metier/formes/Forme_comp.cpp"

#include "../metier/exceptions/Erreur.cpp"

int main(void){
    Segment s(COULEUR_BLEU, Matrice22(Vecteur2D(1, 1), Vecteur2D(2, 2)));
    Cercle c(COULEUR_CYAN, Vecteur2D(4, 4), 3);
    Triangle t(COULEUR_JAUNE, Vecteur2D(2, 2), Vecteur2D(-2, 4), Vecteur2D(-3, -4));
    vector<Vecteur2D> points;
    points.push_back(Vecteur2D(5, 7));
    points.push_back(Vecteur2D(6, 6));
    points.push_back(Vecteur2D(7, 8));
    points.push_back(Vecteur2D(6, -2)); 
    Polygone p(COULEUR_ROUGE, points);


    SauvSegment ss(s);
    SauvCercle sc(c);
    SauvTriangle st(t);
    SauvPolygone sp(p);

    FormatTXT fTexte;

    cout << "Segment TXT : " << ss.accepte(fTexte) << endl;
    cout << "Cercle TXT : " << sc.accepte(fTexte) << endl;
    cout << "Triangle TXT : " << st.accepte(fTexte) << endl;
    cout << "Polygone TXT : " << sp.accepte(fTexte) << endl;

    return 0;
}