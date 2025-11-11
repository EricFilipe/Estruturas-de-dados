#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define tamanho 10

int lista[tamanho];
int ordenado[tamanho];
int option;
int qtde;

void menu_mostrar();
void lista_mostrar();
void lista_gerar();
void lista_ler();
void lista_limpar();
void lista_mostrar_ordenado();
int bubbleSort(int ordenado[]);
int selectionSort(int ordenado[]);
int insertionSort(int ordenado[]);
int shellSort(int ordenado[]);
void troca(int *a, int *b);

int main(void) {
    srand(time(NULL));

    do{
        lista_mostrar();

        lista_mostrar_ordenado();

        menu_mostrar();

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            lista_gerar();
            break;
        
        case 2:
            lista_ler();
            break;
            
        case 3:
            bubbleSort(ordenado);
            break;

        case 4:
            selectionSort(ordenado);
            break;

        case 5:
            insertionSort(ordenado);
            break;

        case 6:
            shellSort(ordenado);
            break;

        default:
            break;
        }
    } while (option != 0);

    system("pause");
    return 0;
}

void lista_mostrar() {
    
    for(int i = 0; i < tamanho; i++) {
        printf("[%d]", lista[i]);
    }
    
}

void menu_mostrar() {
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - Ordenar bubbleSort\n");
    printf("4 - Ordenar selectionSort\n");
    printf("5 - Ordenar insertionSort\n");
    printf("6 - Ordenar shellSort\n");
    printf("0 - sair\n\n");
}

void lista_gerar() {
    for(int i = 0; i < tamanho; i++) {
        lista[i] = rand()%50;
    }
}

void lista_ler() {
    for(int i = 0; i < tamanho; i++) {
        lista_mostrar();

        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%d", &lista[i]);
    }
}

void lista_limpar() {
    for(int i = 0; i < tamanho; i++) {
        ordenado[i] = lista[i];
    }
}

void lista_mostrar_ordenado() {
    printf("\n");
    for(int i = 0; i < tamanho; i++) {
        printf("[%d]", ordenado[i]);
    }

    printf("\nTempo = %d iteracoes\n\n", qtde);
}

int bubbleSort(int ordenado[]) {
    lista_limpar();
    qtde = 0;

    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(ordenado[i] > ordenado[j]) {
                troca(&ordenado[i], &ordenado[j]);
            }

            qtde++;
        }
    }

    return(qtde);
}

int selectionSort(int ordenado[]) {
    lista_limpar();
    qtde = 0;

    for(int i = 0; i < tamanho - 1; i++) {
        int min = i;
        for(int j = i + 1; j < tamanho; j++) {
            if(ordenado[j] < ordenado[min]) {
                min = j;
            } 
            qtde++;
        }


        if(i != min) {
            troca(&ordenado[i], &ordenado[min]);
        }
    }


    return(qtde);
}

int insertionSort(int ordenado[]) {
    lista_limpar();
    qtde = 0;

    for (int i = 1; i < tamanho; i++) {
        int j = i;

        while((ordenado[j] < ordenado[j - 1]) && j != 0) {
            troca(&ordenado[j], &ordenado[j - 1]);
            j--;
            qtde++;
        } 
    }
    
    return(qtde);
}

int shellSort(int ordenado[]) {
    lista_limpar();
    qtde = 0;
    int gap = 1;
    int valor;

    do {
        gap = 3 * gap + 1;
    } while (gap < tamanho);
    
    do {
        gap /= 3;

        for(int i = gap; i < tamanho; i++) {
            valor = ordenado[i];

            int j = i - gap;

            while (j >= 0 && valor < ordenado[j])
            {
                ordenado[j + gap] = ordenado[j];
                j -= gap;
                qtde++;
            }

            ordenado[j + gap] = valor;
            
        }
    } while(gap > 1);

    return(qtde);
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

