#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define tamanho 10

int lista[tamanho];
int ordenado[tamanho];
int option;
int qtde;
int tam = tamanho;

void menu_mostrar();
void lista_mostrar(); 
void lista_gerar();
void lista_ler();
int mergeSort(int lista[], int tam, int qtde);
int quickSort(int lista[], int left, int right, int qtde);
int heapSort(int vec[], int tam);
int particiona(int vec[], int left, int right);
void junta(int lista[], int tam);
int constroiHeap(int vec[], int tam);
int heapify(int vec[], int tam, int i);
void troca(int *a, int *b);
int valor;


int main(void) {
    srand(time(NULL));

    do{
        lista_mostrar();

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
            mergeSort(lista, tam, qtde);
            break;

        case 4:
            valor = quickSort(lista, tam - tam, tam -1, qtde);
            break;

        case 5:
            heapSort(lista, tam);
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

    printf("\nTempo = %d iteracoes\n\n", valor);
    
}

void menu_mostrar() {
    printf("\n1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - Ordenar mergeSort\n");
    printf("4 - Ordenar quickSort\n");
    printf("5 - Ordenar heapSort\n");
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



int mergeSort(int vec[], int tam, int qtde) {
    int meio;

    if(tam > 1) {
        meio = tam / 2;
        qtde = mergeSort(vec, meio, qtde);
   
        qtde = mergeSort(vec + meio, tam - meio, qtde);

        junta(vec, tam);
    }

    return(qtde + 1);
}

void junta(int vec[], int tam) {
    int i, j, k;
    int meio;
    int *temp;

    temp = (int*)malloc(sizeof(int) * tam);

    if(temp == NULL) {
    exit(1);
    }

    meio = tam / 2;

    i = 0;
    j= meio;
    k = 0;

    while (i < meio && j < tam)
    {
        if(vec[i] <= vec[j]) {
            temp[k] = vec[i];
            i++;
        } else {
            temp[k] = vec[j];
            j++;
        }

        k++;
    }

    if(i == meio) {
        while (j < tam)
        {
            temp[k] = vec[j];
            j++;
            k++;
        }
    } else {    
    while (i < meio)
        {
            temp[k] = vec[i];
            i++;
            k++;
        }  
    }

    for(i = 0; i < tam; i++) {
    vec[i] = temp[i];
    }

    free(temp);  
}

int quickSort(int vec[], int left, int right, int qtde) {
    int r;

    if(right > left) {
        r = particiona(vec, left, right);

        qtde = quickSort(vec, left, r - 1, qtde);

        qtde = quickSort(vec, r+1, right, qtde);
    }

    return(qtde + 1); 
}

int particiona(int vec[], int left, int right) {
    int i, j;

    i = left;

    for(j = left + 1; j <= right; j++) {
        if(vec[j] < vec[left]) {
            i++;

            troca(&vec[i], &vec[j]);
        }
    }

    troca(&vec[left], &vec[i]);
    return i;
}

int heapify(int vec[], int tam, int i) {
    int e, d, maior, qtd;

    qtd = 1;
    e = 2 * i + 1;
    d = 2 * i + 2;

    if(e < tam && vec[e] > vec[i]) {
        maior = e;
    } else {
        maior = i;
    }

    if(d < tam && vec[d] > vec[maior]) {
        maior = d;
    }

    if(maior != i) {
        troca(&vec[i], &vec[maior]);
        qtd += heapify(vec, tam, maior);
    }

    return qtd;
}

int constroiHeap(int vec[], int tam) {
    int qtd = 0;

    for(int i = tam / 2; i >= 0; i--) {
        qtd += heapify(vec, tam, i);
    }

    return qtd;
}

int heapSort(int vec[], int tam) {
    int n, qtd;

    qtd = 0;

    qtd += constroiHeap(vec, tam);

    n = tam;

    for(int i = tam -1; i > 0; i--) {
        troca(&vec[0], &vec[i]);
        n--;
        qtd += heapify(vec, n, 0);
    }

    return qtd;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}