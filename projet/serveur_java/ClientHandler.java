package projet.serveur_java;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientHandler extends Thread {
    private Socket clientSocket;

    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {
            String message = in.readLine(); // lire le message du client
            System.out.println("Message recu du client : " + message);

            // créer la chaîne de responsabilité
            Handler chaine = new CercleHandler(
                    new SegmentHandler(
                            new TriangleHandler(null)));

            // envoyer la commande dans la chaîne
            boolean traite = chaine.traiter(message);

            // si aucun handler n'a traité la commande
            if (!traite) {
                System.out.println("Commande non reconnue : " + message);
            }

            clientSocket.close(); // fermer la connexion avec le client

        } catch (Exception e) {
            System.out.println("Erreur dans le ClientHandler : " + e.getMessage());
            e.printStackTrace();

        }
    }
}