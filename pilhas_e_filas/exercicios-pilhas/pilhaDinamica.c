#include<stdio.h>
#include<stdlib.h>

struct no {
    int value;
    struct no *next;
};

typedef struct no *ptr_pilha;
ptr_pilha pilha;

void push(ptr_pilha pilha);
void pop(ptr_pilha pilha);
void top(ptr_pilha pilha);
void checkStatus();
void showPilha();

int main() {
    int option = 1;
    
    pilha = (ptr_pilha)malloc(sizeof(struct no));

    pilha->value = 0;
    pilha->next = NULL;

    while (option != 0)
    {    
        showPilha();

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
            push(pilha);
            break;

        case 2:
            pop(pilha);
            break;

        case 3:
            top(pilha);
            break;

        case 4:
            checkStatus();
            break;
        
        default:
            break;
        }
    }

}

void push(ptr_pilha pilha) {
    int value;

    printf("\nDigite o valor: ");
    scanf("%d", & value);
    
    while (pilha->next != NULL)
    {
        pilha = pilha->next;
    }

    pilha->next = (ptr_pilha)malloc(sizeof(struct no));

    pilha = pilha->next;

    pilha->value = value;
    pilha->next = NULL;
    
}

void pop(ptr_pilha pilha) {
    ptr_pilha actual = pilha;

    while (pilha->next != NULL)
    {
        actual = pilha;
        pilha = pilha->next;
    }

    actual->next = NULL;
}

void top(ptr_pilha pilha) {
    while (pilha->next != NULL)
    {
        pilha = pilha->next;
    }

    printf("\nElemento do topo: %d", pilha->value);
}

void checkStatus() {
   int size = 0;

   while (pilha->next != NULL)
   {
        pilha = pilha->next;
        size++;
   }
   
   if(size > 0) {
        printf("\nPilha dinamica 'cheia'\n");
   } else {
        printf("\nPilha vazia\n");
   }
    
}

void showPilha() {
    while (pilha->next != NULL)
    {
        printf("[%d]", pilha->value);
        pilha = pilha->next;
    }

    printf("[%d]", pilha->value);
    
}