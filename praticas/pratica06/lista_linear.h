#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdbool.h>

// Definimos Lista como um tipo opaco para o main
typedef struct lista Lista;

/* --- Protótipos das Funções --- */

// Note o uso de Lista ** para criar e destruir
void lista_criar(Lista **l);
bool lista_esta_vazia(Lista *l);
bool lista_inserir(Lista *l, int elemento); // Inserção simples ao final
bool lista_remover(Lista *l, int elemento); // Remoção por valor
int lista_buscar(Lista *l, int elemento);
void lista_exibir(Lista *l);
void lista_destruir(Lista **l);

#endif