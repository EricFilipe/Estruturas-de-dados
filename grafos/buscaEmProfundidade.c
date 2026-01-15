#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXV 7

typedef struct str_no {
    int id;
    struct str_no *proximo;
}str_no;

struct str_no grafo[MAXV];

int main() {

    return 0;
}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo) {
    int pilha[MAXV];
    bool visitado[MAXV];//Nos visitados
    int indice = 0;//indice topo da pilha
    bool achou = false; //flag de controle(nao visitados)
    int corrente = inicio;
    struct str_no *ptr;
    
    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");

    for (int i = 0; i < MAXV; i++) {
        visitado[i] = false;
    }
    
    while (true)
    {
        //Nó corrente não visitado? Marque como visitado.
        //Empilhe o nó corrente.
        if(!visitado[corrente]) {
            printf("VISITANDO: %d. \n", corrente);

            if(corrente == alvo) {
                printf("Alvo encontrado!\n\n\n");
                return;
            }

            visitado[corrente] = true;
            pilha[indice] = corrente;
            indice++;
        }

        //Buscando por nós adjacentes, não visitados.
        achou = false;
        for (ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            if(!visitado[ptr->id]) {
                achou = true;
                break;
            }
        }
        
        if(achou) {
            corrente = ptr->id;
        } else {
            //Não há vértices adjacentes não visitados.
            //Tentando desempilhar o vértice do topo.
            indice--;
            if(indice == -1) {
                printf("Encerrando a busca. \n");
                break;
            }

            corrente = pilha[indice-1];
        }
    }
    
    return;
}