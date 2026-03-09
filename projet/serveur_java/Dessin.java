package projet.serveur_java;

import java.awt.Frame;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.List;

public class Dessin {

    private static Frame fenetre;
    private static final List<FormeADessiner> formes = new ArrayList<>();

    private static class FormeADessiner {
        String type;
        int[] valeurs;

        FormeADessiner(String type, int... valeurs) {
            this.type = type;
            this.valeurs = valeurs;
        }
    }

    public static void initialiser() {
        fenetre = new Frame("Serveur de dessin") {
            @Override
            public void paint(Graphics g) {
                synchronized (formes) {

                    for (FormeADessiner f : formes) {

                        g.setColor(Couleur.convertirCouleur(f.valeurs[f.valeurs.length - 1]));

                        // ================= SEGMENT =================
                        if (f.type.equals("SEGMENT")) {

                            g.drawLine(
                                    f.valeurs[0],
                                    f.valeurs[1],
                                    f.valeurs[2],
                                    f.valeurs[3]);
                        }

                        // ================= CERCLE =================
                        else if (f.type.equals("CERCLE")) {

                            int x = f.valeurs[0];
                            int y = f.valeurs[1];
                            int rayon = f.valeurs[2];

                            g.drawOval(
                                    x - rayon,
                                    y - rayon,
                                    2 * rayon,
                                    2 * rayon);
                        }

                        // ================= TRIANGLE =================
                        else if (f.type.equals("TRIANGLE")) {

                            int[] xs = {
                                    f.valeurs[0],
                                    f.valeurs[2],
                                    f.valeurs[4]
                            };

                            int[] ys = {
                                    f.valeurs[1],
                                    f.valeurs[3],
                                    f.valeurs[5]
                            };

                            g.drawPolygon(xs, ys, 3);
                        }

                        // ================= POLYGONE =================
                        else if (f.type.equals("POLYGONE")) {

                            int nbPoints = f.valeurs[0];

                            int[] xs = new int[nbPoints];
                            int[] ys = new int[nbPoints];

                            int index = 1;

                            for (int i = 0; i < nbPoints; i++) {

                                xs[i] = f.valeurs[index];
                                ys[i] = f.valeurs[index + 1];

                                index += 2;
                            }

                            g.drawPolygon(xs, ys, nbPoints);
                        }
                    }
                }
            }
        };

        fenetre.setSize(800, 600);
        fenetre.setLocation(100, 100);
        fenetre.setVisible(true);

        System.out.println("Fenetre de dessin initialisee");
    }

    // ================= SEGMENT =================

    public static synchronized void dessinerSegment(int x1, int y1, int x2, int y2, int couleur) {

        synchronized (formes) {
            formes.add(new FormeADessiner(
                    "SEGMENT",
                    x1, y1, x2, y2, couleur));
        }

        fenetre.repaint();

        System.out.println("Segment dessine");
    }

    // ================= CERCLE =================

    public static synchronized void dessinerCercle(int x, int y, int rayon, int couleur) {

        synchronized (formes) {
            formes.add(new FormeADessiner(
                    "CERCLE",
                    x, y, rayon, couleur));
        }

        fenetre.repaint();

        System.out.println("Cercle dessine");
    }

    // ================= TRIANGLE =================

    public static synchronized void dessinerTriangle(
            int x1, int y1,
            int x2, int y2,
            int x3, int y3,
            int couleur) {

        synchronized (formes) {
            formes.add(new FormeADessiner(
                    "TRIANGLE",
                    x1, y1,
                    x2, y2,
                    x3, y3,
                    couleur));
        }

        fenetre.repaint();

        System.out.println("Triangle dessine");
    }

    // ================= POLYGONE =================

    public static synchronized void dessinerPolygone(
            int[] xs,
            int[] ys,
            int nbPoints,
            int couleur) {

        int[] valeurs = new int[1 + 2 * nbPoints + 1];

        valeurs[0] = nbPoints;

        int index = 1;

        for (int i = 0; i < nbPoints; i++) {

            valeurs[index] = xs[i];
            valeurs[index + 1] = ys[i];

            index += 2;
        }

        valeurs[index] = couleur;

        synchronized (formes) {
            formes.add(new FormeADessiner(
                    "POLYGONE",
                    valeurs));
        }

        fenetre.repaint();

        System.out.println("Polygone dessine");
    }
}