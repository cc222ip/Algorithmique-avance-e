class Noeud {
    friend class Arbre;
    char *nom; //Remplace info
    Noeud *fg;
    Noeud *frd;
    Noeud *pere;

    public:
        Noeud();
        ~Noeud();
};

class Arbre {
    friend class Noeud;
    Noeud *root;
    Noeud *current;

    public:
        Arbre();
        ~Arbre();
};
