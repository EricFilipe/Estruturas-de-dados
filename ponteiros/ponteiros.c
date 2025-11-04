#include<stdio.h>
#include<stdlib.h>

int xi;
int *ptr_xi;

void imprimir() {
    printf("valor de xi= %d \n", xi);

    printf("valor de &xi = %p \n", &xi);

    printf("valor de ptr_xi = %p \n", ptr_xi);

   printf("valor de *ptr_xi = %d \n\n", *ptr_xi);

}

int main() {
    xi = 10;

    ptr_xi = &xi;

    xi = 20;

    *ptr_xi = 30;

    imprimir();

    int *ptr;

    //printf("endereco: %p \n Valor: %d\n\n", ptr, *ptr);

    ptr = (int*)malloc(sizeof(int));

    printf("endereco: %p\n Valor: %d \n\n", ptr, *ptr);

    *ptr = 10;

    printf("endereco: %p\n Valor: %d \n\n", ptr, *ptr);

    int x = 20;

    int *ptr_x = &x;

    printf("endereco: %p\n", ptr_x);

    printf("valor: %d\n\n", *ptr_x);

    int *ptr_xx = ptr_x + 1;

    printf("endereco ptr + 1: %p\n", ptr_xx);

    printf("valor: %d\n\n", *ptr_xx);

    int *ptr_vetor;

    int vetor[5] = {1,2,3,4,5};

    ptr_vetor = vetor;

    int n = *(ptr_vetor + 3);

    printf("endereco: %p\n", ptr_vetor);
    printf("valor: %d\n", *ptr_vetor);
    printf("n: %d\n\n", n);


    system("Pause");
    return 0;
}