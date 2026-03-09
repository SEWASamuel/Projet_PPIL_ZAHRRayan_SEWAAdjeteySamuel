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

                if (parties.length < 4) {
                    System.out.println("Commande polygone invalide");
                    return false;
                }

                int nbPoints = Integer.parseInt(parties[1]);
                System.out.println("Nombre de points : " + nbPoints);

                if (nbPoints < 3) {
                    System.out.println("Commande polygone invalide : un polygone doit avoir au moins 3 points");
                    return false;
                }

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

                String couleur = convertirCouleur(parties[index]);
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