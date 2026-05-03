#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

int main() {
    int vetor[TAMANHO];
    int vetor_copia[TAMANHO];
    clock_t inicio_t, fim_t;
    double tempo_cpu;

    // 1. Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // 2. Preenche o vetor com números aleatórios entre 0 e 999
    printf("Gerando vetor de %d elementos...\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 1000;
        vetor_copia[i] = vetor[i]; // Cópia para manter o vetor original
    }

    printf("-------------------------------------------\n");

    // --- TESTE: Linear Search ---
    int alvo = vetor[TAMANHO / 2]; // Escolhe um elemento que sabemos que existe
    printf("Busca Linear: Procurando valor %d...\n", alvo);
    
    inicio_t = clock();
    int indice = linear_search(vetor, TAMANHO, alvo);
    fim_t = clock();
    
    tempo_cpu = ((double)(fim_t - inicio_t)) / CLOCKS_PER_SEC;
    printf("Resultado: Encontrado no indice %d\n", indice);
    printf("Tempo de execucao: %f segundos\n", tempo_cpu);

    printf("-------------------------------------------\n");

    // --- TESTE: Quick Select ---
    int k = 1000; // Queremos o 10º menor elemento
    printf("Quick Select: Procurando o %do menor elemento...\n", k);
    
    inicio_t = clock();
    int valor_k = quick_select(vetor_copia, 0, TAMANHO - 1, k);
    fim_t = clock();
    
    tempo_cpu = ((double)(fim_t - inicio_t)) / CLOCKS_PER_SEC;
    printf("Resultado: O %do menor elemento e %d\n", k, valor_k);
    printf("Tempo de execucao: %f segundos\n", tempo_cpu);

    return 0;
}