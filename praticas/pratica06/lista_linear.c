#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Struct interna para o Nó
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} no_t;

// Struct interna para a Lista (exatamente como pedido: primeiro e ultimo)
struct lista {
    no_t *primeiro;
    no_t *ultimo;
};

void lista_criar(Lista **l) {
    *l = (Lista *)malloc(sizeof(struct lista));
    if (*l != NULL) {
        (*l)->primeiro = NULL;
        (*l)->ultimo = NULL;
    }
}

bool lista_esta_vazia(Lista *l) {
    return (l == NULL || l->primeiro == NULL);
}

bool lista_inserir(Lista *l, int elemento) {
    if (l == NULL) return false;
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = elemento;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    l->ultimo = novo;
    return true;
}

bool lista_remover(Lista *l, int elemento) {
    if (lista_esta_vazia(l)) return false;
    no_t *atual = l->primeiro;

    while (atual != NULL && atual->valor != elemento) {
        atual = atual->proximo;
    }
    if (atual == NULL) return false;

    if (atual->anterior != NULL) 
        atual->anterior->proximo = atual->proximo;
    else 
        l->primeiro = atual->proximo;

    if (atual->proximo != NULL) 
        atual->proximo->anterior = atual->anterior;
    else 
        l->ultimo = atual->anterior;

    free(atual);
    return true;
}

int lista_buscar(Lista *l, int elemento) {
    if (lista_esta_vazia(l)) return -1;
    no_t *atual = l->primeiro;
    int i = 0;
    while (atual != NULL) {
        if (atual->valor == elemento) return i;
        atual = atual->proximo;
        i++;
    }
    return -1;
}

void lista_exibir(Lista *l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    no_t *atual = l->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_destruir(Lista **l) {
    if (l == NULL || *l == NULL) return;
    no_t *atual = (*l)->primeiro;
    while (atual != NULL) {
        no_t *aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    free(*l);
    *l = NULL;
}