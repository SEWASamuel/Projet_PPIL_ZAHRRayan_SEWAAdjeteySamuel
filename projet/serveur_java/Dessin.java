package projet.serveur_java;

import java.awt.Frame;
import java.awt.Graphics;

public class Dessin {

    public static void dessinerSegment(int x1, int y1, int x2, int y2, int couleur) {
        System.out.println("Je suis entre dans dessinerSegment");

        Frame fenetre = new Frame("Dessin Segment") {
            @Override
            public void paint(Graphics g) {
                g.setColor(Couleur.convertirCouleur(couleur));
                g.drawLine(x1, y1, x2, y2);
            }
        };

        fenetre.setSize(800, 600);
        fenetre.setLocation(100, 100);
        fenetre.setVisible(true);

        System.out.println("Fenetre de dessin ouverte");
    }
}