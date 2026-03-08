package projet.serveur_java;

import java.net.ServerSocket;
import java.net.Socket;

// cette classe est le serveur de dessin, elle écoute les connexions entrantes et gère les clients connectés
public class ServeurDessin {

    public static void main(String[] args) {
        int port = 9111; // port d'écoute du serveur

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Serveur de dessin demarre sur le port " + port);

            // le serveur tourne en boucle infinie pour accepter plusieurs clients
            while (true) {
                System.out.println("En attente de connexions entrantes...");

                Socket clientSocket = serverSocket.accept(); // attendre une connexion entrante
                System.out.println("Client connecte : " + clientSocket.getInetAddress());

                // créer un nouveau thread pour gérer le client connecté
                ClientHandler clientHandler = new ClientHandler(clientSocket);
                clientHandler.start();
            }

        } catch (Exception e) {
            System.out.println("Erreur dans le serveur : " + e.getMessage());
            e.printStackTrace();
        }
    }
}