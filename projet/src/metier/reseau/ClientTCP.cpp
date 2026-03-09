#include "ClientTCP.h"
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void ClientTCP::envoyerAuServeur(const string& message, const string& ip, int port) {
    WSADATA wsa;
    SOCKET sock;
    sockaddr_in serveur;

    // 1) Initialisation de Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "Erreur : WSAStartup a echoue" << endl;
        return;
    }

    // 2) Creation de la socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Erreur : creation de la socket impossible" << endl;
        WSACleanup();
        return;
    }

    // 3) Preparation de l'adresse du serveur
    serveur.sin_family = AF_INET;
    serveur.sin_port = htons(port);
    serveur.sin_addr.s_addr = inet_addr(ip.c_str());

    // 4) Connexion au serveur
    if (connect(sock, (struct sockaddr*)&serveur, sizeof(serveur)) < 0) {
        cerr << "Erreur : connexion au serveur impossible" << endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // 5) Envoi du message
    // On ajoute \n pour que le readLine() Java lise bien une ligne complete
    string msg = message + "\n";

    if (send(sock, msg.c_str(), (int)msg.size(), 0) == SOCKET_ERROR) {
        cerr << "Erreur : envoi du message impossible" << endl;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // 6) Fermeture
    closesocket(sock);
    WSACleanup();
}