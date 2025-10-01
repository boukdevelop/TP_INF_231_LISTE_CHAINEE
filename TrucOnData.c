 /*===== liste doublement chainées :
5. Insertion en tête et en queue dans une liste doublement chaîne circulaire */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct dnode{
    int data;
    struct dnode *next;
    struct dnode *prec;
}dnode;

//Fonction pour creer pour un nouveau noeud
dnode *createNode(int data){
    dnode *newNode = (dnode*)malloc(sizeof(dnode));
    if(!newNode){
        printf("erreur avec malloc\n");
        return NULL;
    }
    newNode-> data= data;
    newNode->next= NULL;
    newNode-> prec =NULL;
    return newNode;
}

void printflist(dnode *head){
    dnode *current = head;
    while(current != NULL){
        printf(" %d <-> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//Fonction pour inserer un element dans une liste doublement chaine trie
void insertDsorted(dnode **head,int data){
    dnode* newNode= createNode(data);

    //si la liste est vide ou si le nouveau noeud doit etre en tete
    if(*head == NULL || (*head)->data >=newNode->data){
        newNode->next = *head;
        if(*head != NULL){
            (*head)->prec = newNode;
        }
        *head = newNode;
    }
    else{
        dnode *current= *head;
        while(current->next && current->next->data<newNode->data){
            current= current->next;
        }
        newNode->prec = current;
        newNode->next = current->next;
        if(current->next != NULL){
            current->next->prec = newNode;
        }
        current->next = newNode;
    }
}

int main(){
        dnode *Mylistzone = NULL;
    printf("\n=== Liste doublement chaînée triée ===\n");
    printf("Entrer des entiers (0 pour terminer) : \n");
    int val;
    scanf("%d",&val);
    while(val !=0){
        insertDsorted(&Mylistzone,val);
        scanf("%d",&val);
    }
    printf("Liste triée: ");

   printflist(Mylistzone);



    return 0;
}