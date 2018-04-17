#include <iostream>
using namespace std;

class Tas {
    int *T;
    int n;
    int queue;

    public :
        Tas(int max);
        ~Tas();
        int pere(int i);
        int fg(int i);
        int fd(int i);
        void ajout(int x);
        void afficher();
        int suppression();
        bool estvide();
        int taille();
        void TriTas(int m, int R[]);
};

void echanger(int &a, int &b);
int argmin(int a, int b);
