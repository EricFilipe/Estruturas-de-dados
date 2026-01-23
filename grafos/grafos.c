#include<stdio.h>
#include<stdlib.h>

#define MAXIMO 10

int tamanho = 0;
int vertices[MAXIMO];
int matriz[MAXIMO][MAXIMO];

int grafo_tamanho();
void grafo_desenhar();
void grafo_desenhar_matriz();
void grafo_inserir();
void grafo_remover();

int main() {
    int option = 1;

    while (tamanho <= 0 || tamanho > MAXIMO)
    {
        tamanho = grafo_tamanho();

        if(tamanho <= 0 || tamanho > MAXIMO) {
            printf("Escolha um valor entre 1 e %d!\n\n", MAXIMO);
        } else {
            for(int i = 0; i < tamanho; i++) {
                vertices[i] = i;
            }
        }
    }

    while (option != 0)
    {
        grafo_desenhar();
        grafo_desenhar_matriz();

        printf("Escolha uma opcao: \n");
        printf("1- inserir\n");
        printf("2- remover\n");
        printf("0- sair\n\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            grafo_inserir();
            break;

        case 2:
            grafo_remover();
            break;

        default:
            break;
        }
    }
    
    return 0;
}

//Definir quantidade de vertices
int grafo_tamanho() {
    int tamanho; 

    printf("Escolha a quantidades de vertices no grafo:");
    scanf("%d", &tamanho);

    return tamanho;
}

//Inserir aresta
void grafo_inserir() {
    int num1, num2;

    printf("Escolha o vértice de origem entre 0 a %d: ", tamanho - 1);
    scanf("%d", &num1);

    printf("Escolha o vértice de destino entre 0 a %d: ", tamanho - 1);
    scanf("%d", &num2);

    if(num1 > tamanho - 1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n",tamanho - 1);
    } else {
        matriz[num1][num2] = 1;
        matriz[num2][num1] = 1;
    }
}

//Remover aresta
void grafo_remover() {
    int num1, num2;

    printf("Escolha o vértice de origem entre 0 a %d: ", tamanho -1);
    scanf("%d", &num1);

    printf("Escolha o vértice de destino entre 0 a %d: ", tamanho -1);
    scanf("%d", &num2);

     if(num1 > tamanho - 1 || num2 > tamanho - 1 || num1 < 0 || num2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n",tamanho -1);
    } else {
        matriz[num1][num2] = 0;
        matriz[num2][num1] = 0;
    }
}

//Mostrar vertices
void grafo_desenhar() {
    
    printf("\n[");
    for(int i = 0; i < tamanho; i++) {
        printf("%d,", vertices[i]);
    }
    printf("]\n\n");
    
}

//Mostrar adjacencias
void grafo_desenhar_matriz() {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}