#include "../metier/formes/Forme.cpp"
#include "../metier/formes/Segment.cpp"
#include "../metier/formes/Cercle.cpp"
#include "../metier/formes/Triangle.cpp"
#include "../metier/formes/Polygone.cpp"

#include "ChargeurListeFormes.cpp"
#include "parseurs/ParseurForme.h"
#include "parseurs/ParseurFormeCOR.cpp"
#include "parseurs/ParseurFormeCORSegment.cpp"
#include "parseurs/ParseurFormeCORCercle.cpp"
#include "parseurs/ParseurFormeCORTriangle.cpp"
#include "parseurs/ParseurFormeCORPolygone.cpp"

#include "../metier/exceptions/Erreur.cpp"

const string formeToString(Forme *f){
    const string type = f->getType();

    ostringstream oss;

    if(type == "segment"){
        Segment *s = (Segment *) f;
        oss << *s;
    } else if(type == "cercle"){
        Cercle *c = (Cercle *) f;
        oss << *c;
    } else if( type == "triangle"){
        Triangle *t = (Triangle *) f;
        oss << *t;
    } else if (type == "polygone"){
        Polygone *p = (Polygone *) f;
        oss << *p;
    } else {
        oss << "Forme non trouvee";
    }

    return oss.str();
}

int main(void){
    FILE * fichier = fopen("formes.txt", "r");

    ParseurFormeCOR *p = new ParseurFormeCORSegment(new ParseurFormeCORCercle(new ParseurFormeCORTriangle(new ParseurFormeCORPolygone(NULL))));
    
    vector<Forme*> formes = ChargeurListeFormes::charge(fichier, p);

    for(unsigned int i=0 ; i<formes.size() ; i++){
        cout << "Forme " << i << " : " << formeToString(formes[i]) << endl;
    }

    return 0;
}