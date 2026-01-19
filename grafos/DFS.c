#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
    /*outros dados vao aqui*/
    ADJACENCIA *cabeca;
} VERTICE; 

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

int main() {

    return 0;
}

void profundidade(GRAFO *g) {
    int cor[g->vertices];

    for(int i = 0; i < g->vertices; i++) {
        cor[i] = BRANCO;
    }

    for(int i = 0; i < g->vertices; i++) {
        if(cor[i] == BRANCO) {
            visitaProfundidade(g, i, cor);
        }
    }
}

//So caminhando
void visitaProfundidade(GRAFO *g, int i, int *cor) {
    cor[i] = AMARELO;
    ADJACENCIA *v = g->adj[i].cabeca;
    while (v)
    {
        if(cor[v->vertice] == BRANCO) {
            visitaProfundidade(g, v->vertice, cor);
            v = v->prox;
        }
    }
    cor[i] = VERMELHO;
}