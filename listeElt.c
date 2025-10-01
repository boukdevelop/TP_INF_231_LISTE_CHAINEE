/* ===Liste chianée simplement===
1. Lire un élément et supprimer toutes les occurence dans la liste */
#include <stdio.h>
#include <stdlib.h>

struct lol {
    int val;
    struct lol *suiv;
};

struct lol *createLol(int valeur){
    struct lol *newlol = (struct lol*)malloc(sizeof(struct lol));
    newlol->val = valeur;
    newlol->suiv = NULL;
    return newlol;
}

void InsertTete(struct lol **tete, int valeur){
    struct lol *newlol = createLol(valeur);
    newlol->suiv = *tete;
    *tete = newlol;
}

void InsertFin(struct lol **tete, int valeur){
    struct lol *newlol = createLol(valeur);
    
    if (*tete == NULL) {
        *tete = newlol;
        return;
    }

    struct lol *temp = *tete;
    while(temp->suiv != NULL){
        temp = temp->suiv;
    }
    temp->suiv = newlol; 
}


void display(struct lol *tete){
    if (tete == NULL) {
        printf("Liste vide!\n");
        return;
    }
    
    struct lol *temp = tete;
    printf("Liste : ");
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->suiv;
    }
    printf("NULL\n");
}

void suppression_tete(struct lol **tete){
    if (*tete == NULL) {
        printf("Liste déjà vide!\n");
        return;
    }
    
    struct lol *temp = *tete;
    *tete = (*tete)->suiv;
    free(temp);
    printf("Élément en tête supprimé.\n");
}

void deleteEnd(struct lol **tete){
    if (*tete == NULL) {
        printf("Liste déjà vide!\n");
        return;
    }
    
    // Cas particulier : un seul élément
    if ((*tete)->suiv == NULL) {
        free(*tete);
        *tete = NULL;
        return;
    }
    
    // Cas général : au moins deux éléments
    struct lol *temp = *tete;
    struct lol *prev = NULL;
    
    while(temp->suiv != NULL){
        prev = temp;
        temp = temp->suiv;
    }
    
    prev->suiv = NULL;
    free(temp);
    printf("Élément en fin supprimé.\n");
}

int main(){
    struct lol *liste = NULL;
    printf("\n======================\n");
    printf("Liste simplement chainée\n");
    printf("======================\n");

    int a, b;
    do{
        printf("\n1. Insertion en tête de liste\n");
        printf("2. Insertion en fin de liste\n");
        printf("3. Suppression en tête de liste\n");
        printf("4. Suppression en fin de liste\n");
        printf("5. Affichage de la liste\n");
        printf("6. Quitter\n");
        printf("\nFaites un choix : ");
        scanf("%d",&b);
        
        switch(b) {
            case 1:
                printf("Insertion en tête\n");
                printf("Entrer une valeur : ");
                scanf("%d",&a);
                InsertTete(&liste, a); 
                display(liste);
                break;
            case 2:
                printf("Insertion en fin\n");
                printf("Entrer une valeur : ");
                scanf("%d",&a);
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
    
    struct lol *temp;
    while(liste != NULL){
        temp = liste;
        liste = liste->suiv;
        free(temp);
    }

    return 0;
}