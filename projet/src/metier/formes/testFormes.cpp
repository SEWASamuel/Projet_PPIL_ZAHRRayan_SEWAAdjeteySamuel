#include <iostream>

#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"

using namespace std;

int main(){

    cout << "Test de creation de formes" << endl;

    // Points
    Vecteur2D A(0,0);
    Vecteur2D B(4,0);
    Vecteur2D C(0,3);

    // Segment
    Segment s(A,B,1);

    // Cercle
    Cercle c(Vecteur2D(1,1), 2.0, 2);

    // Triangle
    Triangle t(A,B,C,3);

    cout << endl << "Affichage des formes :" << endl;

    s.afficher();
    c.afficher();
    t.afficher();

    cout << endl;

    cout << "Aire du segment : " << s.calculerAire() << endl;
    cout << "Aire du cercle : " << c.calculerAire() << endl;
    cout << "Aire du triangle : " << t.calculerAire() << endl;

    return 0;
}