#include "arbre.h"
#include <cstring>
#include <iostream>

Noeud::Noeud() {
    nom = (char *)"";
    pere = NULL;
    fg = NULL;
    frd = NULL;
}

Noeud::~Noeud() {
    if(nom) delete nom;
    if(pere) delete pere;
    if(fg) delete fg;
    if(frd) delete frd;
}

Arbre::Arbre() {
    root = new Noeud();
    root->fg = new Noeud();
    root->fg->frd = new Noeud();

    Noeud *DirRoot = root;
    Noeud *DirDot = root->fg;
    Noeud *DirDotDot = root->fg->frd;

    root->fg->frd = new Noeud();

    DirRoot->nom = (char *)"/";
    DirDot->nom = (char *)".";
    DirDotDot->nom = (char *)"..";

    current = new Noeud();
}

Arbre::~Arbre() {
    if(root) delete root;
    if(root->fg) delete root->fg;
    if(root->fg->frd) delete root->fg->frd;
    if(current) delete current;
}
