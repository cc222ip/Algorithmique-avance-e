#include <iostream>
#include "liste.h"
using namespace std;

Liste::Liste() {
  tete = queue = NULL;
}

Liste::~Liste() {
  if(tete) delete tete;
  if(queue) delete queue;
}

bool Liste::Vide() {
  if(tete == NULL) return true;
  return false;
}

void Liste::InsertionTete(int x) {
  Maillon *p = new Maillon;
  p->info = x;
  p->suiv = tete;
  p->prec = NULL;
  if(!Vide()) {
    tete->prec = p;
  }
  tete = p;
  if(p->suiv == NULL) queue = p;
}

void Liste::InsertionQueue(int x) {
  Maillon *p = new Maillon;
  p->info = x;
  p->suiv = NULL;
  p->prec = queue;
  if(!Vide()) {
    queue->suiv = p;
  }
  queue = p;
  if(Vide()) tete = p;
}

void Liste::afficher() {
  Maillon *p = tete;
  while(p) {
    cout << p->info << " ";
    p = p->suiv;
  }
  cout << endl;
}

Maillon *Liste::Recherche(int x) {
  Maillon *p = tete;
  while(p != NULL && p->info != x) {
    p = p->suiv;
  }
  return p;
}

void Liste::Suppression(Maillon *A) {
  if(A->prec != NULL) {
    (A->prec)->suiv = A->suiv;
  }
  else {
    tete = A->suiv;
  }
  if(A->suiv != NULL) {
    (A->suiv)->prec = A->prec;
  }
  delete A;
}

void Liste::Concatenation(Liste &T) {
  Maillon *p = T.tete;
  while(p != NULL) {
    InsertionQueue(p->info);
    p = p->suiv;
  }
}

Liste::Liste(const Liste &T) {
  tete = NULL;
  queue = NULL;
  Maillon *p = T.tete;
  while(p) {
    InsertionQueue(p->info);
    p = p->suiv;
  }
}
