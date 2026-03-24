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
    
    insert(&list, 34);
    insert(&list, 23);
    insert(&list, 9);
    insert(&list, 34);
    insert(&list, 6);
    insert(&list, 0);
    insert(&list, 6);
    insert(&list, 1);
    insert(&list, 90);
    insert(&list, 54);
    insert(&list, 10);
    insert(&list, 243);
    insert(&list, 156);
    insert(&list, 4);
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
    PONT ordenada;

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
        
        ordenada = merge(smallestA, smallsetB);
        
    }

    *list = ordenada;
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

PONT merge(PONT a, PONT b) {
    
    PONT nextA = a;
    PONT pontToBeReturned = b;

    if(a->next == NULL && b->next == NULL) {
        if(a->value < b->value) {
            a->next = b;
            pontToBeReturned = a;
        } else {
            b->next = a;
        }
    } else {
        PONT elementToCompare = a;
        PONT elementToBeCompared = b;

        if(a->value < b->value) {
            elementToCompare = b;
            elementToBeCompared = a;
            pontToBeReturned = a;
        }

        while (elementToBeCompared != NULL && elementToCompare != NULL)
        {
            if(elementToBeCompared->next != NULL) {
                if(elementToCompare->value < elementToBeCompared->next->value) {
                    PONT temp0 = elementToCompare->next;
                    PONT temp1 = elementToBeCompared->next;
                    elementToBeCompared->next = elementToCompare;
                    elementToCompare->next = temp1;
                    elementToCompare = temp0;
                }
            } 
            else {
                elementToBeCompared->next = elementToCompare;
                break;
            }

            elementToBeCompared = elementToBeCompared->next;
        }
        
    }

    
        
    return pontToBeReturned;
}