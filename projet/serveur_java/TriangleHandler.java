package projet.serveur_java;

// Cette classe est un handler pour les triangles, elle va traiter les messages liés aux triangles envoyés par les clients
public class TriangleHandler extends Handler {

    // constructeur : recoit le handler suivant dans la chaîne de responsabilité
    public TriangleHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {

        // ici on va vérifier si la commande concerne un triangle,
        // par exemple si elle commence par "TRIANGLE"
        if (commande.startsWith("TRIANGLE")) {

            System.out.println("TriangleHandler : commande reconnue");
            System.out.println("Commande triangle = " + commande);

            // ici plus tard on pourra dessiner le triangle

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