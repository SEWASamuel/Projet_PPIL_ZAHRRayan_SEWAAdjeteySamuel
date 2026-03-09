/**
 * @file Erreur.h
 * @brief Definition de la classe Erreur qui servira à relever des erreur ou exceptions dans mes programmes
 */

#ifndef ERREUR_H
#define ERREUR_H
#include <string>
#include <iostream>

using namespace std;

class Erreur {

public:

    const static int LONGUEUR_MESSAGE = 100;
    char messageErreur[LONGUEUR_MESSAGE + 1];

    /******************** CONSTRUCTEURS ********************/
    Erreur();

    Erreur(const char *sujetErreur);

    operator string()const;
    
};

ostream & operator << (ostream & os, const Erreur & erreur);

#endif //ERREUR_H
