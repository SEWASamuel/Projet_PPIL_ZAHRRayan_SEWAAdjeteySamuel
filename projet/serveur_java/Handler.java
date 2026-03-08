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

    // methode qui essaye de traiter la commande si elle correspond au type de
    // handler
    // sinon elle passe la commande au handler suivant dans la chaîne
    public abstract boolean traiter(String commande);

}
