package projet.serveur_java;

// Cette classe est un handler pour les cercles, elle va traiter les messages liés aux cercles envoyés par les clients
public class CercleHandler extends Handler {

    // constructeur : recoit le handler suivant dans la chaîne de responsabilité
    public CercleHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {
        // ici on va vérifier si la commande concerne un cercle, par exemple si elle
        // commence par "CERCLE"
        if (commande.startsWith("CERCLE")) {
            System.out.println("CercleHandler : commande reconnue");
            System.out.println("Commande cercle = " + commande);
            // découper la commande
            String[] parties = commande.split(" ");

            // récupérer les paramètres
            double x = Double.parseDouble(parties[1]);
            double y = Double.parseDouble(parties[2]);
            double rayon = Double.parseDouble(parties[3]);
            String couleur = convertirCouleur(parties[4]);

            // afficher les informations
            System.out.println("Centre X : " + x);
            System.out.println("Centre Y : " + y);
            System.out.println("Rayon : " + rayon);
            System.out.println("Couleur : " + couleur);

            // ici plus tard on dessinera le cercle

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
