#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionenregistrement.h"

int main() {
    // Déclaration et initialisation des tableaux d'animaux
    Animal tab1[450];
    Animal tab2[300];
    printf("le nombre d'animaux dans le tableau 1 :\n");
    int taille1=saisinombreanimaux ();
    saisirAnimaux();
    afficherAnimaux(tab1, taille1);

    printf("le nombre d'animaux dans le tableau 2 :\n");
    int taille2=saisinombreanimaux ();
    saisirAnimaux();
    afficherAnimaux(tab2, taille2);
    // Appel du sous-programme pour obtenir le nouveau tableau
    int tailleResultat;
    Animal resultat[tailleResultat];   
    chevauxNonPresent(tab1, taille1, tab2, taille2, resultat, &tailleResultat);
    // Affichage du nouveau tableau
    printf("Nouveau tableau :\n");
    afficherAnimaux(resultat, tailleResultat);
    return 0;
}