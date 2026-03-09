/**
 * @file TarseurFormeCOR.cpp
 * @brief Definition de la fonction "parse" de la classe ParseurFormeCOR
 */
#include "ParseurFormeCOR.h"

ParseurFormeCOR::ParseurFormeCOR(ParseurFormeCOR * suivant) : suivant(suivant) {}

Forme * ParseurFormeCOR::parse(const char* ligne) const {
    Forme * f = this->parse1(ligne);

    if(f != NULL){
        return f;
    } else {
        if(this->suivant != NULL){
            return this->suivant->parse(ligne);
        } else {
            return NULL;
        }
    }
}