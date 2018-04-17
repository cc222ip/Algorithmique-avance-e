class ABR {
    ABR *fg;
    ABR *fd;
    ABR *pere;
    int info;

    public:
        ABR();
        ABR(int);
        int key();
        ~ABR();
        void Insertion(int);
        void Affiche();
        //void Affiche(int);
        bool Recherche(int);
        ABR *Minimum();
        ABR *Maximum();
        ABR *Maximum(ABR *A);
        ABR *Successeur(ABR*);
        ABR *Predecesseur(ABR*);
        int Hauteur();
//        void Supprimer(ABR*);

};
