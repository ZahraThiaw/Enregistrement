/*Écrire un sous-programme qui permet de supprimer une valeur d’un ta les
données des produits périmés dans un tableau de produits.
Un produit est caractérisé par son code, son libellé, son prix, sa quantité et
sa date de péremption.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un produit
typedef struct {
    int code;
    char libelle[50];
    float prix;
    int quantite;
    char date_peremption[11]; // Sous forme de chaîne de caractères (jj/mm/aaaa)
} Produit;

// Fonction pour supprimer les produits périmés
void supprimerProduitsPerimes(Produit *tableauProduits, int *tailleTableau, char dateActuelle[11]) {
    int i, j;

    for (i = 0; i < *tailleTableau; i++) {
        // Vérifier si la date de péremption est antérieure à la date actuelle
        if (strcmp(tableauProduits[i].date_peremption, dateActuelle) < 0) {
            // Décaler les éléments du tableau pour remplir l'espace du produit périmé
            for (j = i; j < *tailleTableau - 1; j++) {
                tableauProduits[j] = tableauProduits[j + 1];
            }
            (*tailleTableau)--; // Réduire la taille du tableau
            i--; // Décrémenter i pour vérifier le nouvel élément à cette position
        }
    }
}

// Fonction principale pour tester le sous-programme
int main() {
    // Exemple de tableau de produits
    Produit produits[] = {
        {1, "Produit 1", 10.50, 5, "01/03/2024"},
        {2, "Produit 2", 15.75, 3, "15/02/2024"},
        {3, "Produit 3", 8.20, 7, "20/04/2023"},
        // Ajoutez d'autres produits au besoin
    };
    int tailleTableau = sizeof(produits) / sizeof(produits[0]);
    
    char dateActuelle[11] = "04/03/2024"; // Date actuelle
    
    // Supprimer les produits périmés
    supprimerProduitsPerimes(produits, &tailleTableau, dateActuelle);

    // Afficher les produits restants après suppression des produits périmés
    printf("Produits restants :\n");
    for (int i = 0; i < tailleTableau; i++) {
        printf("Code: %d, Libelle: %s, Prix: %.2f, Quantite: %d, Date de peremption: %s\n",
               produits[i].code, produits[i].libelle, produits[i].prix, produits[i].quantite, produits[i].date_peremption);
    }

    return 0;
}
