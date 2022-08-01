#include<stdio.h>
#include<stdlib.h>
#include "fonction.h"

int main(void){
    int nat,n;
    printf("-------------------------------------- RESOLUTION DU PIVOT DE GAUSS JORDAN ------------------------------------\nNotre travail s'occupe de resoudre trois equations as trois inconnue qui seras donc dans une matrice,\non veut resourdre l'equation  A*X=b  !!!!\n");
    printf(" entrer le nombre de valeur inconnue de votre systeme :");
    scanf("%d",&n);
    printf(" MATRICE A\n");
    int **A;
    A=alloue_matrice(n);
    A=lire_clavier(n);
    affiche_matrice(A,n);
    printf(" MATRICE b\n");
    int *b,*sol;
    b=alloue_vecteur(n);
    sol=alloue_vecteur(n);
    b=remplire_vecteur(n);
    affiche_vecteur(b,n);
    nat = type_matrice(A,n);
    if(n == 4){
        printf("nous allons dabord trianguler notre matrice A \n on obtient \n");
        elemination_de_gauss(A,n,b);
        affiche_matrice(A,n); 
        printf(" et les valeurs ont ete modifier sur b");
        affiche_vecteur(b,n);
    }
    printf("notre systeme est donc \n\n");
    afficher_systeme_lineaire(n,b,A);
    printf(" apres resolution on obtient comme resultat les valeurs   \n");
    if( n==4 || n==3 ){
        sol= solution_superieure(A,n,b);
    }
    if( n==1){
        sol= solution_diagonale(A,n,b);
    }
    if( n==2){
        sol= solution_inferieure(A,n,b);
    }
    affiche_vecteur(sol,n);
    return 0;
}

