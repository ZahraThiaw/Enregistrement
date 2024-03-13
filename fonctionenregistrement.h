#ifndef FONCTION_H
#define FONCTION_H


struct Point {
    float x;
    float y;
};
typedef struct Point Point;
float distance(Point A, Point B);
float racine(float x);
struct Animal {
    char categorie[50];
    float poids;
    char dateNaissance[11];
};
typedef struct Animal Animal;
int saisinombreanimaux ();
void saisirAnimal(struct Animal *animal);
void afficherAnimal(struct Animal animal);
void saisirAnimaux(Animal* tableau, int taille);
void afficherAnimaux(Animal* tableau, int taille);
int estCheval(Animal animal);
void chevauxNonPresent(Animal* tableau1, int taille1, Animal* tableau2, int taille2, Animal* resultat, int* tailleResultat);


#endif