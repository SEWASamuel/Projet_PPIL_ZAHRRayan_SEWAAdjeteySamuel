#include "ChargeurListeFormes.cpp"
#include "parseurs/ParseurForme.h"
#include "parseurs/ParseurFormeCOR.cpp"
#include "parseurs/ParseurFormeCORSegment.cpp"
#include "parseurs/ParseurFormeCORCercle.cpp"
#include "parseurs/ParseurFormeCORTriangle.cpp"
#include "parseurs/ParseurFormeCORPolynome.cpp"

int main(void){
    FILE * fichier = fopen("formes.txt", "r");

    ParseurFormeCOR *p = new ParseurFormeCOR(new ParseurFormeCORSegment(new ParseurFormeCORCercle(new ParseurFormeCORTriangle(new ParseurFormeCORPolynome(NULL)))));
    
    vector<Forme> formes = ChargeurListeFormes::charge(fichier, p);

    Forme * forme1 = &formes[0];
    Forme * forme2 = &formes[1];
    Forme * forme3 = &formes[2];

    cout << "Forme 1 : " << &forme1 << endl;
    cout << "Forme 2 : " << &forme2 << endl;
    cout << "Forme 2 : " << &forme3 << endl;

    return 0;
}