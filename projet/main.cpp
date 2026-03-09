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

#include "src/metier/transformateurs/TransCercle.h"
#include "src/metier/transformateurs/TransSegment.h"
#include "src/metier/transformateurs/TransTriangle.h"
#include "src/metier/transformateurs/transformations/TransformationTranslation.h"
#include "src/metier/transformateurs/transformations/TransformationHomothetie.h"
#include "src/metier/transformateurs/transformations/TransformationRotation.h"

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
    
    
    // Envoi de commandes de dessin au serveur Java pour tester la communication TCP

  /*  ClientTCP::envoyerAuServeur("SEGMENT 10 10 200 200 2", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur("CERCLE 300 300 50 2", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur("TRIANGLE 100 100 200 100 150 200 3", "127.0.0.1", 9111);
Sleep(300);

ClientTCP::envoyerAuServeur(
"POLYGONE 5 300 300 350 250 400 300 375 350 325 350 4",
"127.0.0.1",
9111); 
*/
/*   
    cout << endl;
cout << "===== TEST FORME COMPOSEE =====" << endl;

Forme_comp g;

g.addForme(new Cercle(COULEUR_ROUGE, Vecteur2D(150,150), 40));

g.addForme(new Triangle(COULEUR_VERT,
                        Vecteur2D(250,100),
                        Vecteur2D(320,100),
                        Vecteur2D(280,180)));

vector<Vecteur2D> pts;
pts.push_back(Vecteur2D(400,100));
pts.push_back(Vecteur2D(500,100));
pts.push_back(Vecteur2D(500,200));
pts.push_back(Vecteur2D(400,200));

g.addForme(new Polygone(COULEUR_JAUNE, pts));

cout << (string)g << endl;

g.dessiner();

cout << "Aire groupe = " << g.calculerAire() << endl;

*/


  Cercle c(COULEUR_ROUGE, Vecteur2D(100, 100), 40);
    Segment s(COULEUR_BLEU, Matrice22(Vecteur2D(50, 50), Vecteur2D(200, 200)));
    Triangle t(COULEUR_VERT, Vecteur2D(250, 100), Vecteur2D(320, 100), Vecteur2D(280, 180));

    vector<Vecteur2D> pts;
    pts.push_back(Vecteur2D(400, 100));
    pts.push_back(Vecteur2D(500, 100));
    pts.push_back(Vecteur2D(500, 200));
    pts.push_back(Vecteur2D(400, 200));
    Polygone p(COULEUR_JAUNE, pts);

    cout << c << endl;
    cout << "Aire cercle = " << c.calculerAire() << endl;
    c.dessiner();

    cout << s << endl;
    cout << "Aire segment = " << s.calculerAire() << endl;
    s.dessiner();

    cout << t << endl;
    cout << "Aire triangle = " << t.calculerAire() << endl;
    t.dessiner();

    cout << p << endl;
    cout << "Aire polygone = " << p.calculerAire() << endl;
    p.dessiner();

    cout << endl << "=== TEST TRANSFORMATIONS ===" << endl;

    TransCercle tc;
    TransSegment ts;
    TransTriangle tt;

    TransformationTranslation trans(Vecteur2D(100, 50));

    Forme* c2 = tc.transforme(c, trans);
    Forme* s2 = ts.transforme(s, trans);
    Forme* t2 = tt.transforme(t, trans);

    cout << (string)(*c2) << endl;
    c2->dessiner();

    cout << (string)(*s2) << endl;
    s2->dessiner();

    cout << (string)(*t2) << endl;
    t2->dessiner();

    cout << endl << "=== TEST FORME COMPOSEE ===" << endl;

    Forme_comp g;
    g.addForme(new Cercle(COULEUR_ROUGE, Vecteur2D(150,150), 40));
    g.addForme(new Triangle(COULEUR_VERT,
                            Vecteur2D(250,100),
                            Vecteur2D(320,100),
                            Vecteur2D(280,180)));
    g.addForme(new Polygone(COULEUR_JAUNE, pts));

    cout << (string)g << endl;
    cout << "Aire groupe = " << g.calculerAire() << endl;
    g.dessiner();

    delete c2;
    delete s2;
    delete t2;






return 0;
}