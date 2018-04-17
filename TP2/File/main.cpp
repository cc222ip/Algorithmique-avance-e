#include <iostream>
#include "file.h"
using namespace std;

int main() {
  cout << endl;
  File F;
  F.Enfiler(3);
  F.Enfiler(2);
  F.Enfiler(7);
  F.Enfiler(4);
  F.Enfiler(9);
  cout << "- File F formée de 5 chiffres enfilés : ";
  F.afficher();
  cout << endl;

  F.Defiler();
  F.Defiler();
  cout << "- File F après 2 Defiler() : ";
  F.afficher();
  cout << endl;
}
