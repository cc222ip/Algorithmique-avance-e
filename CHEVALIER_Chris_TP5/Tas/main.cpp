#include "tas.h"
#include <time.h>

int main() {
    int n = 5;
    Tas T(n);

    // Test vide() :
    cout << "Le tas est-il vide ?" << endl;
    cout << T.estvide() << endl;

    // Ajouts :
    T.ajout(10);
    T.ajout(8);
    T.ajout(15);
    T.ajout(2);
    T.ajout(11);
    T.ajout(12);
    T.ajout(9);
    T.afficher();

    // Test vide() :
    cout << "Le tas est-il vide ?" << endl;
    cout << T.estvide() << endl;

    // Tests suppression() :
    cout << "L'élement supprimé est le " << T.suppression() << endl;
    T.afficher(); // Je ne comprend pas pourquoi T[0] s'initialise automatiquement à 0.
    // La fonction d'affichage cache ce 0 en trop mais lors de la suppression, le premier élément du tableau étant supprimé, le 0
    // refait son apparition. De plus, il est nécesseur de décaler le pointeur queue de -1 pour que la suppression soit cohérente.
    // De ce fait, le 12 n'apparaît plus alors qu'il devrait être le dernier élément du tas.
    // Enfin, les suppressions suivantes seront faussées à cause de ce fameux zéro.

    // Test taille() :
    cout << "Le tas T a une taille de " << T.taille() << endl;

    // Tri par tas :
    // On créé un tableau R avec des valeurs quelconques :
    int m = 5;
    int *R = new int[m];
    srand(time(NULL));
    int nbgen = rand()%9+1;    //nb aléatoires entre 1-9
    for(int i = 0; i < n; i ++) {
        R[i] = nbgen;
        nbgen = rand()%9+1;
        cout << R[i] << " ";
    }
    cout << endl;

    // Voyons le tri de ce tableau en utilisant les tas :
    Tas P(m);
    P.TriTas(m, R);
    for(int i = 0; i < n; i ++) {
        cout << R[i] << " ";
    }
    cout << endl;
}
