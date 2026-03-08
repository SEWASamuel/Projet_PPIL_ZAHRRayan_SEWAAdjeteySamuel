package projet.client_test;

import java.io.PrintStream;
import java.net.Socket;

public class TestClient {

    public static void main(String[] args) {
        String adresseServeur = "127.0.0.1";
        int portServeur = 9111;

        try (
                // Ça connecte le client au serveur
                Socket socket = new Socket(adresseServeur, portServeur);
                // Ça crée un flux de sortie pour envoyer des données au serveur
                PrintStream out = new PrintStream(socket.getOutputStream())) {
            String message = "CERCLE 100 200 50 RED";

            System.out.println("Envoi du message : " + message);
            // Ça envoie le message au serveur
            out.println(message);

            System.out.println("Message envoye au serveur.");

        } catch (Exception e) {
            System.out.println("Erreur dans le client : " + e.getMessage());
            e.printStackTrace();
        }
    }
}