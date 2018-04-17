#include <iostream>
#include "tri.h"
#include <time.h>
using namespace std;

void Remplir(int T[], int size) { //Affecte des nb aléatoires au T
    srand(time(NULL));
    int nbgen = rand()%99+1;    //nb aléatoires entre 1-99
    for(int i = 0; i < size; i ++) {
        T[i] = nbgen;
        nbgen = rand()%99+1;
    }
}

void Afficher(int T[], int size) {
    for(int i = 0; i < size; i ++) {
        cout << T[i] << "|";
    }
    cout << endl;
}

/*####################
### - TRI FUSION - ###
######################*/

void Fusion(int T[], int deb1, int fin1, int fin2) {
    int R[fin1 - deb1 + 1];
    int deb2 = fin1 + 1;
    int c1 = deb1;
    int c2 = deb2;
    int i;

    for(i = deb1; i <= fin1; i++) {
        R[i-deb1] = T[i];
    }

    for(i = deb1; i <= fin2; i++) {
        if (c1 == deb2) {
            break;
        }
        else if (c2==(fin2+1)) {
            T[i] = R[c1 - deb1];
            c1++;
        }
        else if (R[c1 - deb1] < T[c2]) {
            T[i] = R[c1 - deb1];
                c1++;
        }
        else {
            T[i] = T[c2];
            c2++;
        }
    }
}

void TriFusionBis(int T[], int deb, int fin) {
    if(deb != fin) {
        int milieu = (fin + deb) / 2;
        TriFusionBis(T, deb, milieu);
        TriFusionBis(T, milieu + 1, fin);
        Fusion(T, deb, milieu, fin);
    }
}

void TriFusion(int T[], int n) {
     if(n > 0) {
        TriFusionBis(T, 0, n-1);
    }
}
/*########################
### - FIN TRI FUSION - ###
##########################

_________________________________________________

######################
### - TRI RAPIDE - ###
######################*/

void Echanger(int T[], int a, int b) {
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

int Partitionnement(int T[], int deb, int fin) {
    int c = deb;
    int pivot = T[deb];

    for(int i = deb + 1; i <= fin; i++) {
        if(T[i] < pivot) {
            c++;
            Echanger(T, c, i);
        }
    }
    Echanger(T, c, deb);
    return c;
}

void TriRapideBis(int T[], int deb, int fin) {
    if(deb < fin) {
        int pivot = Partitionnement(T, deb, fin);
        TriRapideBis(T, deb, pivot - 1);
        TriRapideBis(T, pivot + 1, fin);
    }
}

void TriRapide(int T[], int n) {
    TriRapideBis(T, 0, n - 1);
}

/*########################
### - FIN TRI RAPIDE - ###
##########################

_____________________________________________

##################################
### - TRI FUSION DECROISSANT - ###
##################################*/

void FusionDesc(int T[], int deb1, int fin1, int fin2) {
    int R[fin1 - deb1 + 1];
    int deb2 = fin1 + 1;
    int c1 = deb1;
    int c2 = deb2;
    int i;

    for(i = deb1; i <= fin1; i++) {
        R[i-deb1] = T[i];
    }

    for(i = deb1; i <= fin2; i++) {
        if (c1 == deb2) {
            break;
        }
        else if (c2 == (fin2 + 1)) {
            T[i] = R[c1 - deb1];
            c1++;
        }
        else if (R[c1 - deb1] > T[c2]) {
            T[i] = R[c1 - deb1];
                c1++;
        }
        else {
            T[i] = T[c2];
            c2++;
        }
    }
}

void TriFusionBisDesc(int T[], int deb, int fin) {
    if(deb != fin) {
        int milieu = (fin + deb) / 2;
        TriFusionBisDesc(T, deb, milieu);
        TriFusionBisDesc(T, milieu + 1, fin);
        FusionDesc(T, deb, milieu, fin);
    }
}

void TriFusionDesc(int T[], int n) {
     if(n > 0) {
        TriFusionBisDesc(T, 0, n-1);
    }
}

/*####################################
### - FIN TRI FUSION DECROISSANT - ###
######################################

_________________________________________

##################################
### - TRI RAPIDE DECROISSANT - ###
##################################*/

int PartitionnementDesc(int T[], int deb, int fin) {
    int c = deb;
    int pivot = T[deb];

    for(int i = deb + 1; i <= fin; i++) {
        if(T[i] > pivot) {
            c++;
            Echanger(T, c, i);
        }
    }
    Echanger(T, c, deb);
    return c;
}

void TriRapideBisDesc(int T[], int deb, int fin) {
    if(deb < fin) {
        int pivot = PartitionnementDesc(T, deb, fin);
        TriRapideBisDesc(T, deb, pivot - 1);
        TriRapideBisDesc(T, pivot + 1, fin);
    }
}

void TriRapideDesc(int T[], int n) {
    TriRapideBisDesc(T, 0, n - 1);
}

/*####################################
### - FIN TRI RAPIDE DECROISSANT - ###
######################################*/

void sort(int T[], int n, std::string type, char sens) {
    if(sens == 'c') {
        if(type == "Fusion") {
            TriFusion(T, n);
        }
        if(type == "Quicksort") {
            TriRapide(T, n);
        }
    }
    if(sens == 'd') {
        if(type == "Fusion") {
            TriFusionDesc(T, n);
        }
        if(type == "Quicksort") {
            TriRapideDesc(T, n);
        }
    }
}
