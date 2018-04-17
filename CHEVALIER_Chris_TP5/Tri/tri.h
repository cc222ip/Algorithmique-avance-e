#include <cstring>
void Remplir(int T[], int size);
void Afficher(int T[], int size);

void Fusion(int T[], int deb1, int fin1, int fin2);
void TriFusionBis(int T[], int deb, int fin);
void TriFusion(int T[], int n);

void Echanger(int T[], int a, int b);
int Partitionnement(int T[], int a, int b, int m);
void TriRapideBis(int T[], int deb, int fin);
void TriRapide(int T[], int n);

void FusionDesc(int T[], int deb1, int fin1, int fin2);
void TriFusionBisDesc(int T[], int deb, int fin);
void TriFusionDesc(int T[], int n);


int PartitionnementDesc(int T[], int a, int b, int m);
void TriRapideBisDesc(int T[], int deb, int fin);
void TriRapideDesc(int T[], int n);


void sort(int T[], int n, std::string type, char sens);
