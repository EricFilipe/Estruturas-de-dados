#include<stdio.h>
#include<stdlib.h>

#define tamanho 10

struct spilha {
    int dados[tamanho];
    int topo;
};

struct spilha pilha;

void push();
void pop();
void top();
void checkStatus();
void showPilha();

int main() {
    int option = 1;
    pilha.topo = 0;

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
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            top();
            break;

        case 4:
            checkStatus();
            break;
        
        default:
            break;
        }
    }

}

void push() {
    int value;

    printf("\nDigite o valor: ");
    scanf("%d", & value);

    if(pilha.topo == tamanho) {
        printf("\nPilha ja esta cheia!\n");
    } else {
        pilha.dados[pilha.topo] = value;
        pilha.topo++;
    }
}

void pop() {
    if(pilha.topo == 0) {
        printf("\nPilha vazia!");
    } else {
        pilha.dados[pilha.topo - 1] = 0;
        pilha.topo--; 
    }
}

void top() {
    if(pilha.topo != 0) {
        int top = pilha.dados[pilha.topo - 1];
        printf("\nElemento do topo: %d\n", top);
    } else {
        printf("Pilha vazia");
    }
}

void checkStatus() {
    if(pilha.topo == 0) {
        printf("\nPilha Vazia!\n");
    } else
    {
        printf("\nPilha cheia!\n");
    }
    
}

void showPilha() {
    for(int i = pilha.topo - 1; i >= 0; i--) {
        printf("[%d]", pilha.dados[i]);
    }
}