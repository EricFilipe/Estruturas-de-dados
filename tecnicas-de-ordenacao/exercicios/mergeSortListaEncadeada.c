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

        printf("lado esquerdo: %d\n", *a);
        printf("lado direito: %d\n", *b);

        mergeSort(&a);
        mergeSort(&b);
        printf("comeca merge\n");
    }
}