#include "abr.h"
#include <iostream>
using namespace std;

ABR::ABR() {
    info = 0;
    fg = NULL;
    fd = NULL;
    pere = NULL;
}

ABR::ABR(int x) {
    info = x;
    fg = NULL;
    fd = NULL;
    pere = NULL;
}

int ABR::key() {
	return(info);
}

ABR::~ABR() {
    if(fg) delete fg;
    if(fd) delete fd;
}

void ABR::Insertion(int x) {
    ABR *tmp = this;
    while(tmp != NULL) {
        if(tmp->info > x) {
            if(tmp->fg) {
                tmp = tmp->fg;
            }
            else {
                tmp->fg = new ABR(x);
                return; //Le noeud a été créé.
            }
        }
        else if(tmp->info < x) {
            if(tmp->fd) {
                tmp = tmp->fd;
            }
            else {
                tmp->fd = new ABR(x);
                return; //Le noeud a été créé.
            }
        }
        else if(tmp->info == x) {
            return; //Le noeud existe déjà.
        }
    }
}

void ABR::Affiche() {
	if(fg) {
        fg->Affiche();
    }
    cout << " " << info << " ";
	if(fd) {
        fd->Affiche();
    }
}

int ABR::Hauteur() {
    int g, d;
    if(fg) {
        g = fg->Hauteur();
    }
    else {
        g = 0;
    }
	if(fd) {
        d = fd->Hauteur();
    }
    else {
        d = 0;
    }
    if(d < g) return g + 1;
    return d + 1;
}

bool ABR::Recherche(int cle) {
    ABR *tmp = this;
    while(tmp != NULL) {
        if(tmp->info == cle) return true;
        else if(tmp->info > cle) {
            tmp = tmp->fg;
        }
        else if(tmp->info < cle) {
            tmp = tmp->fd;
        }
    }
    return false;
}

ABR *ABR::Minimum() {
    ABR *tmp = this;
    while(tmp->fg != NULL) {
        tmp = tmp->fg;
    }
    return tmp;
}

ABR *ABR::Maximum() {
    ABR *tmp = this;
    while(tmp->fd != NULL) {
        tmp = tmp->fd;
    }
    return tmp;
}

ABR *ABR::Maximum(ABR *A) {
    ABR *tmp = A;
    while(tmp->fd != NULL) {
        tmp = tmp->fd;
    }
    return tmp;
}

ABR *ABR::Successeur(ABR* x) {
    if(x->fd) {
        return ((x->fd)->Minimum());
    }
    else {
        ABR *y = x->pere;
        while(y != NULL && x == y->fd) {
            x = y;
            y = y->pere;
        }
        return y;
    }
}

ABR *ABR::Predecesseur(ABR* x) {
    if(x->fg != NULL) {
        return ((x->fg)->Maximum());
    }
    ABR *y = x->pere;
    while(y != NULL && x == y->fg) {
        x = y;
        y = y->pere;
    }
    return y;
}
/*

ABR *ABR::Supprimer(ABR *&A) {
    ABR *B;
    if(A->fd) {
        B = A->fd->Minimum();
        A->info = B->info;
        delete B;
        return B;
    }
    else if(A->fg != NULL) {
        B = A->fg->Maximum();
        A->info = B->info;
        delete B;
        return B;
    }
    else {
        delete A;
        return A;
    }
}

ABR *ABR::Supprimer(ABR *A) {
    if(A->fg == NULL && A->fd == NULL) { //Cas 1 :
        if(A->pere) {
            A->pere = NULL;
        }
    }
    else if(A->fg == NULL && A->fd) {
        if(A->pere) {
            A->pere = NULL;
            A->pere->fd = A->fd;
        }
    }
    else if(A->fd == NULL && A->fg) {
        if(A->pere) {
            A->pere = NULL;
            A->pere->fg = A->fg;
        }
    }
}

void ABR::Supprimer(ABR *N) {
    if(N->fg == NULL && N->fd == NULL) {    //CAS 1 - N n'a aucun fils
        if(N->pere->fg == N) {
            N->pere->fg = NULL;
        }
        if(N->pere->fd == N) {
            N->pere->fd = NULL;
        }
        delete N;
    }
    if(N->fg != NULL && N->fd == NULL) {    //CAS 2 - N a un seul fils (à gauche).
        cerr << "CAS 2 - N a un seul fils (à gauche)." << endl;
        if(N->pere) {
            if(N->pere->fg == N) {
                cerr << "N est le fg de son père." << endl;
                N->pere->fg = N->fg;
            }
            if(N->pere->fd == N) {
                cerr << "N est le fd de son père." << endl;
                N->pere->fd = N->fg;
            }
        }
        delete N;
    }
    if(N->fd != NULL && N->fg == NULL) {    //CAS 2 - N a un seul fils (à droite).
        cerr << "CAS 2 - N a un seul fils (à droite)." << endl;
        if(N->pere) {
            if(N->pere->fg == N) {
                cerr << "N est le fg de son père." << endl;
                N->pere->fg = N->fd;
            }
            else if(N->pere->fd == N) {
                cerr << "N est le fd de son père." << endl;
                N->pere->fd = N->fd;
            }
        }
        else if(N->pere == NULL) {
            cerr << "N n'a pas de pere." << endl;
            N->fg = this; //Que faire ?
        }
        delete N;
    }
    if(N->fg != NULL && N->fd != NULL) {    //CAS 3 - N a deux fils.
        ABR *q = Maximum(N->fg);
        N->info = q->info;
        if(q->pere->fd == q) {
            q->pere->fd = NULL;
        }
        delete q;
    }
}
*/
