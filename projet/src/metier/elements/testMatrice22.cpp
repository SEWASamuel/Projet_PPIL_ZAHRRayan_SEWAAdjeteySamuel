using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include "Vecteur2D.h"
#include "Matrice22.h"

int main(){
    cout << "Test sur les matrices 2x2 : " << endl << endl;
    
    Matrice22 mat(4, -1, 7, 3);
    Vecteur2D v1(2,5);

    Vecteur2D v2 = mat*v1;

    cout << "v1 = " << v1 << endl << endl;

    cout << "mat = " << endl << mat << endl << endl;

    cout << "v2 (mat * v1) = " << v2 << endl << endl;

    double alfa = M_PI/4;

    Matrice22 matR = Matrice22::creeRotation(alfa);

    cout << "matR (matrice de rotation generee avec alfa = PI/4) = " << endl << matR << endl;

    return 0;
}