#include<stdio.h>
#include<stdlib.h>

void inverter(char *str);

int main() {
    
    char str[] = "ponteiro";
    char *ptr;

    ptr = str;

    inverter(ptr);

    printf("\n\n");

    return 0;
}

void inverter(char *str) {
    int tamanho = 0;
    char *inicio = str;

    while(*str != '\0') {
        str = str+1;
        tamanho++;
    }

    str = inicio;
    char *ptr_f = inicio + tamanho - 1;

    for(int i = 0; i < (tamanho / 2); i++) {
        char temp = *str;
        *str = *ptr_f;
        *ptr_f = temp;
        str += 1;
        ptr_f -= 1;
    }

    printf("%s", inicio);
    
}