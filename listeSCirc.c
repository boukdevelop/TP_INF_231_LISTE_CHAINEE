#include <stdio.h>
#include <stdlib.h>

struct lol {
    int val;
    struct lol *suiv;
    struct lol *prec;
};

struct lol *createLol(int valeur) {
    struct lol *newlol = (struct lol*)malloc(sizeof(struct lol));
    newlol->val = valeur;
    newlol->suiv = newlol; // Pointe vers elle-même pour une liste circulaire
    newlol->prec = newlol; // Pointe vers elle-même pour une liste circulaire
    return newlol;
}

void InsertTete(struct lol **tete, int valeur) {
    struct lol *newlol = createLol(valeur);
    
    if (*tete == NULL) {
        *tete = newlol;
    } else {
        struct lol *temp = *tete;
        // Parcourir jusqu'au dernier élément
        while (temp->suiv != *tete) {
            temp = temp->suiv;
        }
        newlol->suiv = *tete;
        temp->suiv = newlol;
        *tete = newlol;
    }
}

void InsertFin(struct lol **tete, int valeur) {
    struct lol *newlol = createLol(valeur);
    
    if (*tete == NULL) {
        *tete = newlol;
    } else {
        struct lol *temp = *tete;
        while (temp->suiv != *tete) {
            temp = temp->suiv;
        }
        temp->suiv = newlol;
        newlol->suiv = *tete;
    }
}

void display(struct lol *tete) {
    if (tete == NULL) {
        printf("Liste vide!\n");
        return;
    }
    
    struct lol *temp = tete;
    printf("Liste : ");
    do {
        printf("%d -> ", temp->val);
        temp = temp->suiv;
    } while (temp != tete);
    printf("(retour à tête)\n");
}

void suppression_tete(struct lol **tete) {
    if (*tete == NULL) {
        printf("Liste déjà vide!\n");
        return;
    }
    
    if ((*tete)->suiv == *tete) { // Un seul élément
        free(*tete);
        *tete = NULL;
    } else {
        struct lol *temp = *tete;
        struct lol *dernier = *tete;
        while (dernier->suiv != *tete) {
            dernier = dernier->suiv;
        }
        *tete = (*tete)->suiv;
        dernier->suiv = *tete;
        free(temp);
    }
    printf("Élément en tête supprimé.\n");
}

void deleteEnd(struct lol **tete) {
    if (*tete == NULL) {
        printf("Liste déjà vide!\n");
        return;
    }
    
    if ((*tete)->suiv == *tete) { // Un seul élément
        free(*tete);
        *tete = NULL;
    } else {
        struct lol *temp = *tete;
        struct lol *prev = NULL;
        while (temp->suiv != *tete) {
            prev = temp;
            temp = temp->suiv;
        }
        prev->suiv = *tete;
        free(temp);
    }
    printf("Élément en fin supprimé.\n");
}

int main() {
    struct lol *liste = NULL;
    printf("\n=================================\n");
    printf("Liste circulaire simplement chainée\n");
    printf("===================================\n");

    int a, b;
    do {
        printf("\n1. Insertion en tête de liste\n");
        printf("2. Insertion en fin de liste\n");
        printf("3. Suppression en tête de liste\n");
        printf("4. Suppression en fin de liste\n");
        printf("5. Affichage de la liste\n");
        printf("6. Quitter\n");
        printf("\nFaites un choix : ");
        scanf("%d", &b);
        
        switch(b) {
            case 1:
                printf("Insertion en tête\n");
                printf("Entrer une valeur : ");
                scanf("%d", &a);
                InsertTete(&liste, a); 
                display(liste);
                break;
            case 2:
                printf("Insertion en fin\n");
                printf("Entrer une valeur : ");
                scanf("%d", &a);
                InsertFin(&liste, a);
                display(liste);
                break;
            case 3:
                printf("Suppression en tête\n");
                suppression_tete(&liste);
                display(liste);
                break;
            case 4:
                printf("Suppression en fin\n");
                deleteEnd(&liste);
                display(liste);
                break;
            case 5:
                printf("Affichage de la liste\n");
                display(liste);
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while(b != 6);
    
    // Libération de la mémoire
    if (liste != NULL) {
        struct lol *courant = liste;
        struct lol *suivant;
        do {
            suivant = courant->suiv;
            free(courant);
            courant = suivant;
        } while (courant != liste);
    }

    return 0;
}