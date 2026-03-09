package projet.serveur_java;

// Cette classe est un handler pour les triangles
public class TriangleHandler extends Handler {

    public TriangleHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {

        if (commande.startsWith("TRIANGLE")) {

            System.out.println("TriangleHandler : commande reconnue");
            System.out.println("Commande triangle = " + commande);

            String[] parties = commande.split(" ");

            if (parties.length != 8) {
                System.out.println("Commande TRIANGLE invalide");
                return false;
            }

            double x1 = Double.parseDouble(parties[1]);
            double y1 = Double.parseDouble(parties[2]);
            double x2 = Double.parseDouble(parties[3]);
            double y2 = Double.parseDouble(parties[4]);
            double x3 = Double.parseDouble(parties[5]);
            double y3 = Double.parseDouble(parties[6]);

            String couleur = convertirCouleur(parties[7]);

            System.out.println("Point A : (" + x1 + ", " + y1 + ")");
            System.out.println("Point B : (" + x2 + ", " + y2 + ")");
            System.out.println("Point C : (" + x3 + ", " + y3 + ")");
            System.out.println("Couleur : " + couleur);

            return true;

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