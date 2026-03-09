package projet.serveur_java;

// Cette classe est un handler pour les cercles, elle va traiter les messages liés aux cercles envoyés par les clients
public class CercleHandler extends Handler {

    // constructeur : recoit le handler suivant dans la chaîne de responsabilité
    public CercleHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {
        // on vérifie si la commande concerne un cercle
        if (commande.startsWith("CERCLE")) {
            System.out.println("CercleHandler : commande reconnue");
            System.out.println("Commande cercle = " + commande);

            try {
                // découper la commande proprement
                String[] parties = commande.trim().split("\\s+");

                // récupérer les paramètres
                int x = (int) Double.parseDouble(parties[1]);
                int y = (int) Double.parseDouble(parties[2]);
                int rayon = (int) Double.parseDouble(parties[3]);
                int couleur = Integer.parseInt(parties[4]);

                // afficher les informations
                System.out.println("Centre X : " + x);
                System.out.println("Centre Y : " + y);
                System.out.println("Rayon : " + rayon);
                System.out.println("Couleur : " + couleur);

                // dessiner le cercle
                Dessin.dessinerCercle(x, y, rayon, couleur);

                return true; // indiquer que la commande a été traitée

            } catch (Exception e) {
                System.out.println("Erreur dans CercleHandler : " + e.getMessage());
                return false;
            }

        } else {
            // sinon, passer la commande au handler suivant dans la chaîne
            if (suivant != null) {
                return suivant.traiter(commande);
            } else {
                // fin de la chaîne, aucun handler n'a pu traiter la commande
                System.out.println("Aucun handler disponible pour traiter la commande : " + commande);
                return false;
            }
        }
    }
}