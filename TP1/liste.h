class Maillon {
  friend class Liste;
  int info;
  Maillon *suiv;
  Maillon *prec; //indispensable pour une liste doublement chainée.
};

class Liste {
  Maillon *tete;
  Maillon *queue; //indispensable pour une liste doublement chainée.

  public:
    Liste();
    ~Liste();
    void afficher();
    bool Vide();
    void InsertionTete(int x);
    void InsertionQueue(int x);
    Maillon *Recherche(int);
    void Suppression(Maillon *A);
    void Concatenation(Liste &T);
    Liste(const Liste &T);
};
