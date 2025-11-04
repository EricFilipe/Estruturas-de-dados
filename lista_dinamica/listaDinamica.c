#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definindo aestrutura da pilha
struct no {
    int dado;
    struct no *proximo;
};

//Variaveis
typedef struct no *ptr_no;
ptr_no fila;
int option;

//Prototipagem
void menu_mostrar();
void menu_selecionar(int option);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);

int main() {
    //Inicializando maquina de numeros randomicos
    srand(time(NULL));

    option = 1;

    //criando o primeiro no na fila
    fila = (ptr_no)malloc(sizeof(struct no));

    fila->dado = 0;
    fila->proximo = NULL;

    while (option != 0)
    {
        menu_mostrar();

        scanf("%d", &option);

        menu_selecionar(option);
    }

    system("pause");
    return 0;
}

void menu_mostrar() {
    fila_mostrar(fila);

    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da fila\n");
    printf("2 - Remover no inicio da fila\n");
    printf("0 - Sair\n");
}

void menu_selecionar(int option) {
    switch (option)
    {
    case 1:
        fila_inserir(fila);
        break;
    
    case 2:
        fila_remover(fila);
        break;

    default:
        break;
    }
}

void fila_inserir(ptr_no fila) {
    while (fila->proximo != NULL)
    {
        fila = fila->proximo;
    }

    fila->proximo = (ptr_no)malloc(sizeof(struct no));
    
    fila = fila->proximo;

    fila->dado = rand()%100;
    fila->proximo = NULL;
}

void fila_remover(ptr_no fila) {
    ptr_no atual = fila;

    if(fila->proximo != NULL) {
        fila = fila->proximo;
        atual->proximo = fila->proximo;
    }
}

void fila_mostrar(ptr_no fila) {
    while (fila->proximo != NULL)
    {
        printf("%d", fila->dado);
        fila = fila->proximo;
    }

    printf("%d", fila->dado);
    
}