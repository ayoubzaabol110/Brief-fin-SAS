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
void affichage() {
    if (nm == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }
    for (int i = 0; i < nm; i++) {
        printf("Tache %d\n", i + 1);
        printf("Titre: %s\n", tch[i].titre);
        printf("Description: %s\n", tch[i].description);
        printf("Date: %d/%d/%d\n", tch[i].date.jour, tch[i].date.mois, tch[i].date.annee);
        if (tch[i].priorite == 1) {
            printf("Priorité: High\n");
        } else if (tch[i].priorite == 2) {
            printf("Priorité: Low\n");
        } else {
            printf("Priorité: Inconnue\n");
        }
        printf("----------------------------\n");
    }
}
void modifier(tache tch[], int index) {
    if (index >= 0 && index < nm) {
        printf("Mise à jour des informations de la tâche %d\n", index + 1);

        printf("Nouveau titre: ");
        scanf("%s", tch[index].titre);
        printf("Nouvelle description: ");
        scanf("%s", tch[index].description);
        printf("Nouvelle priorité (1 pour High, 2 pour Low): ");
        scanf("%d", &tch[index].priorite);
        printf("Nouvelle date (jour mois année): ");
        scanf("%d %d %d", &tch[index].date.jour, &tch[index].date.mois, &tch[index].date.annee);
        printf("Informations mises à jour avec succès.\n");
    } else {
        printf("Index invalide.\n");
    }
}

void supprimer(int index) {
    if (index < 0 || index >= nm) {
        printf("Index invalide. Impossible de supprimer.\n");
    } else {
        for (int i = index; i <=nm; i++) {
            tch[i] = tch[i + 1];
        }
        nm--;
        printf("Tâche supprimée avec succès.\n");
    }
}
void filtrerParPriorite(int prioriteRecherchee) {
    int trouve = 0;
    printf("Tâches avec priorité ");

    if (prioriteRecherchee == 1) {
        printf("High:\n");
    } else if (prioriteRecherchee == 2) {
        printf("Low:\n");
    } else {
        printf("inconnue.\n");
        return;
    }
    for (int i = 0; i < nm; i++) {
        if (tch[i].priorite == prioriteRecherchee) {
            printf("Tâche %d\n", i + 1);
            printf("Titre: %s\n", tch[i].titre);
            printf("Description: %s\n", tch[i].description);
            printf("Date: %d/%d/%d\n", tch[i].date.jour, tch[i].date.mois, tch[i].date.annee);
            printf("----------------------------\n");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune tâche trouvée avec la priorité spécifiée.\n");
    }
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
         case 2:
                affichage();
                break;
        case 3:
                printf("Entrez l'index de la tâche à supprimer: ");
                scanf("%d", &index);
                supprimer(index - 1);
                break;
        case 4:
                printf("Entrez l'index de la tâche à modifier: ");
                scanf("%d", &index);
                modifier(tch, index - 1);
                break;
                 case 5:
                printf("Entrez la priorité à filtrer (1: High, 2: Low): ");
                scanf("%d", &priorite);
                filtrerParPriorite(priorite);
                break;
        }
        
    } while (choix != 6);

    return 0;
}
