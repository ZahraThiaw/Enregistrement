#include <stdio.h>
int autoIdEtudiant = 0;
int autoIdMatiere = 0;
typedef struct
{
    int j, m, a;

} DATE;

typedef struct
{
    int id;
    char nom[50];
    char prenom[50];
    DATE dn;

} ETUDIANT;

typedef struct
{
    int id;
    char libelle[50];
    int coef;

} MATIERE;
enum niveau
    {
        L1 = 1,
        L2,
        L3,
        M1,
        M2,
        M3
    };
typedef struct
{
    char libelle[50];
    MATIERE matieres[10];
    ETUDIANT etudiants[100];
    int nbrEtudiant;
    int nbrMatiere;
    enum niveau niveau;
} CLASSE;
enum type
    {
        DEVOIR=1,
        EXAMEN
    };
typedef struct
{
    ETUDIANT etudiant;
    MATIERE matiere;
    float note;
    enum type type;

} EVALUATION;
// prototype
void afficherDate(DATE);
DATE saisieDate(void);
int saisirInt(int, int, char[]);
ETUDIANT saisirEtudiant();
void afficherEtudiant(ETUDIANT e);
MATIERE saisirMatiere();
void afficherMatiere(MATIERE m);
CLASSE saisirClasse (int nbrEtudiant, int nbrMatiere);
void afficherClasse(CLASSE c);
EVALUATION saisirEvaluation();
void afficherEvaluation(EVALUATION e);

int main()
{
    // enum jour{LUNDI = 1,MARDI, MERCREDI, JEUDI,VENDREDI,SAMEDI,DIMANCHE};
    // enum jour j;
    // j = LUNDI;
    //afficherDate(saisieDate());
    afficherEtudiant(saisirEtudiant());
    afficherMatiere(saisirMatiere());
    afficherClasse(saisirClasse(10, 2));
    afficherEvaluation(saisirEvaluation());

    return 0;
}
DATE saisieDate(void)
{
    DATE d;
    puts("Entrez une date [j,m,a]");
   // scanf("%d%d%d", &d.j, &d.m, &d.a);
   d.j = saisirInt(1, 31, "entrez le jour");
   d.m = saisirInt(1, 12, "entrez le mois");
   d.a = saisirInt(1, 2024, "entrez l'année");
    return d;
}
void afficherDate(DATE a)
{
    printf("la date est %d-%d-%d", a.j, a.m, a.a);
}
int saisirInt(int min, int max, char msg[])
{
    int x;
    do
    {
        puts(msg);
        scanf("%d", &x);
    } while (x<min || x>max);
    return x;
}
void generermatricule(ETUDIANT e, int id){
    char matricule[50];
    sprintf(matricule, "%s-%s%s%d%d", "MAT", e.prenom, e.nom, e.id);
    printf("%s\n", matricule);
}
ETUDIANT saisirEtudiant(){
    ETUDIANT e;
    e.id = ++autoIdEtudiant;
    puts("Donnez le nom :");
    fgets(e.nom, sizeof(e.nom), stdin);
    puts("Donnez le prénom :");
    fgets(e.prenom , sizeof(e.prenom), stdin);
    e.dn = saisieDate();
    return e;
}
void afficherEtudiant(ETUDIANT e){
    printf("%d %s %s %d-%d-%d\n", e.id, e.nom, e.prenom, e.dn.j, e.dn.m, e.dn.a);
}
MATIERE saisirMatiere(){
    MATIERE m;
    m.id = ++autoIdMatiere;
    puts("Donnez le libelle :");
    fgets(m.libelle , sizeof(m.libelle), stdin);
    puts("Donnez le coef :");
    scanf("%d", &m.coef);
    return m;
}
void afficherMatiere(MATIERE m){
    printf("%d %s %d\n", m.id, m.libelle, m.coef);
}
CLASSE saisirClasse (int nbrEtudiant, int nbrMatiere){
    CLASSE c;
    puts("Donnez le libelle :");
    fgets(c.libelle , sizeof(c.libelle), stdin);
    c.nbrEtudiant = nbrEtudiant;
    c.nbrMatiere = nbrMatiere;
    for (int i = 0; i < c.nbrEtudiant; i++)
    {
        c.etudiants[i] = saisirEtudiant();
    }
    for (int i = 0; i < c.nbrMatiere; i++)
    {
        c.matieres[i] = saisirMatiere();
    }
    enum niveau l = saisirInt(1, 6, "entrez le niveau");
    return c;
}
void afficherClasse(CLASSE c){
    printf("%s\n", c.libelle);
    for (int i = 0; i < c.nbrEtudiant; i++)
    {
        afficherEtudiant(c.etudiants[i]);
    }
    for (int i = 0; i < c.nbrMatiere; i++)
    {
        afficherMatiere(c.matieres[i]);
    }
}
EVALUATION saisirEvaluation(){
    EVALUATION e;
    puts("Donnez le type DEVOIR=1, EXAMEN=2:");
    enum type t = saisirInt(1, 2, "entrez le type");
    e.etudiant = saisirEtudiant();
    e.matiere = saisirMatiere();
    puts("Donnez la note :");
    scanf("%f", &e.note);
    return e;
}
void afficherEvaluation(EVALUATION e){
    printf("%d %s %s %d-%d-%d %f\n", e.etudiant.id, e.etudiant.nom, e.etudiant.prenom, e.etudiant.dn.j, e.etudiant.dn.m, e.etudiant.dn.a, e.note);
}