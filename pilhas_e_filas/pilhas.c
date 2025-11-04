#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Constantes
#define tamanho 5

//Estrutura da pilha
struct tpilha {
    int dados[tamanho];
    int inicio;
    int fim;
};

//Variaveis globais
struct tpilha pilha;
int opcao;

//Prototipacao
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

int main() {
    setlocale(LC_ALL, "Portuguese");

    opcao = 1;

    pilha.inicio = 0;
    pilha.fim = 0;

    while (opcao != 0){
        

        pilha_mostrar();

        menu_mostrar();

        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            pilha_entrar();
            break;

        case 2:
            pilha_sair();
            break;
        
        default:
            break;
        }
    }

    return 0;
    
}

void pilha_entrar() {
    if(pilha.fim == tamanho) {
        printf("\n A pilha esta cheia, impossivel empilhar!\n\n");
        system("pause");
    } else {
        printf("Digite o valor a empilhar: ");
        scanf("%d", &pilha.dados[pilha.fim]);
        
        pilha.fim++;
    }
}

void pilha_sair() {
    if(pilha.inicio == pilha.fim) {
        printf("\n A pilha esta vazia, impossivel desempilhar!\n\n");
        system("pause");
    } else {
        pilha.dados[pilha.fim - 1] = 0;
        pilha.fim--;
    }
}

void pilha_mostrar() {
    for(int i = 0; i < tamanho; i++) {
        printf("[");
        printf("%d", pilha.dados[i]);
        printf("]\n\n");
    }
}

void menu_mostrar() {
    printf("\nESCOLHA UMA OPCAO:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n\n");
}