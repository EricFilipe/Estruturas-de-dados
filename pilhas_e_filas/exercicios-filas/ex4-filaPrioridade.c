#include<stdio.h>
#include<stdlib.h>

typedef int bool;

typedef struct elemento {
    int valor;
    int prioridade;
    struct elemento *prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void enqueue(FILA *f, int valor, int prioridade);
void dequeue(FILA *f);
void front(FILA *f);
bool isEmpty(FILA *f);
void showFila(FILA *f);

int main (void) {
    FILA *f = (FILA *) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;

    enqueue(f, 10, 3);
    enqueue(f, 20, 1);
    enqueue(f, 30, 2);
    enqueue(f, 40, 1);
    enqueue(f, 40, 4);
    enqueue(f, 13, 3);

    showFila(f);

    front(f);

    dequeue(f);
    front(f);

    return 0;
}

bool isEmpty(FILA *f) {
    return f->inicio == NULL;
}

void enqueue(FILA *f, int valor, int prioridade) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if(isEmpty(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        PONT end = f->inicio;

        while (end)
        {
            if(novo->prioridade < end->prioridade) {
                if(end == f->inicio){
                    f->inicio = novo;
                    f->inicio->prox = end;
                }
            } else if (end->prox != NULL) {
                if(novo->prioridade < end->prox->prioridade) {
                    PONT temp = end->prox;
                    end->prox = novo;
                    novo->prox = temp;
                    break;
                }
            } else {
                f->fim->prox = novo;
                f->fim = novo;
                break;
            }
            
            
            end = end->prox;
        }
    }
}

void showFila(FILA *f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    
    PONT end = f->inicio;

    while (end->prox != NULL)
    {
        printf("(%d,p%d) -> ", end->valor, end->prioridade);
        end = end->prox;
    }

    printf("(%d,p%d) \n\n", end->valor, end->prioridade);
    
}

void dequeue(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }

    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);

    if(f->inicio == NULL) f->fim = NULL;
}

void front(FILA *f) {
    if(isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("1⁰ elemento = (%d,p%d)\n\n", f->inicio->valor, f->inicio->prioridade);
}