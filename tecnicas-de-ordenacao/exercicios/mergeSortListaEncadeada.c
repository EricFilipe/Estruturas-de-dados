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
    
    insert(&list, 13);
    insert(&list, 1);
    insert(&list, 56);
    insert(&list, 20);
    insert(&list, 22);
    insert(&list, 84);
    insert(&list, 90);
    insert(&list, 1);

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
    if (list == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    while (list->next != NULL)
    {
        printf("%d -> ", list->value);
        list = list->next;
    }

    printf("%d\n\n", list->value);
    
}

int calcLength(PONT list) {
    PONT end = list;
    int length = 0;

    while (end)
    {
        length++;
        end = end->next;    
    }
    
    return length;
}

void mergeSort(PONT *list) {

    if ((*list) == NULL || (*list)->next == NULL) return;

    PONT origin = *list;
    PONT a;
    PONT b;

    split(origin, &a, &b);
    
    mergeSort(&a);
    
    mergeSort(&b);
    
    *list = merge(a, b);
}

void split(PONT origem, PONT *a, PONT *b) {
    int length = calcLength(origem);
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