/*Créer une structure « Point » contenant une abscisse (x) et une ordonnée (y)
Définissez un type « Point » pour cette structure.
Créer une fonction prenant en paramètre deux « Point » puis calcule et affiche
la distance entre ces deux points.
Soit A(Xa, Ya), B(Xb, Yb) , Dist(A,B)=√(〖(Xb-Xa)〗^2+〖(Yb-Ya)〗^2 )
On suppose avoir une fonction nommée racine qui permet de calculer la racine
carré.*/

#include <stdio.h>
#include <math.h>
#include "fonctionenregistrement.h"


int main() {
    // Déclaration et initialisation des points A et B
    Point A = {3, 4}; // A(Xa, Ya)
    Point B = {6, 8}; // B(Xb, Yb)

    // Calcul de la distance entre A et B
    float dist = distance(A, B);

    // Affichage du résultat
    printf("La distance entre les points A et B est : %.2f\n", dist);

    return 0;
}
