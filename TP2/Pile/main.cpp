#include <iostream>
#include "pile.h"
using namespace std;

int main() {
  cout << endl;
  Pile P;

  P.Empiler(4);
  P.Empiler(9);
  P.Empiler(5);
  P.Empiler(7);
  P.Empiler(6);
  cout << "- Pile P composée de 5 chiffres empilés : " << endl;
  P.afficher();
  cout << endl;

  P.Depiler();
  P.Depiler();
  cout << "- Pile P après 2 'Depiler()' : " << endl;
  P.afficher();
  cout << endl;
}
