#include <stdio.h>
#include <stdlib.h>

struct lol {
    int val;
    struct lol *suiv;
    struct lol *prec;
};

struct lol *createLol(int valeur) {
    struct lol *newlol = (struct lol*)malloc(sizeof(struct lol));
    if (newlol == NULL) {
        printf("Erreur d'allocation mémoire!\n");
        exit(1);
    }
    newlol->val = valeur;
    newlol->suiv = newlol;
    newlol->prec = newlol;
    return newlol;
}

void InsertTete(struct lol **tete, int valeur) {
    struct lol *newlol = createLol(valeur);
    
    if (*tete == NULL) {
        *tete = newlol;
    } else {
        struct lol *last = (*tete)->prec; // le dernier noeud 
        
        // connecter le nouveau noeud
        newlol->suiv = *tete;
        newlol->prec = last;
        
        // mettre à jour les noeuds environnants
        last->suiv = newlol;
        (*tete)->prec = newlol;
        
        // mettre à jour la tête
        *tete = newlol;
    }
}

void InsertFin(struct lol **tete, int valeur) {
    struct lol *newlol = createLol(valeur);
    
    if (*tete == NULL) {
        *tete = newlol;
    } else {
        struct lol *last = (*tete)->prec; // le dernier noeud
        
        // connecter le nouveau noeud
        newlol->suiv = *tete;
        newlol->prec = last;
        
        // mettre à jour les noeuds environnants
        last->suiv = newlol;
        (*tete)->prec = newlol;
        // la tête reste inchangée
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


int main() {
    struct lol *liste = NULL;
    printf("\n=============================================\n");
    printf("Liste circulaire doublement chainée circulaire\n");
    printf("================================================\n");

    int a, b;
    do {
        printf("\n1. Insertion en tête de liste\n");
        printf("2. Insertion en fin de liste\n");
        printf("3. Affichage de la liste\n");
        printf("4. Quitter\n");
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
                printf("Affichage de la liste\n");
                display(liste);
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while(b != 4);
    
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