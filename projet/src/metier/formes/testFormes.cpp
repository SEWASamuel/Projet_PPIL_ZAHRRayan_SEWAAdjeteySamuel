#include "Forme.cpp"
#include "Segment.cpp"
#include "Cercle.cpp"
#include "Triangle.cpp"

#include <iostream>

int main(){
    cout << "test de creation de formes : " << endl;

    Vecteur2D a(2,2);
    Vecteur2D b = Vecteur2D(2, 3);
    Vecteur2D c = Vecteur2D(7, 8);
    
    Segment j(COULEUR_BLEU, a);
    Segment k(COULEUR_JAUNE, b);

    Cercle m(COULEUR_VERT, a, 2);
    Cercle n(COULEUR_CYAN, b, 7);

    Triangle p(COULEUR_ROUGE, a, b, c);
    Triangle q(COULEUR_NOIR, Vecteur2D(6, 10), Vecteur2D(9, 16), Vecteur2D(5, 3));

    return 0;
}