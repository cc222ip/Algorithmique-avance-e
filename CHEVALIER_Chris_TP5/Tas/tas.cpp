#include "tas.h"
#include <time.h>

Tas::Tas(int max) { // Constructeur de Tas ??
    n = max;
    T = new int[n];
    queue = 0;
}

Tas::~Tas() {
    delete[] T;
}

void echanger(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Tas::pere(int i) {
    return i/2;
}

int Tas::fg(int i) {
    return 2*i;
}

int Tas::fd(int i) {
    return (2 * i) + 1;
}

void Tas::ajout(int v) {
    int i = queue + 1;
    T[i] = v;
    if(i % 2 == 0) { // Si le noeud est un fils gauche
        while(T[i / 2] >= T[i]) {
            echanger(T[i], T[i / 2]);
            i = i / 2;
        }
    }
    else if(i % 2 == 1) { // Si le noeud est un fils droit
        while(T[(i - 1) / 2] >= T[i]) {
            echanger(T[i], T[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    queue = queue + 1;
}

void Tas::afficher() {
    for(int i = 1; i <= queue; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
}

int argmin(int a, int b) {
    if(a < b) {
        return a;
    }
    return b;
}

int Tas::suppression() {
    int res = T[1];
    T[1] = T[queue];
    int i = 1;
    int m = argmin(T[fg(i)], T[fd(i)]);
    while((i <= queue / 2) && (T[i] > T[m])) {
        echanger(T[i], T[m]);
        i = m;
        m = argmin(T[fg(i)], T[fd(i)]);
    }
    queue = queue - 1;
    return res;
}

bool Tas::estvide() {
    if(queue == 0) {
        return true;
    }
    return false;
}

int Tas::taille() {
    return queue;
}

void Tas::TriTas(int m, int R[]) {
    for(int i = 0; i < m; i++) {
        ajout(R[i]);
    }
    for(int i = 0; i < m; i++) {
        R[i] = suppression();
    }
}
