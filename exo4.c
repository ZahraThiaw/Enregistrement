/*Ecrire un sous-programme qui permet de retourner la plus
vielle femme d’un tableau de personne. Une personne est
caractérisée par son nom, son prénom, son âge et son sexe.*/

#include <stdio.h>
#include <string.h>

// Structure pour représenter une personne
struct Personne {
    char nom[50];
    char prenom[50];
    int age;
    char sexe; // 'M' pour masculin, 'F' pour féminin
};

// Fonction pour trouver la plus vieille femme dans un tableau de personnes
struct Personne plusVieilleFemme(struct Personne personnes[], int taille) {
    struct Personne vieilleFemme;
    vieilleFemme.age = -1; // Initialisation de l'âge à une valeur négative pour s'assurer qu'il sera remplacé

    for (int i = 0; i < taille; i++) {
        if (personnes[i].sexe == 'F') { // Vérifier si la personne est une femme
            if (personnes[i].age > vieilleFemme.age) { // Vérifier si la femme est plus âgée que la précédente
                vieilleFemme = personnes[i];
            }
        }
    }
    return vieilleFemme;
}

int main() {
    // Exemple d'utilisation du sous-programme
    struct Personne personnes[] = {
        {"Doe", "Jane", 75, 'F'},
        {"Smith", "John", 65, 'M'},
        {"Johnson", "Emily", 80, 'F'},
        {"Williams", "Michael", 70, 'M'}
    };

    int taille = sizeof(personnes) / sizeof(personnes[0]);
    
    struct Personne vieilleFemme = plusVieilleFemme(personnes, taille);
    
    if (vieilleFemme.age != -1) {
        printf("La plus vieille femme est : %s %s, âgée de %d ans.\n", vieilleFemme.prenom, vieilleFemme.nom, vieilleFemme.age);
    } else {
        printf("Aucune femme n'a été trouvée dans le tableau.\n");
    }
    
    return 0;
}
