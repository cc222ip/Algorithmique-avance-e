#include <iostream>
using namespace std;

class Pile {
  int tete;
  int *tab;
  int max;

  public:
    Pile();
    Pile(int);
    ~Pile();
    void afficher();
    bool Vide();
    bool Pleine();
    void Empiler(int);
    int Depiler();
};
