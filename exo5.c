/*Écrire un sous-programme qui permet de faire l’union de deux tableaux
d'Étudiants. Un étudiant est caractérisé par son matricule, son nom, son
prénom et sa classe.*/

#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int matricule;
    char nom[50];
    char prenom[50];
    char classe[20];
} Etudiant;

void unionEtudiants(Etudiant etudiants1[], int taille1, Etudiant etudiants2[], int taille2, Etudiant resultat[], int *tailleResultat) {
    int i;
    *tailleResultat = 0;

    // Copier les étudiants du premier tableau dans le résultat
    for (i = 0; i < taille1; i++) {
        resultat[*tailleResultat] = etudiants1[i];
        (*tailleResultat)++;
    }

    // Vérifier les étudiants du deuxième tableau pour éviter les doublons
    for (i = 0; i < taille2; i++) {
        int j;
        int doublon = 0;

        for (j = 0; j < taille1; j++) {
            if (etudiants2[i].matricule == etudiants1[j].matricule &&
                strcmp(etudiants2[i].nom, etudiants1[j].nom) == 0 &&
                strcmp(etudiants2[i].prenom, etudiants1[j].prenom) == 0 &&
                strcmp(etudiants2[i].classe, etudiants1[j].classe) == 0) {
                doublon = 1;
                break;
            }
        }

        if (!doublon) {
            resultat[*tailleResultat] = etudiants2[i];
            (*tailleResultat)++;
        }
    }
}

int main() {
    Etudiant etudiants1[MAX_ETUDIANTS] = {
        {101, "Dupont", "Jean", "A"},
        {102, "Martin", "Marie", "B"},
        // Ajoutez d'autres étudiants au besoin...
    };
    int taille1 = 2;

    Etudiant etudiants2[MAX_ETUDIANTS] = {
        {103, "Dubois", "Pierre", "A"},
        {104, "Dufour", "Sophie", "C"},
        // Ajoutez d'autres étudiants au besoin...
    };
    int taille2 = 2;

    Etudiant resultat[MAX_ETUDIANTS];
    int tailleResultat;

    unionEtudiants(etudiants1, taille1, etudiants2, taille2, resultat, &tailleResultat);

    printf("Résultat de l'union :\n");
    for (int i = 0; i < tailleResultat; i++) {
        printf("Matricule : %d, Nom : %s, Prénom : %s, Classe : %s\n",
               resultat[i].matricule, resultat[i].nom, resultat[i].prenom, resultat[i].classe);
    }

    return 0;
}
