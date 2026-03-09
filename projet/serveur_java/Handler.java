package projet.serveur_java;

// c'est la classe abstraite Handler qui définit la structure de base pour les différents types de handlers (CercleHandler, TriangleHandler, SegmentHandler) 
// pour la chain of responsibility
public abstract class Handler {
    // le champ suivant est une référence au prochain handler dans la chaîne de
    // responsabilité
    protected Handler suivant;

    // le constructeur prend en paramètre un handler suivant pour construire la
    // chaîne de responsabilité
    public Handler(Handler suivant) {
        this.suivant = suivant;
    }

    protected String convertirCouleur(String couleur) {

        if (couleur.equalsIgnoreCase("Rouge"))
            return "RED";
        if (couleur.equalsIgnoreCase("Bleu"))
            return "BLUE";
        if (couleur.equalsIgnoreCase("Vert"))
            return "GREEN";
        if (couleur.equalsIgnoreCase("Jaune"))
            return "YELLOW";
        if (couleur.equalsIgnoreCase("Noir"))
            return "BLACK";
        if (couleur.equalsIgnoreCase("Cyan"))
            return "CYAN";

        return couleur;
    }

    // methode qui essaye de traiter la commande si elle correspond au type de
    // handler
    // sinon elle passe la commande au handler suivant dans la chaîne
    public abstract boolean traiter(String commande);

}
