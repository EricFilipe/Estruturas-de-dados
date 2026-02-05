#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definindo a estrutura da lista
struct no {
    int dado;
    struct no *proximo;
};

//Variaveis
typedef struct no *ptr_no;
ptr_no lista;
int option;

//Prototipacao
void menu_mostrar();
void menu_selecionar(int option);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

int main() {
    //Inicializando maquina de numeros randomicos
    srand(time(NULL));

    option = 1;

    //Criando primeiro no da lista, no cabeca
    lista = (ptr_no)malloc(sizeof(struct no));

    lista->dado = 0;
    lista->proximo = NULL;

    while(option != 0) {
        system("cls");

        menu_mostrar();

        scanf("%d", &option);

        menu_selecionar(option);
    }

    system("pause");
    return 0;
}

void menu_mostrar() {
    lista_mostrar(lista);

    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da lista\n");
    printf("2 - Remover um item da lista\n");
    printf("0 - Sair\n");
}

void menu_selecionar(int option) {
    switch (option)
    {
    case 1:
        lista_inserir(lista);
        break;
    
    case 2:
        lista_remover(lista);
        break;

    default:
        break;
    }
}

void lista_inserir(ptr_no lista) {
    while (lista->proximo != NULL)
    {
        lista = lista->proximo;
    }

    lista->proximo = (ptr_no)malloc(sizeof(struct no));
    
    lista = lista->proximo;

    lista->dado = rand()%100;

    lista->proximo = NULL;
}

void lista_remover(ptr_no lista) {
    int dado;
    ptr_no atual = (ptr_no)malloc(sizeof(struct no));
    
    printf("\n\nEscolha um dos itens:\n");
    scanf("%d", &dado);

    while (lista->dado != dado)
    {
        if(lista->proximo == NULL) {
            printf("item nao encontrado");
            break;
        }
        
        atual = lista;
        lista = lista->proximo;
    }

    if(lista->dado == dado) {
        atual->proximo = lista->proximo;
    }

}

void lista_mostrar(ptr_no lista) {
    system("cls");

    while (1)
    {
        printf("%d", lista->dado);
        if(lista->proximo == NULL) {
            break;
        }

        lista = lista->proximo;
    }
}

