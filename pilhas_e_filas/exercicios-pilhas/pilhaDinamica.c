#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct no {
    int value;
    struct no *next;
};

typedef struct no *ptr_pilha;

void push(ptr_pilha *pilha);
void pop(ptr_pilha *pilha);
void top(ptr_pilha *pilha);
void checkStatus(ptr_pilha pilha);
void showPilha(ptr_pilha pilha);

int main() {
    srand(time(NULL));
    int option = 1;
    
    ptr_pilha pilha = NULL;  
    ptr_pilha *pPilha = &pilha;

    while (option != 0)
    {    
        showPilha(pilha);

        printf("\nEscolha uma opcao:\n\n");

        printf("1 - emplihar\n");
        printf("2 - desemplihar\n");
        printf("3 - consultar elemento do topo\n");
        printf("4 - verificar estado\n");
        printf("0 - sair\n\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push(pPilha);
            break;

        case 2:
            pop(pPilha);
            break;

        case 3:
            top(pPilha);
            break;

        case 4:
            checkStatus(pilha);
            break;
        
        default:
            break;
        }
    }

    free(pilha);
}

void push(ptr_pilha *pilha) {
    ptr_pilha new = (ptr_pilha)malloc(sizeof(struct no));
    new->value = rand()%50;
    new->next = *pilha;
    *pilha = new;
}

void pop(ptr_pilha *pilha) {
     if(*pilha == NULL) {
        printf("Pilha vazia");
        return;
    }

    ptr_pilha temp = *pilha;
    *pilha = (*pilha)->next;
    free(temp);
}

void top(ptr_pilha *pilha) {
    if(*pilha == NULL) {
        printf("Pilha vazia");
        return;
    }

    printf("\nElemento do topo: %d\n", (*pilha)->value);
}

void checkStatus(ptr_pilha pilha) {
   if(pilha == NULL) {
        printf("Pilha vazia\n");
   } else {
        int count = 1;
        while (pilha->next != NULL)
        {
            count++;
            pilha = pilha->next;
        }

        printf("Pilha com %d elementos\n", count);
        
   }
    
}

void showPilha(ptr_pilha pilha) {
    if(pilha == NULL) {
        return;
    }

    while (pilha->next != NULL)
    {
        printf("[%d]", pilha->value);
        pilha = pilha->next;
    }
   
    printf("[%d]", pilha->value);
}