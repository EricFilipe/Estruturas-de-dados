#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Constante
#define tamanho 5

//Estrutura da fila
struct tfila {
    int dados[tamanho];
    int inicio;
    int fim;
};

//Variaveis globais
struct tfila fila;
int option;

//Prototipacao
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

int main() {
    setlocale(LC_ALL, "Portuguese");

    option = 1;
    fila.inicio = 0;
    fila.fim = 0;

    while (option != 0)
    {
        fila_mostrar();

        menu_mostrar();

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            fila_entrar();
            break;
        
        case 2:
            fila_sair();
            break;

        default:
            break;
        }
    }

    return 0;
    
}

void fila_entrar() {
    if(fila.fim == tamanho) {
        printf("\nA fila esta cheia!\n");
        system("pause");
    } else {
        printf("\nDigite o valor a entrar: ");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}

void fila_sair() {
    if(fila.fim == fila.inicio) {
        printf("\nA fila esta vazia!\n");
        system("pause");
    } else {
        for(int i = 0; i < tamanho; i++) {
            fila.dados[i] = fila.dados[i + 1];
        }

        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}

void fila_mostrar() {
    printf("[");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", fila.dados[i]);
    }
    printf("]\n\n");
}

void menu_mostrar() {
    printf("\nEscolha uma opcao:\n");
    printf("1 - Incluir na fila\n");
    printf("2 - Excluir da fila\n");
    printf("0 - Sair\n\n");
}