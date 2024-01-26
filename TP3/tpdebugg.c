

int maine(){
    
    
    // change_juste_une_lettre("Classe", 6, 'i');
    
}


/*void une_somme_pas_si_simple(int n)
{
    // ici plutôt que de modifier sauf erreurs bloquantes faites plusieurs 
    // sommes à la suite pour pouvoir comparer 
    // les différentes solutions
    
    float sumf = 0;

    for(int i=0; i<n ; i++){
        sumf += 1/n;
    }
    printf("La somme vaut :                 %.6f \n", sumf);
   

}*/

/*
void PremiereFonction()
{
    printf("Hello World !")
}

*/

/*
void juste_une_boucle(){
    int tab[] = {1, 2, 3, 4};
    int sum = 0;

    for(int i = 1; i =< 4;i++)
    {
        int sum = sum + tab[i];
    
    
    // partie à ne pas modifier
    if(sum != 10)
    {
        printf("la somme n'est pas bonne, sum=  %d \n", sum);
    }
    // fin partie à ne pas modifier
}
*/

/*
void juste_une_somme(int a, int b){
    int retour = a + b;
}
*/

/*
void deccalage(int entree){
    int offset;

    if(entree >10){
        int offset = 1:
        //printf("presence d'un offset de 1 \n);
    }else
        int offset = 2;
        //printf("presence d'un offset de 2 \n);

    printf("le resultat est %d + %d = %d", entree, offset, entree + offset); // ne pas modifier cette ligne
}
*/




/*
void une_autre_somme(double LeSuperResultat, double unNomDeVariable, double unAutreNomDeVariable){
    LeSuperResultat = unNomDevariable + unAutreNomDeVariable;
}
*/

/*
void change_juste_une_lettre(char* mot, int position, char lettre){
    printf("L'ancien mot est : %s \n", mot);
    mot[position] = lettre;
    printf("Le nouveau mot est : %s \n", mot);
}
*/

/*
void soustration_de_matrice(double** result, double** mat1, double** mat2, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void init_mat(){
    for(int i = 0; i < TAILLE_MAT; i++){
        for(int j = 0; j < TAILLE_MAT; j++){
            mat1[i][j] = i+j;
            mat2[i][j] = i*j;
            result[i][j] = 0;
        }
    }
}

void affiche_mat(){
    printf("%lf", result);
}


*/
/*
void deccalage(int entree){
    int offset;

    if(entree >10){
        printf("presence d'un offset de 1 \n");
        int offset = 1:
    }else{
        int offset =2;
        printf("presence d'un offset de 2 \n");
    }
    printf("le resultat est %d", entree + offset);
}

*/

/*
void jeu_aleatoire(int max){
    //https://koor.fr/C/cstdlib/rand.wp
   
   
    int searchedValue = rand() % max;       // % => Reste de la division entière
    int editedValue;
    int score = 0;
    printf( "MegaGame V1.0 - Valeur secrete \n");

    while(1);
    {
        printf( "Veuillez saisir un entier (entre 0 et %d) : ", max );
        fflush( stdout );
        scanf( "%d", & editedValue );
        score++;

        if ( editedValue == searchedValue ) {
            printf( "Felicitation : trouve en %d coups !\n", score );
            break;      // intérrompre la boucle 
        }
        if ( editedValue < searchedValue ) {
            printf( "La valeur a trouver est plus grande.\n" );
        } else {
            printf( "La valeur a trouver est plus petite.\n" );
        }
    }    
}

*/


/*
int fonction_recursive(int n){
    if(n=0){return 1;} else {return n * fonction_recursive(n-1);}
}


*/

