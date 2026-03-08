#include "Vecteur2D.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Vecteur2D A(2,3);
    Vecteur2D u(5,-1);

    cout << "A.x = " << A.x << ", A.y = " << A.y << endl;
    cout << "A = " << (string)A << endl;
    cout << "A = " << A << endl;

    Vecteur2D B;
    B = A + u;

    cout << "A = " << A << endl;
    cout << "u = " << u << endl;
    cout << "B = " << B << endl;

    cout << "Produit vecteur * double" << endl;
    Vecteur2D v1(3,2);
    Vecteur2D v2;

    v2 = v1 * 3;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "Test du produit scalaire" << endl;
    Vecteur2D p1(3,2);
    Vecteur2D p2(-2,3);

    double a = p1 * p2;
    cout << "a = " << a << endl;

    cout << "Test de la norme d'un vecteur" << endl;
    Vecteur2D v(4,3);

    double nV2 = v.norme2();
    cout << "on doit trouver 25, |v|^2 = " << nV2 << endl;

    double nV = v.norme();
    cout << "on doit trouver 5, |v| = " << nV << endl;

    return 0;
}