#include "../formes/Forme.cpp"
#include "../formes/Segment.cpp"
#include "../formes/Cercle.cpp"
#include "../formes/Triangle.cpp"
//#include "../formes/Polygoone.cpp"
//#include "../formes/forme_comp.cpp"

#include "opTrans.h"

#include "transformations/Transformation.h"
#include "transformations/TransformationTranslation.h"
#include "transformations/TransformationHomothetie.h"
#include "transformations/TransformationHomothetie.h"
#include "Transformateur.cpp"
#include "TransSegment.cpp"
#include "TransCercle.cpp"
#include "TransTriangle.cpp"
#include "TransPolygone.cpp"
//#include "TransForme_comp.h"
#include "../exceptions/Erreur.cpp"

int main(void){

    cout << "Initialisation des formes :" << endl;
    
    Segment s(COULEUR_JAUNE, Matrice22(Vecteur2D(1, 1), Vecteur2D(2, 2)));
    Cercle c(COULEUR_CYAN, Vecteur2D(3, 3), 3.0);
    Triangle t(COULEUR_ROUGE, Vecteur2D(1, 1), Vecteur2D(2, 2), Vecteur2D(3, 1));

    cout << s << endl;
    cout << c << endl;
    cout << t << endl << endl;

    cout << "Initialisation de la chaine de responsabilite..." << endl;

    Transformateur *chaine = new TransSegment(new TransCercle(new TransTriangle(new TransPolygone(NULL)))); 

    cout << "Initialisation de la chaine de responsabilité reussie ! "<< endl << endl;

    cout << "Test de transformations : " << endl;
    cout << "Initialisation des transformations..." << endl;

    TransformationTranslation translation1(Vecteur2D(1, 1));
    TransformationHomothetie homothetie1(Vecteur2D(1, 1), 3.0);
    TransformationRotation rotation1(Vecteur2D(1, 1), 1);

    cout << "Initialisation reussie !" << endl << endl;


    cout << "Test de translation : " << endl;

    Segment *sTranslation = (Segment *)chaine->transforme(s, translation1);
    cout << "Segment translate : " << *sTranslation << endl << endl;

    Cercle *cTranslate = (Cercle *)chaine->transforme(c, translation1);
    cout << "Cercle translate : " << *cTranslate << endl << endl;

    Triangle *tTranslate = (Triangle *)chaine->transforme(t, translation1);
    cout << "Triangle translate : " << *tTranslate << endl << endl << endl;


    cout << "Test d'homotheite : " << endl;

    Segment *sZoom = (Segment *)chaine->transforme(s, homothetie1);
    cout << "Segment zoome : " << *sZoom << endl << endl;

    Cercle *cZomm = (Cercle *)chaine->transforme(c, homothetie1);
    cout << "Cercle zoome : " << *cZomm << endl << endl;

    Triangle *tZoom = (Triangle *)chaine->transforme(t, homothetie1);
    cout << "Triangle zoome : " << *tZoom << endl << endl << endl;


    cout << "Test de rotation : " << endl;

    Segment *sRotation = (Segment *)chaine->transforme(s, rotation1);
    cout << "Segment tourne : " << *sRotation << endl << endl;

    Cercle *cRotation = (Cercle *)chaine->transforme(c, rotation1);
    cout << "Cercle tourne : " << *cRotation << endl << endl;

    Triangle *tRotation = (Triangle *)chaine->transforme(t, rotation1);
    cout << "Triangle tourne : " << *tRotation << endl << endl << endl;
    
    return 0;
}