#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <string>
#include <iostream>
#include <sstream>
#include "Vecteur2D.h"

using namespace std;

int main(){
    Vecteur2D v = Vecteur2D(1,1);

    cout << v << endl;

    cout << "test du produit scalaire" << endl;
    Vecteur2D v1(3,2), v2(-2,3);

    v1 = 5*v1;
    v2 = -3*v2;

    double a = v1*v2; // a = v1.operator*(v2)

    cout << "a = " << a << endl;


    cout << "Test de la norme d'un vecteur" << endl;

    Vecteur2D nV2(4,3);

    double nV = v.norme2();

    cout << "On doit trouver 25 |v|^2 = " << nV2 << endl;

    double nV = v.norme();

    cout << "on doit trouver 5, |v|  = " << nV << endl;
    
}

#endif