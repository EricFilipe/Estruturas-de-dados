#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct {
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

void inicializarD(GRAFO *g, int *d, int *p, int s);
void relaxa(GRAFO *g, int *d, int *p, int u, int v);
bool existeAberto(GRAFO *g, int *aberto);
int menorDist(GRAFO *g, int *aberto, int *d);
int *dijkstra(GRAFO *g, int s);
GRAFO *criaGrafo(int v);
ADJACENCIA *criaAdj(int v, TIPOPESO p);
bool criaAresta(GRAFO *g, int vi, int vf, TIPOPESO p);

int main() {
    GRAFO *g = criaGrafo(6);

    criaAresta(g, 0, 1, 10);
    criaAresta(g, 0, 2, 5);
    criaAresta(g, 2, 1, 3);
    criaAresta(g, 1, 3, 1);
    criaAresta(g, 2, 3, 8);
    criaAresta(g, 2, 4, 2);
    criaAresta(g, 4, 5, 6);
    criaAresta(g, 3, 5, 4);
    criaAresta(g, 3, 4, 4);

    int *r = dijkstra(g, 0);

    for (int i = 0; i < g->vertices; i++)
    {
        printf("D(v0 -> v%d) = %d\n", i, r[i]);
    }
    
}

//Fazemos d[v] = "infinito" para todo no que nao e inicial
void inicializarD(GRAFO *g, int *d, int *p, int s) {
    int v;
    for(v = 0; v < g->vertices; v++) {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

//Relaxamento de (u,v)
void relaxa(GRAFO *g, int *d, int *p, int u, int v) {
    ADJACENCIA *ad = g->adj[u].cabeca;
    while (ad && ad->vertice != v) 
    {
        ad = ad->prox;
    }

    if(ad) {
        if(d[v] > d[u] + ad->peso) {
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}

//Varre todos os vertices do grafo, retornando true se encontrar algum aberto
bool existeAberto(GRAFO *g, int *aberto) {
    for (int i = 0; i < g->vertices; i++) {
        if(aberto[i]) return(true);
    }

    return(false);
}

int menorDist(GRAFO *g, int *aberto, int *d) {
    int i;
    for (i = 0; i < g->vertices; i++) {
        if(aberto[i]) break;
    }
    if(i == g->vertices) return(-1);
    int menor = i;

    for (i = menor + 1; i < g->vertices; i++) {
        if(aberto[i] && (d[menor] > d[i])) {
            menor = i;
        }
    }
    return(menor);
}

int *dijkstra(GRAFO *g, int s) {
    int *d = (int *) malloc(sizeof(int) * g->vertices);
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializarD(g, d, p, s);

    for(int i = 0; i < g->vertices; i++) {
        aberto[i] = true;
    }

    while (existeAberto(g, aberto))
    {
        int u = menorDist(g, aberto, d);
        aberto[u] = false;

        ADJACENCIA *ad = g->adj[u].cabeca;
        while (ad) 
        {
            relaxa(g, d, p, u, ad->vertice);
            ad = ad->prox;
        }
    }
    return(d);
}

GRAFO *criaGrafo(int v) {
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));

    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc(sizeof(VERTICE) * v);

    for (int i = 0; i < g->vertices; i++)
    {
        g->adj[i].cabeca = NULL;
    }
    
    return g;
}

ADJACENCIA *criaAdj(int v, TIPOPESO p) {
    ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));

    temp->vertice = v;
    temp->peso = p;
    temp->prox = NULL;

    return temp;
}

bool criaAresta(GRAFO *g, int vi, int vf, TIPOPESO p) {
    if(!g) return false;
    if(vi < 0 || vi >= g->vertices) return false;
    if(vf < 0 || vf >= g->vertices) return false;

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = g->adj[vi].cabeca;
    g->adj[vi].cabeca = novo;
    g->arestas++;

    return true;
}