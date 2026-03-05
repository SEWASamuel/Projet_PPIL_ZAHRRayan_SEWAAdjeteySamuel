#include "Forme.cpp"
#include "Segment.cpp"
#include "Cercle.cpp"
#include "Triangle.cpp"

#include <iostream>

int main(){
    cout << "test de creation de formes : " << endl;

    Vecteur2D v(2,2);

    Vecteur2D VecteurAux = Vecteur2D(2,3);
    
    Segment s(1,v);

    return 0;
}