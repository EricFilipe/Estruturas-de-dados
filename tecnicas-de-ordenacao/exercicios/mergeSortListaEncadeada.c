#include<stdio.h>
#include<stdlib.h>

//dividir lista no meio
//dividir recursivamente

typedef struct no {
    int value;
    struct no *next;
} NO, *PONT;

void mergeSort(PONT *list);
PONT merge(PONT a, PONT b);
void split(PONT origem, PONT *a, PONT *b);
void insert(PONT *list, int value);
void showList(PONT list);

int main(void) {
    PONT list = NULL;
    
    insert(&list, 5);
    insert(&list, 1);
    insert(&list, 9);
    insert(&list, 3);
    insert(&list, 7);
    insert(&list, 10);
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 8);
    insert(&list, 6);

    showList(list);

    mergeSort(&list);
    printf("\n");

    showList(list);
}

void insert(PONT *list, int value) {
    PONT new = (PONT) malloc(sizeof(NO));
    new->value = value;
    new->next = *list;
    *list = new;
}

void showList(PONT list) {
    while (list->next != NULL)
    {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("%d\n\n", list->value);
    
}

int calcLength(PONT *list) {
    PONT end = *list;
    int length = 0;

    while (end)
    {
        length++;
        end = end->next;    
    }
    
    return length;
}

void mergeSort(PONT *list) {
    PONT ordenada;

    if((*list)->next != NULL) {
        int length = calcLength(list);
        int half = length / 2;

        PONT a = *list;
        PONT end = *list;
        PONT before;
        for(int i = 0; i < half; i++) {
            before = end;
            end = end->next;
        }

        PONT b = end;
        before->next = NULL;

        printf("lado esquerdo: %d\n", a->value);
        printf("lado direito: %d\n", b->value);
        
        PONT actualA = a;
        PONT menorA = a;
        PONT actualB = b;
        PONT menorB = b;
        while (actualA->next != NULL)
        {
            if(actualA->next->value < menorA->value) {
                menorA = actualA->next;
            }

            actualA = actualA->next;
        }

        while (actualB->next != NULL)
        {
            if(actualB->next->value < menorB->value) {
                menorB = actualB->next;
            }

            actualB = actualB->next;
        }
        
        
        mergeSort(&a);
        mergeSort(&b);
        printf("comeca merge com pont a: %d e pont b: %d\n", menorA->value, menorB->value);
        ordenada = merge(menorA, menorB);
        showList(ordenada);
    }

    *list = ordenada;
}

PONT merge(PONT a, PONT b) {
    //PONT a e PONT b precisam ser as partes ordenadas
    //pegar um lado e ordenar com o outro
    //pegar o inicio de um lado ordenado e o inicio do outro lado ordenado
    PONT nextA = a;
    PONT pontToBeReturned = b;

    if(a->next == NULL && b->next == NULL) {
        if(b->value < a->value) {
            b->next = a;
            return pontToBeReturned;
        }

        a->next = b;
        return pontToBeReturned = a;
    }

    if(a->value < b->value) {
        if(a->next != NULL && a->next->value < b->value) {
            nextA = a->next->next;
            a->next->next = b;
        } else {
            nextA = a->next;
            a->next = b;
        }

        pontToBeReturned = a;
    } 

    while(nextA != NULL)
    {
        if(b->next != NULL && nextA->value < b->next->value) {
            PONT temp = nextA->next;
            PONT nextB = b->next;
            b->next = nextA;
            nextA->next = nextB;
            nextA = temp;
         }
        else if(b->next == NULL) {
            PONT temp = nextA->next;
            PONT nextB = b->next;
            b->next = nextA;
            nextA->next = nextB;
            nextA = temp;
        }

        b = b->next;
    }
        
    return pontToBeReturned;
}