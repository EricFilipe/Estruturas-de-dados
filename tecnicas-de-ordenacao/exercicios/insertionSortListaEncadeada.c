#include<stdio.h>
#include<stdlib.h>

//ordenar em ordem crescente
//repsicionando os nos
//pegar um no, a partir do segundo, que esta na parte 
//desordenada e coloca-lo na parte ordenada

typedef struct no{
    int valor;
    struct no *prox;
} NO, *PONT;

typedef struct{
    PONT inicio;
} LISTA;

void inserir(PONT *l, int valor);
void insertionSort(PONT *l);
void showLista(PONT l);

int main(void) {
    PONT no = (PONT) malloc(sizeof(NO));
    no = NULL;
    PONT *l = &no;

    inserir(l, 5);
    inserir(l, 1);
    inserir(l, 9);
    inserir(l, 3);
    inserir(l, 7);

    insertionSort(l);

    showLista(*l);

    return 0;
}

int isEmpty(PONT l) {
    return l == NULL;
}

void inserir(PONT *l, int valor) {
    PONT novo = (PONT) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = *l;
    *l = novo;
}

void insertionSort(PONT *l) {
    PONT atual = *l;
    
    while (atual->prox != NULL)
    {
        PONT prox = atual->prox;
        PONT temp = prox->prox;
        PONT end = *l;

        if(prox) {
            while (end)
            {
                if(prox->valor < end->valor) {
                    PONT temp = prox->prox;
                    prox->prox = end;
                    *l = prox;
                    end->prox = temp;
                    break;
                } else if(prox->valor < end->prox->valor) {
                    PONT temp = end->prox;
                    end->prox = prox;
                    prox->prox = temp;
                    break;
                }

                end = end->prox;
            }
        } 
        
        atual->prox = temp;
        atual = atual->prox;
    }
    
}

void showLista(PONT l) {
    if(isEmpty(l)) {
        printf("Fila vazia.\n\n");
        return;
    }

    while (l->prox != NULL)
    {
        printf("%d -> ", l->valor);
        l = l->prox; 
    }

    printf("%d\n\n", l->valor);
}