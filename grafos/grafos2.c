#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int TIPOPESO;
typedef int bool;

typedef struct adjcencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct {
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criarGrafo(int v);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO *g, int vi, int vf, TIPOPESO peso);
void mostrarGrafo(GRAFO *g);

int main() {
    GRAFO *g = criarGrafo(5);

    criaAresta(g, 0, 1, 3);
    criaAresta(g, 1, 2, 7);
    criaAresta(g, 2, 0, 12);
    criaAresta(g, 2, 3, 40);
    criaAresta(g, 3, 4, 10);
    criaAresta(g, 4, 1, 2);

    mostrarGrafo(g);

    return 0;
}

GRAFO *criarGrafo(int v) {
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));

    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc(sizeof(VERTICE) * v);

    for (int i = 0; i < v; i++)
    {
        g->adj[i].cabeca = NULL;
    }
    
    return(g);
}

ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}

bool criaAresta(GRAFO *g, int vi, int vf, TIPOPESO peso) {
    if(!g) return false;
    if(vf < 0 || vf >= g->vertices) return false;
    if(vi < 0 || vi >= g->vertices) return false;

    ADJACENCIA *novo = criaAdj(vf, peso);
    novo->prox = g->adj[vi].cabeca;
    g->adj[vi].cabeca = novo;
    g->arestas++;
    return true;
}

void mostrarGrafo(GRAFO *g) {
    printf("Vertices: %d, Arestas: %d\n", g->vertices, g->arestas);

    for (int i = 0; i < g->vertices; i++)
    {
        ADJACENCIA *ad = g->adj[i].cabeca;

        printf("v%d: ", i);
        while (ad)
        {
            printf("v%d p(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
        
    }
    
    
}