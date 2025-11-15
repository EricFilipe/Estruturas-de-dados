#include<stdio.h>
#include<stdlib.h>

struct no {
    char value;
    struct no *next;
};


typedef struct no *ptr_pilha;

void push(ptr_pilha *pilha, char parenteses);
void pop(ptr_pilha *pilha);
void findParenteses(char *ptr_expression, char mathExpression[], ptr_pilha *pilha);
void showPilha(ptr_pilha pilha);
void isExpressionBalanced(ptr_pilha pilha);

int main() {
    ptr_pilha pilha = NULL;
    ptr_pilha *pPilha = &pilha;

    char firstExemple[] = "(2 + 3) * (5 - (4 / 2))";
    char secondExemple[] = "(2 + 3)) * ((5 - (4 / 2))";
    char *ptr_1 = firstExemple;
    char *ptr_2 = secondExemple;

    int exemple;

    printf("Expressão 1: (2 + 3) * (5 - (4 / 2))\n");
    printf("Expressão 2: (2 + 3)) * ((5 - (4 / 2))\n\n");
    printf("Exemplo 1 ou 2? ");
    scanf("%d", &exemple);

    switch (exemple)
    {
    case 1:
        findParenteses(ptr_1, firstExemple, pPilha);
        showPilha(pilha);
        isExpressionBalanced(pilha);
        break;

    case 2:
        findParenteses(ptr_2, secondExemple, pPilha);
        showPilha(pilha);
        isExpressionBalanced(pilha);
        break;
    
    default:
        break;
    }
    
}

void findParenteses(char *ptr_expression, char mathExpression[], ptr_pilha *pilha) {
    while(*ptr_expression != '\0') {
        if(*ptr_expression == '(') {
            push(pilha, *ptr_expression);
        } else if (*ptr_expression == ')')
        {
            if(*pilha == NULL) {
                push(pilha, *ptr_expression);
            } else {
                pop(pilha);
            }
        }
        ptr_expression++;
    }
}

void push(ptr_pilha *pilha, char parenteses) {
    ptr_pilha new = (ptr_pilha)malloc(sizeof(struct no));
    new->value = parenteses;
    new->next = *pilha;
    *pilha = new;
}

void pop(ptr_pilha *pilha) {
    ptr_pilha temp = *pilha;
    *pilha = (*pilha)->next;
    free(temp);
}

void showPilha(ptr_pilha pilha) {
    if(pilha == NULL) {
        printf("[Pilha vazia]\n");
        return;
    }

    while (pilha->next != NULL)
    {
        printf("[%c]", pilha->value);
        pilha = pilha->next;
    }

    printf("[%c]\n\n", pilha->value);
    
}

void isExpressionBalanced(ptr_pilha pilha) {
    if (pilha != NULL)
    {
        printf("A expressão não tem parênteses balanceados\n\n");
    } else {
        printf("Expressão balanceada\n\n");
    }
    
}