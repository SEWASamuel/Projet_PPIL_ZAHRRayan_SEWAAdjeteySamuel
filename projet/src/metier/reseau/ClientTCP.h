/**
 * @file ClientTCP.h
 * @brief Définition de la classe ClientTCP qui nous servira à envoyer un message au serveur de dessin
 */
#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <string>

class ClientTCP {
public:
    /// Cette méthode envoie un message au serveur de dessin
    static void envoyerAuServeur(const std::string& message, const std::string& ip, int port);
};

#endif