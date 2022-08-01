#include<stdio.h>
#include<stdlib.h>
#include "fonction.h"

int** alloue_matrice(int n){
	int i;
	int **tab;
	tab=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		*(tab+i)=(int*)malloc(sizeof(int)*n);
	}
	return tab;
}

void affiche_matrice(int **tab,int n){
	int i,j;
    printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\t%d\t",tab[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

int** lire_clavier(int n){
	int i,j;
	int **tab;
	tab=alloue_matrice(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(" valeur ligne %d colone %d :",i+1,j+1);
			scanf("%d",&tab[i][j]);
		}
	}
	return tab ;
}

int matrice_inferieure(int **t,int n){
    int cp=0,ok=1,i,j;
    for(i=1;i<n;i++){
        cp+=1;
        for(j=0;j<cp;j++){
            if(  t[j][i] != 0 ){
                ok=0;
                break;
            }
        }
    }
    return ok;
}

int matrice_superieure(int **t,int n){
    int i,j,ok=1;
    int cp=0;
    for(i=1;i<n;i++){
        cp+=1;
        for(j=0;j<cp;j++){
            if(  t[i][j] != 0 ){
                ok=0;
                break;
            }
        }
    }
    return ok;
}

int type_matrice(int **t,int n){
    int ok1,ok2;
    ok1 = matrice_inferieure(t,n);
    ok2 = matrice_superieure(t,n);
    if( ok1 == 1 && ok2 == 1){
        printf("  votre matrice est diagonale\n");
        return 1;
    }
    else{
        if(ok1 == 1){
            printf(" votre matrice est triangulaire inferieure \n");
            return 2;
        }
        else{
            if(ok2 == 1){
                printf(" votre matrice est triangulaire superieure \n");
                return 3;
            }
            else{
                printf(" votre matrice est quelconque\n");
                return 4;
            }
        }
    }
}

int* alloue_vecteur(int n){
    int *tab = malloc(sizeof(int)*n);
    return tab;
}

int* remplire_vecteur(int n){
    int *tab = alloue_vecteur(n);
    int i;
    for(i=0;i<n;i++){
        printf("valeur ligne %d :",i+1);
        scanf("%d",&tab[i]);
    }
    return tab;
}

void affiche_vecteur(int *tab,int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d \t",tab[i]);
    }
    printf("\n");
    printf("\n");
}

void elemination_de_gauss(int **t,int n,int *b){
    int k,i,j;
    int pivot,facto ;
    for(k=0;k<n-1;k++){
        pivot = t[k][k];
        for(i=k+1;i<n;i++){
            facto = pivot/t[i][k];
            printf("facto %d\n",facto);
            for(j=k;j<n;j++){
                t[i][j] =  t[i][j] - facto*t[k][j];
            }
            b[i] = b[i] -facto*b[k];
        }
    }
}

int* solution_superieure(int **t,int n,int *b){
    int *x=alloue_vecteur(n);
    int i,j;
    x[n-1] = b[n-1] /t[n-1][n-1];
    for(i=n-2;i>=0;i--){
        for(j=i+1;j<n;j++){
            b[i] = b[i] -t[i][j]*x[j];
        }
        x[i] = b[i]/t[i][i];
    }
    return x;
}

int* solution_diagonale(int **t,int n,int *b){
    int *x=alloue_vecteur(n);
    int i;
    for(i=0;i<n;i++){
        x[i] = b[i]/t[i][i];
    }
    return x;
}

int* solution_inferieure(int **t,int n,int *b){
    int *x=alloue_vecteur(n);
    int i,j;
    x[0] = b[0] /t[0][0];
    for(i=1;i<n;i++){
        for(j=0;j<=i;j++){
            b[i] = b[i] -t[i][j]*x[j];
        }
        x[i] = b[i]/t[i][i];
    }
    return x;
}

void afficher_systeme_lineaire(int n,int *b,int **a){
    int i,j;
    for(i=0;i<n;i++){
        printf("(");
        for(j=0;j<n;j++){
            printf("%d   ",a[i][j]);
        }
        printf(" )(x%d) = %d\n",i,b[i]);
    }
}