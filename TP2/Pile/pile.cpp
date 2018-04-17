#include <iostream>
#include "pile.h"
using namespace std;

Pile::Pile() {
  const int M = 1000;
  max = M;
  tete = -1;
  tab = new int[max]; //Taille du tableau ?
}

Pile::Pile(int n) {
  max = n;
}

Pile::~Pile() {
  delete[] tab;
}

bool Pile::Vide() {
  if(tete == -1) return true;
  return false;
}

bool Pile::Pleine() {
  if(tete == max - 1) return true;
  return false;
}

void Pile::afficher() {
  if(Vide()) {
    cerr << "La file est vide." << endl;
  }
  else {
    for(int i(0); i <= tete; i++) {
        cout << tab[i] << endl;
    }
  }
}

void Pile::Empiler(int x) {
  tete = tete + 1;
  tab[tete] = x;
}

int Pile::Depiler() {
  if(Vide()) {
    cerr << "Pile Vide" << endl;
  }
  else {
    tete = tete - 1;
    return tab[tete + 1];
  }
  return 0;
}
