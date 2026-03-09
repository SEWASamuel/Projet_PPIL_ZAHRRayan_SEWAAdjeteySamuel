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
                String[] parties = commande.trim().split("\\s+");

                int nbPoints = Integer.parseInt(parties[1]);

                int tailleAttendue = 2 + 2 * nbPoints + 1;
                if (parties.length != tailleAttendue) {
                    throw new IllegalArgumentException("Commande polygone invalide");
                }

                int[] xs = new int[nbPoints];
                int[] ys = new int[nbPoints];

                int index = 2;
                for (int i = 0; i < nbPoints; i++) {
                    xs[i] = (int) Double.parseDouble(parties[index]);
                    ys[i] = (int) Double.parseDouble(parties[index + 1]);
                    index += 2;
                }

                int couleur = Integer.parseInt(parties[index]);

                System.out.println("Nombre de points = " + nbPoints);
                System.out.println("Couleur = " + couleur);
                System.out.println("Avant appel Dessin");

                Dessin.dessinerPolygone(xs, ys, nbPoints, couleur);

                System.out.println("Apres appel Dessin");

                return true;

            } catch (Exception e) {
                System.out.println("Erreur dans PolygoneHandler : " + e.getMessage());
                e.printStackTrace();
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