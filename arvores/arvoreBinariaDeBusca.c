#include<stdio.h>
#include<stdlib.h>

int buscaArvoreBinaria(int vec[], int arg, int tam);

int main() {
    //Vetor {3, 1, 8, 7, 20, 21, 31, 40, 30, 0};
    //[30][16][15][19][31][40][15][6][45][33]
    int test[] = {31, 30, 40, 16, 0, 33, 45, 15, 19,0,0,0,0,0,0,6,15};
    int arvoreDeBusca[] = {20, 3, 21, 1, 8, 0, 31, 1, 0, 7, 0, 0, 0, 30, 40};
    int arg = 6;
    int tam = 10; 
    int h = buscaArvoreBinaria(test, arg, tam);
    printf("\n%d\n\n", h);
}

int buscaArvoreBinaria(int vec[], int arg, int tam) {
    int no, achou, fim;

    fim = 0;
    no = 0;
    achou = -1;

    while ((achou == -1) && (fim <= tam))
    {
        if(arg == vec[no]) {
            achou = no;
        }

        if(arg < vec[no]) {
            no = 2 * no + 1;
        } else {
            no = 2 * no + 2;
        }

        fim++;
    }

    return(achou);
}