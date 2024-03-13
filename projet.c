#include <stdio.h>
#include <stdlib.h> 
FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
int fclose(FILE* pointeurSurFichier);
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
 
    fichier = fopen("test.txt", "w");
 
    if (fichier != NULL)
    {
        fputc('A', fichier); // Écriture du caractère A
        fclose(fichier);
    }
 
    return 0;
}