#include "ChargeurListeFormes.h"

#define LONGUEUR_LIGNE 100

const vector<Forme*> ChargeurListeFormes::charge(FILE * fichier, ParseurForme * parseur){
    // ici, le but est de construire un vecteur de formes qu'on va charger grâce à la chaine de responsabilité

    // Donc, on déclare ici le vecteur qu'on va retourner à la fin
    //vector<Forme> formes = vector<Forme>();
    vector<Forme*> formes = vector<Forme*>();

    // pour un fichier donné, on veut analyser chaque ligne
    // on va donc utiliser une boucle while qui va s'arreter lorsqu'on arrive à la fin du fichier

    // ici on verifie si le fichier est bien ouvert, sinon on renvoie le vecteur vide
    if(!fichier) return formes;
    Forme * fAux;

    char ligne[LONGUEUR_LIGNE];

    while(!feof(fichier)){
        if(fgets(ligne, LONGUEUR_LIGNE, fichier) != NULL){
            fAux = parseur->parse(ligne);
            if(fAux != NULL){
                formes.push_back(fAux);
            }
        }
    }

    return formes;
}