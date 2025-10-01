#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *suivant;  // Un seul pointeur pour liste simplement chaînée
} node;

// Fonction pour créer un nouveau nœud
node *creerNoeud(int data){
    node *nouveauNoeud = (node*)malloc(sizeof(node));
    if(!nouveauNoeud){
        printf("Erreur avec malloc\n");
        return NULL;
    }
    nouveauNoeud->data = data;
    nouveauNoeud->suivant = NULL;  // Uniquement le pointeur suivant, pas de prec
    return nouveauNoeud;
}

void afficherListe(node *tete){
    node *courant = tete;
    while(courant != NULL){
        printf(" %d -> ", courant->data);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

// Fonction pour insérer un élément dans une liste simplement chaînée triée
void insererTrie(node **tete, int data){
    node *nouveauNoeud = creerNoeud(data);

    // Si la liste est vide ou si le nouveau nœud doit être en tête
    if(*tete == NULL || (*tete)->data >= nouveauNoeud->data){
        nouveauNoeud->suivant = *tete;
        *tete = nouveauNoeud;
    }
    else{
        node *courant = *tete;
        // Trouver la position appropriée
        while(courant->suivant != NULL && courant->suivant->data < nouveauNoeud->data){
            courant = courant->suivant;
        }
        // Insérer le nouveau nœud
        nouveauNoeud->suivant = courant->suivant;
        courant->suivant = nouveauNoeud;
    }
}

int main(){
    node *maListe = NULL;
    printf("\n=== Liste simplement chaînée triée ===\n");
    printf("Entrer des entiers (0 pour terminer) : \n");
    int valeur;
    scanf("%d", &valeur);
    while(valeur != 0){
        insererTrie(&maListe, valeur);
        scanf("%d", &valeur);
    }
    printf("Liste triée: ");
    afficherListe(maListe);

    return 0;
}