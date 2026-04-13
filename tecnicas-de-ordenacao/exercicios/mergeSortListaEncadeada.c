#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
    
    insert(&list, 34);
    insert(&list, 23);
    insert(&list, 9);
    insert(&list, 34);
    insert(&list, 4);
    insert(&list, 0);
    insert(&list, 6);
    insert(&list, 1);
    insert(&list, 90);
    insert(&list, 54);
    insert(&list, 10);
    insert(&list, 243);
    insert(&list, 156);
    insert(&list, 6);
    insert(&list, 7);

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
    PONT sorted;

    if((*list)->next != NULL) {
        PONT origin = *list;
        PONT a;
        PONT b;

        split(origin, &a, &b);
        
        PONT actualA = a;
        PONT smallestA = a;
        PONT actualB = b;
        PONT smallsetB = b;
        
        //Pegando menor numero do lado a
        while (actualA->next != NULL)
        {
            if(actualA->next->value < smallestA->value) {
                smallestA = actualA->next;
            }

            actualA = actualA->next;
        }

        //Pegando menor numero do lado b
        while (actualB->next != NULL)
        {
            if(actualB->next->value < smallsetB->value) {
                smallsetB = actualB->next;
            }

            actualB = actualB->next;
        }
        
        mergeSort(&a);
        mergeSort(&b);
        sorted = merge(smallestA, smallsetB);
    }

    *list = sorted;
}

void split(PONT origem, PONT *a, PONT *b) {
    int length = calcLength(&origem);
    int half = length / 2;

    *a = origem;
    PONT end = origem;
    PONT before;
    for(int i = 0; i < half; i++) {
        before = end;
        end = end->next;
    }

    *b = end;
    before->next = NULL;
}

// PONT a e PONT b precisam ser as partes ordenadas
// pegar o inicio de um lado ordenado e o inicio do outro lado ordenado
// pegar um lado e ordenar com o outro
PONT merge(PONT a, PONT b) {
    PONT pontToBeReturned;
    PONT sorted;
    if (a->value < b->value)
    {
        pontToBeReturned = a;
        sorted = a;
        a = a->next;
    }
    else 
    {
        pontToBeReturned = b;
        sorted = b;
        b = b->next;
    }

    while (a != NULL && b != NULL)
    {
        if (b->value < a->value)
        {
            sorted->next = b;
            b = b->next;
            sorted = sorted->next;
        }
        else
        {
            sorted->next = a;
            a = a->next;
            sorted = sorted->next;
        }
    }

    if (a == NULL)
    {
        sorted->next = b;
    }    
    else
    {
        sorted->next = a;
    }
        
    return pontToBeReturned;
}