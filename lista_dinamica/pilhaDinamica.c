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
ptr_no pilha;
int option;

//Prototipagem
void menu_mostrar();
void menu_selecionar(int option);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);

int main() {
    //Inicializando maquina de numeros randomicos
    srand(time(NULL));

    option = 1;

    //criando o primeiro no na pilha
    pilha = (ptr_no)malloc(sizeof(struct no));

    pilha->dado = 0;
    pilha->proximo = NULL;

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
    pilha_mostrar(pilha);

    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover no final da pilha\n");
    printf("0 - Sair\n");
}

void menu_selecionar(int option) {
    switch (option)
    {
    case 1:
        pilha_inserir(pilha);
        break;
    
    case 2:
        pilha_remover(pilha);
        break;

    default:
        break;
    }
}

void pilha_inserir(ptr_no pilha) {
    while (pilha->proximo != NULL)
    {
        pilha = pilha->proximo;
    }

    pilha->proximo = (ptr_no)malloc(sizeof(struct no));
    
    pilha = pilha->proximo;

    pilha->dado = rand()%100;
    pilha->proximo = NULL;
}

void pilha_remover(ptr_no pilha) {
    ptr_no atual = (ptr_no)malloc(sizeof(struct no)); 
    while (pilha->proximo != NULL)
    {
        atual = pilha;
        pilha = pilha->proximo;
    }

    atual->proximo = NULL;
    
}

void pilha_mostrar(ptr_no pilha) {
    while (pilha->proximo != NULL)
    {
        printf("%d", pilha->dado);
        pilha = pilha->proximo;
    }

    printf("%d", pilha->dado);
    
}