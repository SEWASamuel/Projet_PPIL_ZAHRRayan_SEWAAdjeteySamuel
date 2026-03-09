package projet.serveur_java;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

// Cette classe gère la communication avec un client connecté au serveur
public class ClientHandler extends Thread {

    private Socket clientSocket;

    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {

        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {

            // créer la chaîne de responsabilité une seule fois
            Handler chaine = new CercleHandler(
                    new SegmentHandler(
                            new TriangleHandler(
                                    new PolygoneHandler(null))));

            String message;

            // lire les commandes envoyées par le client tant que la connexion est ouverte
            while ((message = in.readLine()) != null) {

                System.out.println("Message recu du client : " + message);

                // envoyer la commande dans la chaîne
                boolean traite = chaine.traiter(message);

                // si aucun handler n'a reconnu la commande
                if (!traite) {
                    System.out.println("Commande non reconnue : " + message);
                }
            }

            // fermer la connexion quand le client se déconnecte
            clientSocket.close();

        } catch (Exception e) {

            System.out.println("Erreur dans le ClientHandler : " + e.getMessage());
            e.printStackTrace();
        }
    }
}