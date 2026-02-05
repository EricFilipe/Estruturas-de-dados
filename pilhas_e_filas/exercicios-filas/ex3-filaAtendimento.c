#include<stdio.h>
#include<stdlib.h>

typedef int bool;

typedef struct cliente {
    int id;
    int tempo;
    struct cliente *prox;
} CLIENTE, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void enqueue(FILA *f, int id, int tempo);
void atender(FILA *f);
bool isEmpty(FILA *f);
void showFila(FILA *f);
void front(FILA *f);

int main () {
    FILA *f = (FILA *) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;

    enqueue(f, 1, 3);
    enqueue(f, 2, 2);

    atender(f);
    showFila(f);

    atender(f);
    showFila(f);

    atender(f);
    showFila(f);

    return 0;
}

bool isEmpty(FILA *f) {
    return f->inicio == NULL;
}

void enqueue(FILA *f, int id, int tempo) {
    PONT novo = (PONT) malloc(sizeof(CLIENTE));
    novo->id = id;
    novo->tempo = tempo;
    novo->prox = NULL;

    if(isEmpty(f)) {
        f->fim = novo;
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("Entrou: Pessoa %d (tempo %d)\n", f->fim->id, f->fim->tempo);
}

void atender(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia.\n\n");
        return;
    }

    f->inicio->tempo--;

    printf("\nAtendendo Pessoa %d (tempo restante: %d)\n", f->inicio->id, f->inicio->tempo);

    if(f->inicio->tempo == 0) { 
        PONT apagar = f->inicio;
        printf("Pessoa %d finalizou atendimento\n", apagar->id);
        f->inicio = f->inicio->prox;
        free(apagar);
    }

    if(f->inicio == NULL) f->fim = NULL;
}

void front(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia.\n\n");
        return;
    }

    printf("1⁰ cliente: %d\n", f->inicio->id);
}

void showFila(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia");
        return;
    }

    PONT end = f->inicio;

    printf("Fila: ");
    while (end->prox != NULL)
    {
        printf("[%d(%d)] -> ", end->id, end->tempo);
        end = end->prox;
    }
    printf("[%d(%d)]\n\n", end->id, end->tempo);
    
}