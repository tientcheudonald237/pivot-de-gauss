#ifndef __PROTOTYPE__H__
#define __PROTOTYPE__H__

    int** alloue_matrice(int n);
    int** lire_clavier(int n);
    int matrice_inferieure(int **t,int n);
    int matrice_superieure(int **t,int n);
    int type_matrice(int **t,int n);
    void affiche_matrice(int **tab,int n);
    int* alloue_vecteur(int n);
    int* remplire_vecteur(int n);
    void affiche_vecteur(int *tab,int n);
    void elemination_de_gauss(int **t,int n,int *b);
    int* solution_superieure(int **t,int n,int *b);
    int* solution_diagonale(int **t,int n,int *b);
    int* solution_inferieure(int **t,int n,int *b);
    void afficher_systeme_lineaire(int n,int *b,int **a);

#endif