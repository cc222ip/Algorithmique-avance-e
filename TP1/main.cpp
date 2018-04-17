#include <iostream>
#include "liste.h"
using namespace std;

int main() {
  cout << endl;
  Liste L;
  L.InsertionTete(2);
  L.InsertionTete(5);
  L.InsertionTete(4);
  L.InsertionQueue(7);
  cout << "- Liste L formée d'insertions en tête et en queue : ";
  L.afficher();
  cout << endl;

  Maillon *A = L.Recherche(5);
  L.Suppression(A);
  cout << "- Suppression du maillon '5' : ";
  L.afficher();
  cout << endl;

  Liste T;
  T.InsertionTete(3);
  T.InsertionTete(2);
  T.InsertionTete(1);
  cout << "- Liste T : ";
  T.afficher();
  cout << endl;

  L.Concatenation(T);
  cout << "- Liste L concaténée à T : ";
  L.afficher();
  cout << endl;

  Liste L1 = Liste(T);
  cout << "- Liste L1 construite en copie de T : ";
  L1.afficher();
  cout << endl;
}
