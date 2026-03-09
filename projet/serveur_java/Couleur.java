package projet.serveur_java;

import java.awt.Color;

public class Couleur {

    public static Color convertirCouleur(int code) {
        switch (code) {
            case 0:
                return Color.BLACK;
            case 1:
                return Color.BLUE;
            case 2:
                return Color.RED;
            case 3:
                return Color.GREEN;
            case 4:
                return Color.YELLOW;
            case 5:
                return Color.CYAN;
            default:
                return Color.BLACK;
        }
    }
}