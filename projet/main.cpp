#include <iostream>
#include <vector>
#include <windows.h>
#include "src/metier/formes/Cercle.h"
#include "src/metier/formes/Segment.h"
#include "src/metier/formes/Triangle.h"
#include "src/metier/formes/Polygone.h"
#include "src/metier/formes/Forme_comp.h"

#include "src/metier/elements/Vecteur2D.h"
#include "src/metier/elements/Matrice22.h"
#include "src/metier/reseau/ClientTCP.h"

using namespace std;

int main() {
    /*
    cout << "===== TEST DES FORMES =====" << endl;

    Cercle c(COULEUR_ROUGE, Vecteur2D(10,20), 5);
    cout << c << endl;
    c.dessiner();
    cout << "Aire cercle = " << c.calculerAire() << endl;

    cout << endl;

    Segment s(COULEUR_BLEU, Matrice22(Vecteur2D(0,0), Vecteur2D(4,3)));
    cout << s << endl;
    s.dessiner();
    cout << "Aire segment = " << s.calculerAire() << endl;

    cout << endl;

    Triangle t(COULEUR_VERT,
               Vecteur2D(0,0),
               Vecteur2D(4,0),
               Vecteur2D(0,3));

    cout << t << endl;
    t.dessiner();
    cout << "Aire triangle = " << t.calculerAire() << endl;

    cout << endl;

    vector<Vecteur2D> points;
    points.push_back(Vecteur2D(0,0));
    points.push_back(Vecteur2D(4,0));
    points.push_back(Vecteur2D(4,3));
    points.push_back(Vecteur2D(0,3));

    Polygone p(COULEUR_JAUNE, points);

    cout << p << endl;
    p.dessiner();
    cout << "Aire polygone = " << p.calculerAire() << endl;

    cout << endl;

    cout << "===== TEST FORME COMPOSEE =====" << endl;

    Forme_comp g;

    g.addForme(new Cercle(COULEUR_ROUGE, Vecteur2D(0,0), 2));
    g.addForme(new Triangle(COULEUR_BLEU,
                            Vecteur2D(0,0),
                            Vecteur2D(4,0),
                            Vecteur2D(0,3)));

    cout << (string)g << endl;

    g.dessiner();

    cout << "Aire groupe = " << g.calculerAire() << endl;
    
    
    
    */
    ClientTCP::envoyerAuServeur("SEGMENT 10 10 200 200 2", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur("CERCLE 300 300 50 2", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur("TRIANGLE 100 100 200 100 150 200 3", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur(
"POLYGONE 5 300 300 350 250 400 300 375 350 325 350 4",
"127.0.0.1",
9111);

return 0;
}