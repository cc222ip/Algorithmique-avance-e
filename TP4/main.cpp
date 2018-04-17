#include "abr.h"
#include <iostream>
using namespace std;

int main() {
    ABR A;

    cout << "Mon arbre :" << endl;
    A.Insertion(3);
    A.Insertion(2);
    A.Insertion(5);
    A.Insertion(4);
    A.Insertion(7);
    A.Insertion(8);
    A.Affiche();
    cout << endl << endl;
    cout << "Hauteur de l'arbre : " << A.Hauteur() << endl;

    int n = 3;
    cout << n << " est-il dans mon arbre ? " << A.Recherche(n) << endl;

    ABR *min = A.Minimum();
    ABR *max = A.Maximum();
    cout << "Minimum : " << min->key() << endl;
    cout << "Maximum : " << max->key() << endl;

    ABR *suiv = A.Successeur(min);
    cout << "Successeur de " << min->key() << " --> " << suiv->key() << endl;

    ABR *prec = A.Predecesseur(max);
    cout << "Predecesseur de " << max->key() << " --> " << prec->key() << endl;

    cout << endl;
//    A.Supprimer(max);
//    cout << "Suppression de " << max->key() << " : " << endl;
    A.Affiche();
    cout << endl;

    return 0;
}
