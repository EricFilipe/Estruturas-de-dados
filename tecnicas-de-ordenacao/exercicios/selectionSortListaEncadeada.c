#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int value;
    struct no *next;
} NO, *PONT;

void insert(PONT *list, int value);
void selectionSort(PONT *list);
void showList(PONT list);

int main(void) {
    PONT list = NULL;

    insert(&list, 5);
    insert(&list, 1);
    insert(&list, 9);
    insert(&list, 3);
    insert(&list, 7);

    showList(list);

    selectionSort(&list);

    showList(list);

    return 0;
}

int isEmpty(PONT list) {
    return list == NULL;
} 

void insert(PONT *list, int value) {
    PONT new = (PONT) malloc(sizeof(NO));
    new->value = value;
    new->next = *list;
    *list = new;
}

void selectionSort(PONT *list) {
    if(isEmpty(*list)) return;
    PONT sortted = NULL;
    PONT end = NULL;

    while (*list != NULL)
    {
        PONT smallest = *list;
        PONT current = *list;
        PONT before = NULL;
        
        while (current->next != NULL)
        {
            if(current->next->value < smallest->value) {
                before = current;
                smallest = current->next;
            }

            current = current->next;
        } 

        if(smallest == *list) {
            *list = smallest->next;
        } else {
            before->next = smallest->next;
        }
        
        smallest->next = NULL;

        if(sortted == NULL) {
            sortted = smallest;
            end = sortted;
        } else {
            end->next = smallest;
            end = smallest;
        }
        
    }

    *list = sortted;
    
}

void showList(PONT list) {
    if(isEmpty(list)) {
        printf("Lista vazia.\n\n");
        return;
    }

    while (list->next != NULL)
    {
        printf("%d -> ", list->value);
        list = list->next;
    }
    
    printf("%d\n\n", list->value);
}
