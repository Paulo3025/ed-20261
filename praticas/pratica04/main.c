#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 1000

/* Função para copiar vetor */
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/* Função para imprimir vetor (opcional) */
void imprimir_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[TAM], v1[TAM], v2[TAM], v3[TAM];
    clock_t inicio, fim;
    double tempo;

    /* Inicializa gerador de números aleatórios */
    srand(time(NULL));

    /* Gera vetor aleatório */
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;  // números entre 0 e 999
    }

    /* Copia vetor original para cada algoritmo */
    copiar_vetor(v, v1, TAM);
    copiar_vetor(v, v2, TAM);
    copiar_vetor(v, v3, TAM);

    /* ================= BUBBLE SORT ================= */
    inicio = clock();
    bubble_sort(v1, TAM);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort: %f segundos\n", tempo);

    /* ================= SELECTION SORT ================= */
    inicio = clock();
    selection_sort(v2, TAM);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Selection Sort: %f segundos\n", tempo);

    /* ================= QUICK SORT ================= */
    inicio = clock();
    quick_sort(v3, 0, TAM - 1);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Quick Sort: %f segundos\n", tempo);

    return 0;
}
