#include<stdio.h>
#include<stdlib.h>

int main() {
    int tamanho, *ptr, soma;

    soma = 0;
    tamanho = 5;
    ptr = (int*)malloc(sizeof(int)*tamanho);

    if(ptr == NULL) {
        printf("Error ao alocar memoria\n");
        return 1;
    }

    for(int i = 0; i < tamanho; i++) {
        int *endereco = ptr+i;
        *endereco = 5+i;
        printf("%d\n", *endereco);
        soma += *endereco;
    }

    printf("Resultado: %d\n\n", soma);

    free(ptr);
    return 0;
}