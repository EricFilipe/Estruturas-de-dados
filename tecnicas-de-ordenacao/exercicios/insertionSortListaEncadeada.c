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
    PONT anterior = *l;
    PONT atual = anterior->prox;
    PONT temp;
    
    while (atual)
    {

        PONT end = *l;

        while (end->prox != NULL && end != atual)
        {
            if(atual->valor < end->valor) {
                temp = atual->prox;
                anterior->prox = temp;
                atual->prox = end;
                *l = atual;
                atual = anterior;
                break;
            } else if(atual->valor < end->prox->valor) {
                temp = end->prox;
                end->prox = atual;
                anterior->prox = atual->prox;
                atual->prox = temp;
                atual = anterior;
                break;
            }


            end = end->prox;
        }
        
        anterior = atual;
        atual = anterior->prox;
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