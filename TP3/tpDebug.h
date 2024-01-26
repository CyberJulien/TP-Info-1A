// il manque surement des includes, à vos recherches !




#define TAILLE_MAT 4

double mat1[TAILLE_MAT][TAILLE_MAT];
double mat2[TAILLE_MAT][TAILLE_MAT];
double result[TAILLE_MAT][TAILLE_MAT];

void une_somme_pas_si_simple(int n);

void premiere_fonction();

void juste_une_boucle();

double juste_une_somme(double a, double b);

void une_autre_somme(double* c, double a, double b);

void change_juste_une_lettre(char* mot, int position, char lettre);
void deccalage(int entree);

void init_mat();
void affiche_mat();
void soustration_de_matrice(double result[][TAILLE_MAT], double mat1[][TAILLE_MAT], double mat2[][TAILLE_MAT], int n);

int fonction_recursive(int n);