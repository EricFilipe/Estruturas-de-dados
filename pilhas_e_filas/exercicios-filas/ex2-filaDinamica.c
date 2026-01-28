#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct no{
    int valor;
    struct no *prox;
} NO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void enqueue(FILA *f, int valor);
void dequeue(FILA *f);
void front(FILA *f);
bool isEmpty(FILA *f);

int main() {
    FILA *f = (FILA *) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;

    enqueue(f,6);
    front(f);
    printf("ultimo %d\n", f->fim->valor);

    enqueue(f,9);
    front(f);
    printf("ultimo %d\n", f->fim->valor);

    enqueue(f,12);
    front(f);
    printf("ultimo %d\n\n", f->fim->valor);

    dequeue(f);
    front(f);
    printf("ultimo %d\n", f->fim->valor);

    dequeue(f);
    front(f);
    printf("ultimo %d\n\n", f->fim->valor);

    dequeue(f);
    dequeue(f);
    front(f);

    return 0;
}

bool isEmpty(FILA *f) {
    return (f->fim == NULL);
}

void enqueue(FILA *f, int v) {
    PONT novo = (PONT) malloc(sizeof(NO));
    novo->valor = v;
    novo->prox = NULL;

    if(isEmpty(f)) {
        f->fim = novo;
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void dequeue(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia.\n\n");
        return;
    }

    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL) f->fim = NULL;
}

void front(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia\n\n");
        return;
    }

    printf("1⁰ elemento = %d\n", f->inicio->valor);
}