#include <iostream>
#include "tri.h"
using namespace std;

int main() {
    int n = 10; //Taille du tableau
    int T[n];

    cout << "Tableau initial :" << endl;
    Remplir(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tri fusion croissant :" << endl;
    TriFusion(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tableau remis à zéro :" << endl;
    Remplir(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tri fusion décroissant :" << endl;
    TriFusionDesc(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tableau remis à zéro :" << endl;
    Remplir(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tri rapide :" << endl;
    TriRapide(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tableau remis à zéro :" << endl;
    Remplir(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tri rapide décroissant :" << endl;
    TriRapideDesc(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Tableau remis à zéro :" << endl;
    Remplir(T, n);
    Afficher(T, n);
    cout << endl;

    cout << "Test de la fonction sort :" << endl;
    std::string type = "Fusion";
    char sens = 'd';
    sort(T, n, type, sens);
    Afficher(T, n);
}
