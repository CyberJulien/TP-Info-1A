#include <stdlib.h>
#include <stdio.h>

int* tableau_initial_pascal()
{
    int* tableau = malloc(sizeof(int)*3);
    tableau[0] = 0;
    tableau[1] = 1;
    tableau[2] = 0;
    return(tableau);
}

int* tableau_nouvelle_ligne(int* ligne, int n)
{
    int* nouvelle_ligne = malloc(sizeof(int)*(n+1));
    nouvelle_ligne[0] = 0;
    nouvelle_ligne[n] = 0;
    for(int i = 1; i<n; i++)
    {
        nouvelle_ligne[i] = ligne[i] + ligne[i-1];
    }
    return(nouvelle_ligne);
}

void affiche_pascal(int n)
{
    int* ligne_actuelle;
    int* ligne_precedente;
    ligne_actuelle=tableau_initial_pascal();
    for (int ligne = 0; ligne < n; ligne++)
{
        for (int colonne = 0; colonne <= ligne; colonne++)
        {
            printf("%i ", ligne_actuelle[colonne+1]);
        }
        printf("\n");
        ligne_precedente = ligne_actuelle;
        ligne_actuelle = tableau_nouvelle_ligne(ligne_actuelle, ligne + 3);
        free(ligne_precedente);
    }
    free(ligne_actuelle);
}

int main(){
    affiche_pascal(20);
}