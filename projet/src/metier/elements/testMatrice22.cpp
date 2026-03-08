#include <iostream>
#include <string>
#include <sstream>
#include "Vecteur2D.h"
#include "Matrice22.h"

using namespace std;

int main() {
    Matrice22 mat(4, -1, 7, 3);
    Vecteur2D v1(2, 5);

    Vecteur2D v2 = mat * v1;

    cout << "v1 = " << v1 << endl;
    cout << "mat = " << endl << mat << endl;
    cout << "v2 = " << v2 << endl;

    double alfa = 3.14 / 4;
    Matrice22 matR = Matrice22::creeRotation(alfa);

    cout << "matR = " << endl << matR << endl;

    return 0;
}