/*Soit un tableau de tableau d’artistes de taille N = 200.
Écrire un sous-programme qui détermine et affiche le pourcentage de présence de chaque type d’artiste dans le tableau. Un
artiste est caractérisé par son nom, son prénom, sa date de naissance et son type.*/

#include <stdio.h>
#include <string.h>

#define N 200
#define MAX_LENGTH 50

typedef struct {
    char nom[MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char date_naissance[MAX_LENGTH];
    char type[MAX_LENGTH];
} Artiste;

void calculerPourcentagePresence(Artiste tableau[N], int taille) {
    int i, j;
    int nbTotal = taille;
    int nbTypes = 0;
    char types[N][MAX_LENGTH];

    // Extraire les types d'artistes distincts
    for (i = 0; i < taille; i++) {
        int existe = 0;
        for (j = 0; j < nbTypes; j++) {
            if (strcmp(types[j], tableau[i].type) == 0) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            strcpy(types[nbTypes], tableau[i].type);
            nbTypes++;
        }
    }

    // Calculer le nombre d'artistes de chaque type
    for (i = 0; i < nbTypes; i++) {
        int nbArtisteType = 0;
        for (j = 0; j < taille; j++) {
            if (strcmp(types[i], tableau[j].type) == 0) {
                nbArtisteType++;
            }
        }
        // Afficher le pourcentage de présence de chaque type d'artiste
        printf("Pourcentage de %s : %.2f%%\n", types[i], (float)nbArtisteType / nbTotal * 100);
    }
}

int main() {
    Artiste tableau[N] = {
        {"Nom1", "Prenom1", "01/01/1990", "Type1"},
        {"Nom2", "Prenom2", "02/02/1991", "Type2"},
        // Ajouter d'autres artistes ici
    };

    // Appeler la fonction pour calculer et afficher le pourcentage de présence de chaque type d'artiste
    calculerPourcentagePresence(tableau, N);

    return 0;
}
