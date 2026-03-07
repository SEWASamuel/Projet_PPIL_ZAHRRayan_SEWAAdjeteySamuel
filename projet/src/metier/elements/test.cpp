#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <string>
#include <iostream>
#include <sstream>
#include "Vecteur2D.h"

using namespace std;

int main(){
    Vecteur2D v = Vecteur2D(1,1);

    cout << "Vecteur v = " <<  v << endl << endl;

    cout << "test du produit scalaire" << endl;
    Vecteur2D v1(3,2), v2(-2,3);

    v1 = v1 * 5; cout << "V1 = : " << v1 << endl;
    v2 = v2 * -3; cout << "V2 = : " << v2 << endl;

    double a = v1*v2; // a = v1.operator*(v2)

    cout << "a = " << a << endl << endl;


    cout << "Test de la norme d'un vecteur" << endl;

    Vecteur2D nV2(4,3);

    cout << "Vecteur nV2 = " << nV2 << endl;

    double nVd = nV2.norme2();

    cout << "On doit trouver 25, |v|^2 = " << nVd << endl;

    double nV = nV2.norme();

    cout << "on doit trouver 5, |v| = " << nV << endl << endl;

    cout << "Test de la distance entre 2 vecteurs" << endl;
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    double dist2 = v1.distance2(v2);
    double dist = v1.distance(v2);

    cout << "Distance carree entre v1 et v2 : " << dist2 << endl;
    cout << "Distance entre v1 et v2 : " << dist << endl;
}

#endif