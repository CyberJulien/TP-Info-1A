#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
int** triangle(int n){ //génère un triangle de tableaux vide en utilisant les pointeur, tab[i][j] renvoie la ième ligne jème colonne
    int* tab[n];
    for (int i=0; i<n; i++)
    {
        tab[i] = malloc(sizeof(int)*(i+1));
    }
    return(tab);
}
*/

int print_pascal(int n)
{
    //scanf("%n", &n);
    //int** tab = triangle(n);
    int* tab[n];
    for (int i=0; i<n; i++)
    {
        tab[i] = malloc(sizeof(int)*(i+1));
    }
    // tab est de type int**
    for (int i=0; i<n; i++)
    {
        tab[i][0] = 1; //on met la première colonne à 1
        tab[i][i] = 1; //on met le dernier élément de chaque colonne à 1
        
    }
    for (int i=1; i<n; i++)
    {
        for (int j=1; j<i; j++)
        {
        tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (j != i)
            {
            printf( "%d ",tab[i][j]);
            }
            if (j == i)
            {
            printf( "%d \n",tab[i][j]);
            
            }
        }
    }
    for (int i=0; i<n; i++)
    {
    free(tab[i]);
    }
}

void main()
{
  int n = 0;  
  scanf("%d", &n);  
  print_pascal(n);

}





