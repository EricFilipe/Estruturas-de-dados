#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int tam;

    int *vetor;

    printf("escolha o tamanho do vetor: ");

    scanf("%d", &tam);

    vetor = (int*)malloc(sizeof(int)*tam);

    printf("endereco: %p\n", vetor);
    printf("valor: %d\n\n", *vetor);

    for(int i = 0; i < tam; i++) {
        vetor[i] = 2 * i;

        printf("Posicao %d: %d\n", i,vetor[i]);
    }

    printf("endereco: %p\n", vetor);
    printf("valor: %d\n\n", *vetor);

     return 0;
}