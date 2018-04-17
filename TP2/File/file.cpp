#include <iostream>
#include "file.h"
using namespace std;

File::File() {
  const int M = 1000;
  max = M;
  tete = queue = 0;
  tab = new int[max];
}

File::File(int n) {
  max = n;
  tete = queue = 0;
  tab = new int[max];
}

File::~File() {
  delete[] tab;
}

bool File::Vide() {
  if(tete == queue) return true;
  return false;
}

bool File::Pleine() {
  int tmp;
  if(queue == tete - 1) tmp = 0;
  tmp = queue + 1;
  if(tete == tmp) return true;
  return false;
}

void File::Enfiler(int x) {
  if(!Pleine()) {
      tab[queue] = x;
      if(queue == max - 1) {
        queue = 0;
      }
      else {
        queue = queue + 1;
      }
  }
  else {
    cout << "La file est pleine." << endl;
  }
}

int File::Defiler() {
  if(Vide()) {
    cerr << "La file est vide." << endl;
  }
  else {
    if(tete == max - 1) {
        tete = 0;
    }
    else {
        tete = tete + 1;
    }
  }
  return 0;
}

void File::afficher() {
  if(Vide()) {
    cerr << "La file est vide." << endl;
  }
  else {
    for(int i(tete); i < queue; i++) {
      cout << tab[i] << " ";
    }
    cout << endl;
  }
}
