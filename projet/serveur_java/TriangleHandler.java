package projet.serveur_java;

public class TriangleHandler extends Handler {

    public TriangleHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {
        if (commande.startsWith("TRIANGLE")) {
            System.out.println("TriangleHandler : commande reconnue");
            System.out.println("Commande triangle = " + commande);

            try {
                String[] parties = commande.trim().split("\\s+");

                int x1 = (int) Double.parseDouble(parties[1]);
                int y1 = (int) Double.parseDouble(parties[2]);
                int x2 = (int) Double.parseDouble(parties[3]);
                int y2 = (int) Double.parseDouble(parties[4]);
                int x3 = (int) Double.parseDouble(parties[5]);
                int y3 = (int) Double.parseDouble(parties[6]);
                int couleur = Integer.parseInt(parties[7]);

                System.out.println("x1 = " + x1 + ", y1 = " + y1);
                System.out.println("x2 = " + x2 + ", y2 = " + y2);
                System.out.println("x3 = " + x3 + ", y3 = " + y3);
                System.out.println("Couleur = " + couleur);

                Dessin.dessinerTriangle(x1, y1, x2, y2, x3, y3, couleur);

                return true;

            } catch (Exception e) {
                System.out.println("Erreur dans TriangleHandler : " + e.getMessage());
                return false;
            }
        }

        if (suivant != null) {
            return suivant.traiter(commande);
        }

        System.out.println("Aucun handler disponible pour traiter la commande : " + commande);
        return false;
    }
}