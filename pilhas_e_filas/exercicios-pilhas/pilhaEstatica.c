#include<stdio.h>
#include<stdlib.h>

#define tamanho 10

struct spilha {
    int dados[tamanho];
    int inicio;
    int fim;
};

struct spilha pilha;

void push();
void pop();
void top();
void checkStatus();
void showPilha();

int main() {
    int option = 1;
    pilha.inicio = 0;
    pilha.fim= 0;

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

    if(pilha.fim == tamanho) {
        printf("\nPilha ja esta cheia!\n");
    } else {
        pilha.dados[pilha.fim] = value;
        pilha.fim++;
    }
}

void pop() {
    if(pilha.fim == pilha.inicio) {
        printf("\nPilha vazia!");
    } else {
        pilha.dados[pilha.fim - 1] = 0;
        pilha.fim--; 
    }
}

void top() {
    if(pilha.fim != pilha.inicio) {
        int top = pilha.dados[pilha.fim - 1];
        printf("\nElemento do topo: %d\n", top);
    }
}

void checkStatus() {
    if(pilha.fim == pilha.inicio) {
        printf("\nPilha Vazia!\n");
    } else if (pilha.fim == tamanho)
    {
        printf("\nPilha cheia!\n");
    }
    
}

void showPilha() {
    for(int i = 0; i < tamanho; i++) {
        printf("\n[%d]\n", pilha.dados[i]);
    }
}