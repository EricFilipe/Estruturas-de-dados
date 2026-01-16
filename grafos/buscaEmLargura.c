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

void buscaEmLargura(struct str_no g[], int inicio, int alvo) {
    int fila[MAXV];
    bool visitado[MAXV];//Nos visitados
    int indice = 0;//indice topo da fila
    bool achou = false; //flag de controle(nao visitados)
    int corrente = inicio;
    struct str_no *ptr;
    
    printf("=-=-=-= Busca em Largura =-=-=-=\n");

    for (int i = 0; i < MAXV; i++) {
        visitado[i] = false;
    }
    
    //Partindo do primeiro vértice.
    printf("VISITANDO: %d. \n", corrente);

    visitado[corrente] = true;
    fila[indice] = corrente;
    indice++;

    while (true) {
        //Visitar os nós adjacentes ao vértice corrente
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            corrente = ptr->id;
            
            if(!visitado[corrente]) {
                printf("VISITANDO: %d. \n", corrente);

                if(corrente == alvo) {
                    printf("Alvo encontrado!\n\n\n");
                    return;
                }

                visitado[corrente] = true;
                fila[indice] = corrente;
                indice++;
            }
        }

        //Caso a fila não esteja vazia:
        if(indice != 0) {
            corrente = fila[0];

            //Desenfileirando o primeiro vértice.
            for(int i = 1; i < indice + 1; i++) {
                fila[i-1] = fila[i];
            }

            indice--;
        } else {
            printf("Encerramos a busca.\n");
            break;
        }
    }
    

    return;
}