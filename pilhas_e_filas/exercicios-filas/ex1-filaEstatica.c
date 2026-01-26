#include<stdio.h>
#include<stdlib.h>

#define TAM 10
#define true 1
#define false 0

typedef int bool;

typedef struct {
    int dados[TAM];
    int inicio;
    int fim;
    int volta;
} Fila;

void enqueue(Fila *f, int n);
void dequeue(Fila *f);
void front(Fila *f);
bool isEmpty(Fila *f);
bool isFull(Fila *f);


int main() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->fim = 0;
    f->inicio = 0;
    f->volta = 0;
    int option = 1;

    while (option != 0)
    {
        printf("Escolha uma opcao: \n");
        printf("1- inserir na fila\n");
        printf("2- remover da fila\n");
        printf("3- Consultar primeiro elemento\n");
        printf("0- sair\n\n");
        scanf("%d", &option);

    
    
        switch (option)
        {
        case 1:
            printf("n : ");
            int n;
            scanf("%d", &n);
            enqueue(f , n);
            break;
        
        case 2: 
            dequeue(f);
            break;

        case 3:
            front(f);
            break;
        
        default:
            break;
        }
    }

    free(f);
    return 0;
}

void enqueue(Fila *f, int n) {
    if(isFull(f)) return;
    if(f->fim == TAM && f->inicio > 0) {
        f->fim = 0;
        f->dados[f->fim] = n;
        f->fim++;
        f->volta++;
    } else {
        f->dados[f->fim] = n;
        f->fim++;
    }
}

void dequeue(Fila *f) {
    if(isEmpty(f)) return;
    f->inicio++;
    if(f->inicio == TAM) {
        f->inicio = 0;
        f->volta--;
    }
}

void front(Fila *f){
    if(isEmpty(f)) return;
    printf("1⁰ elemento = %d\n\n", f->dados[f->inicio]);
}

bool isEmpty(Fila *f) {
    if(f->inicio == f->fim && f->volta == 0) {
        printf("Fila vazia\n\n");
        return true;
    }

    return false;
}

bool isFull(Fila *f) {
    if((f->fim == TAM && f->inicio == 0) || (f->fim == f->inicio && f->volta > 0)) {
        printf("Fila cheia\n\n");
        return true;
    }

    return false;
}