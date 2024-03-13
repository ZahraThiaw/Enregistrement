#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fonctionenregistrement.h"


float distance(Point A, Point B) {
    float distance = racine((pow(B.x - A.x, 2) + pow(B.y - A.y, 2)));
}
float racine(float x) {
    return sqrt(x);
}
int saisinombreanimaux (){
    int nombreAnimaux;
    printf("Combien d'animaux voulez-vous saisir ? ");
    scanf("%d", &nombreAnimaux);
    return nombreAnimaux;
}
// Fonction de saisie d'un animal
void saisirAnimal(Animal *animal) {
    printf("Catégorie : ");
    scanf("%s", animal->categorie);
    printf("Poids : ");
    scanf("%f", &animal->poids);
    printf("Date de naissance (JJ/MM/AAAA) : ");
    scanf("%s", animal->dateNaissance);
}
// Fonction d'affichage d'un animal
void afficherAnimal(Animal animal) {
    printf("\nCatégorie : %s\n", animal.categorie);
    printf("Poids : %.2f\n", animal.poids);
    printf("Date de naissance : %s\n", animal.dateNaissance);
}
// Saisie des informations pour chaque animal
void saisirAnimaux(Animal* tableau, int taille) {
    int nombreAnimaux;
    printf("Saisissez les informations pour chaque animal :\n");
    for (int i = 0; i < nombreAnimaux; i++) {
        printf("Animal %d :\n", i + 1);
        saisirAnimal(&tableau[i]);
    }
}
void afficherAnimaux(Animal* tableau, int taille) {
    printf("Animaux :\n");
    for (int i = 0; i < taille; i++) {
        afficherAnimal(tableau[i]);
    }
}
// Fonction pour vérifier si un animal est un cheval
int estCheval(Animal animal) {
    return strcmp(animal.categorie, "cheval") == 0;
}
// Sous-programme pour créer un nouveau tableau contenant  les chevaux du premier tableau qui ne sont pas dans le second
void chevauxNonPresent(Animal* tableau1, int taille1, Animal* tableau2, int taille2, Animal* resultat, int* tailleResultat){
    *tailleResultat = 0; // Initialise la taille du tableau résultat à zéro
    // Parcourt le premier tableau contenant tous les animaux
    for (int i = 0; i < taille1; i++) {
        // Vérifie si l'animal est un cheval et n'est pas présent dans le deuxième tableau
        if (estCheval(tableau1[i])) {
            int present = 0;
            for (int j = 0; j < taille2; j++) {
                if (strcmp(tableau1[i].categorie, tableau2[j].categorie) == 0 && tableau1[i].poids == tableau2[j].poids && strcmp(tableau1[i].dateNaissance, tableau2[j].dateNaissance) == 0) {
                    present = 1;
                    break;
                }
            }
            // Si l'animal est un cheval et n'est pas présent dans le deuxième tableau, l'ajouter au tableau résultat
            if (!present) {
                resultat[*tailleResultat] = tableau1[i];
                (*tailleResultat)++;
            }
        }
    }
}
