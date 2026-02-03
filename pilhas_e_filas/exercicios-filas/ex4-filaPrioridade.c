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

    showFila(f);

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
        
        f->fim->prox = novo;

        while (end->prox != NULL)
        {
            if(novo->prioridade < end->prioridade) {
                PONT temp = end;
                novo->prox = temp;
                end = novo;
                novo = temp;
                novo->prox = NULL;
                if(f->inicio->prox == NULL) {
                    f->inicio = end;
                }
            } else if(novo->prioridade == end->prioridade && novo != end->prox) {
                PONT temp = end->prox;
                end->prox = novo;
                novo->prox = temp;
                f->fim->prox = NULL;
            }

            end = end->prox;
        }

        f->fim = end;
    }
}

void showFila(FILA *f) {
    if (isEmpty(f)) {
        printf("Fila vazia.");
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