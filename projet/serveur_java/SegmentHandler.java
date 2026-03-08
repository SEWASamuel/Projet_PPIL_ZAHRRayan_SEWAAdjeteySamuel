package projet.serveur_java;

// Cette classe est un handler pour les segments, elle va traiter les messages liés aux segments envoyés par les clients
public class SegmentHandler extends Handler {

    // constructeur : recoit le handler suivant dans la chaîne de responsabilité
    public SegmentHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {

        // ici on va vérifier si la commande concerne un segment,
        // par exemple si elle commence par "SEGMENT"
        if (commande.startsWith("SEGMENT")) {

            System.out.println("SegmentHandler : commande reconnue");
            System.out.println("Commande segment = " + commande);

            // ici plus tard on pourra dessiner le segment

            return true; // indiquer que la commande a été traitée

        } else {

            // sinon, passer la commande au handler suivant dans la chaîne
            if (suivant != null) {
                return suivant.traiter(commande);
            } else {

                // fin de la chaîne, aucun handler n'a pu traiter la commande
                System.out.println("Aucun handler disponible pour traiter la commande : " + commande);

                return false; // indiquer que la commande n'a pas été traitée
            }
        }
    }
}