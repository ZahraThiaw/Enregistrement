/*Soit deux tableaux d’animaux de taille respective N1 = 450 et N2 = 300.
Écrire un sous-programme qui crée un nouveau tableau contenant les
chevaux du premier tableau qui ne sont pas dans le second. Un animal est
caractérisé par sa catégorie, son poids et sa date de naissance (jj/mm/aaaa).*/

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
    saisirAnimaux(tab1, taille1);
    afficherAnimaux(tab1, taille1);

    printf("le nombre d'animaux dans le tableau 2 :\n");
    int taille2=saisinombreanimaux ();
    saisirAnimaux(tab2, taille2);
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
