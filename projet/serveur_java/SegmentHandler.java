package projet.serveur_java;

public class SegmentHandler extends Handler {

    public SegmentHandler(Handler suivant) {
        super(suivant);
    }

    @Override
    public boolean traiter(String commande) {
        if (commande.startsWith("SEGMENT")) {
            System.out.println("SegmentHandler : commande reconnue");
            System.out.println("Commande segment = " + commande);

            try {
                System.out.println("Avant split");

                String[] parties = commande.split(" ");

                System.out.println("Apres split");

                int x1 = (int) Double.parseDouble(parties[1]);
                int y1 = (int) Double.parseDouble(parties[2]);
                int x2 = (int) Double.parseDouble(parties[3]);
                int y2 = (int) Double.parseDouble(parties[4]);
                int couleur = Integer.parseInt(parties[5]);

                System.out.println("Avant appel Dessin");
                Dessin.dessinerSegment(x1, y1, x2, y2, couleur);
                System.out.println("Apres appel Dessin");

                return true;
            } catch (Exception e) {
                System.out.println("Erreur dans SegmentHandler");
                e.printStackTrace();
                return false;
            }
        }

        if (suivant != null) {
            return suivant.traiter(commande);
        }
        return false;
    }
}