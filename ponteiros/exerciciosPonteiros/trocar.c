#include<stdio.h>
#include<stdlib.h>

void trocar(int *ptr1, int *ptr2);

int main() {
    int x, y, *ptr1, *ptr2;

    x = 7;
    y = 22;

    ptr1 = &x;
    ptr2 = &y;

    printf("Valor x antes da troca: %d\n", *ptr1);
    printf("Valor y antes da troca: %d\n\n", *ptr2);

    trocar(ptr1, ptr2);

    printf("Valor x depois da troca: %d\n", *ptr1);
    printf("Valor y depois da troca: %d\n\n", *ptr2);

    return 0;
}

void trocar(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}