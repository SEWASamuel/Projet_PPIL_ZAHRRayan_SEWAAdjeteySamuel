package projet.serveur_java;

public class PolygoneHandler extends Handler {

    public PolygoneHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {

        if (commande.startsWith("POLYGONE")) {
            System.out.println("PolygoneHandler : commande reconnue");
            System.out.println("Commande polygone = " + commande);

            try {
                String[] parties = commande.split(" ");

                int nbPoints = Integer.parseInt(parties[1]);
                System.out.println("Nombre de points : " + nbPoints);

                // taille attendue de la commande :
                // 2 éléments fixes : "POLYGONE" + nbPoints
                // puis 2 coordonnées (x,y) pour chaque point → 2 * nbPoints
                // puis 1 élément pour la couleur
                // donc : 2 + (2 * nbPoints) + 1
                int tailleAttendue = 2 + (2 * nbPoints) + 1;

                if (parties.length != tailleAttendue) {
                    System.out.println("Commande polygone invalide : nombre d'arguments incorrect");
                    return false;
                }

                int index = 2;

                for (int i = 0; i < nbPoints; i++) {
                    double x = Double.parseDouble(parties[index]);
                    double y = Double.parseDouble(parties[index + 1]);

                    System.out.println("Point " + (i + 1) + " : (" + x + ", " + y + ")");

                    index += 2;
                }

                String couleur = parties[index];
                System.out.println("Couleur : " + couleur);

                return true;

            } catch (Exception e) {
                System.out.println("Erreur lors du traitement du polygone : " + e.getMessage());
                return false;
            }

        } else {
            if (suivant != null) {
                return suivant.traiter(commande);
            } else {
                System.out.println("Aucun handler disponible pour traiter la commande : " + commande);
                return false;
            }
        }
    }
}