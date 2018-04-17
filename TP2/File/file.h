class File {
  int tete;
  int queue;
  int *tab;
  int max;

  public:
    File();
    File(int n);
    ~File();
    bool Vide();
    bool Pleine();
    void Enfiler(int);
    int Defiler();
    void afficher();
};
