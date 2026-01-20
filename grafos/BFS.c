#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
    /*Outros dados vao aqui*/
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

typedef struct {
    int chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

int main() {
    return 0;
}

void inicializarFila(FILA *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserirNaFila(FILA *f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
}

void excluirDaFila(FILA *f, REGISTRO *reg) {
    if(f->inicio == NULL) return;

    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);

    if(f->inicio == NULL) {
        f->fim = NULL;
    }
}

void largura(GRAFO *g) {
    bool expl[g->vertices];

    for(int i = 0; i < g->vertices; i++) {
        expl[i] = false;
    }

    for(int i = 0; i < g->vertices; i++) {
        if(!expl[i]) {
            visitaL(g, i, expl);
        }
    }
    
}

//So caminhando
void visitaL(GRAFO *g, int s, bool *expl) {
    FILA f;
    inicializarFila(&f);
    expl[s] = true;
    REGISTRO *u = (REGISTRO *) malloc(sizeof(REGISTRO));
    u->chave = s;
    inserirNaFila(&f, *u);

    while (f.inicio)
    {
        excluirDaFila(&f, u);
        ADJACENCIA *v = g->adj[u->chave].cabeca;

        while (v)
        {
            if(!expl[v->vertice]) {
                expl[v->vertice] = true;
                u->chave = v->vertice;
                inserirNaFila(&f, *u);
            }
            v = v->prox;
        }
    }
    free(u);
}