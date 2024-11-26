#include <stdio.h>
#include <string.h>
typedef struct {
    int jour;
    int mois;
    int annee;
} Newdate;

typedef struct {
    char titre[30];
    char description[30];
    int priorite; // 1 for High, 2 for Low
    Newdate date;
} tache;
tache tch[10];
int nm = 0;
int dateValide(int jour, int mois, int annee) {
    if (annee < 1900 || annee > 2100) {
        return 0;
    }
    if (mois < 1 || mois > 12) {
        return 0;
    }
    if (jour < 1 || jour > 31) {
        return 0;
    }
    return 1;
}

// Function to add a task
void ajouter() {
 

    printf("Entrez les données de la tâche:\n");
    printf("Titre: ");
    scanf("%s", tch[nm].titre);
    printf("Description: ");
    scanf("%s", tch[nm].description);

    do {
        printf("Date (jour mois année): ");
        scanf("%d %d %d", &tch[nm].date.jour, &tch[nm].date.mois, &tch[nm].date.annee);
        if (!dateValide(tch[nm].date.jour, tch[nm].date.mois, tch[nm].date.annee)) {
            printf("Date invalide. Réessayez.\n");
        }
    } while (!dateValide(tch[nm].date.jour, tch[nm].date.mois, tch[nm].date.annee));

    printf("Priorité (1 pour High, 2 pour Low): ");
    scanf("%d", &tch[nm].priorite);

    nm++;
}

int main() {
  do {
        printf("1 - Ajouter une tâche :\n");
        printf("2 - Afficher les tâches :\n");
        printf("3 - Supprimer une tâche :\n");
        printf("4 - Modifier une tâche :\n");
        printf("5 - Filtrer les tâches par priorité\n");
        printf("0 - Quitter\n");
         printf("Entrez votre choix: ");
        scanf("%d", &choix);
switch (choix) {
            case 1:
                ajouter();
                break;
        }
        
    } while (choix != 0);

    return 0;
}
