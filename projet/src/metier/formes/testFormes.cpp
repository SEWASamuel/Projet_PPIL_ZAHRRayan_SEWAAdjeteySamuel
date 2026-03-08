#include "Forme.cpp"
#include "Segment.cpp"
#include "Cercle.cpp"
#include "Triangle.cpp"
#include "../exceptions/Erreur.cpp"

#include <iostream>

int main(){
    cout << "test de creation de formes : " << endl << endl;

    cout << "creation de segments..." << endl;

    Vecteur2D a(2,2);
    Vecteur2D b = Vecteur2D(2, 3);
    Vecteur2D c = Vecteur2D(7, 8);

    try {
        Segment j(COULEUR_BLEU, Matrice22(a, b));
        Segment k(COULEUR_JAUNE, Matrice22(b, a));

        cout << "Segments crees !" << endl;

        cout << "segment j : " << j << endl;
        cout << "segment k : " << k << endl << endl;

    } catch (Erreur &tmp) {
        cout << tmp << endl;
    }
    
    cout << "creation de cercles..." << endl;

    try {
        Cercle m(COULEUR_VERT, a, 2);
        Cercle n(COULEUR_CYAN, b, 7);

        cout << "Cercles crees !" << endl;

        cout << "Cercle m : " << m << endl;
        cout << "Cercle n : " << n << endl << endl;
        
    } catch (Erreur &tmp){
        cout << tmp << endl;
    }

    cout << "creation de triangles..." << endl;

    try {
        Triangle p(COULEUR_ROUGE, a, b, c);
        Triangle q(COULEUR_NOIR, Vecteur2D(6, 10), Vecteur2D(9, 16), Vecteur2D(5, 3));

        cout << "Triangles crees !" << endl;

        cout << "Triangle p : " << p << endl;
        cout << "Triangle q : " << q << endl << endl;

    } catch (Erreur &tmp) {
        cout << tmp << endl;
    }

    cout << "test fini !" << endl;

    return 0;
}