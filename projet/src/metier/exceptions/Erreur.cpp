//
// Created by samue on 19/01/2026.
//

#include "Erreur.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

Erreur::Erreur() {
    strcpy(this->messageErreur, "Erreur !");
}

Erreur::Erreur(const char *sujetErreur) {
    strcpy(this->messageErreur, "Erreur : ");
    int l =  strlen(sujetErreur);
    static int n = LONGUEUR_MESSAGE-9;
    if (l <= n) strcat(this->messageErreur, sujetErreur);
    else {
        strncat(this->messageErreur, sujetErreur, n);
        this->messageErreur[LONGUEUR_MESSAGE] = '\0';
    }
}

Erreur::operator string() const {
    return string(this->messageErreur);
}

ostream & operator << (ostream & os, const Erreur & erreur) {
    os << (string)erreur;
    return os;
}