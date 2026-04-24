#include "selecao.h"

// Função auxiliar temp ( troca dois elementos de lugar)
void trocar(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

// Função auxiliar de particionamento 
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; // Escolhe o último elemento como pivô
    int i = inicio;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            trocar(&vetor[i], &vetor[j]);
            i++;
        }
    }
    trocar(&vetor[i], &vetor[fim]);
    return i;
}

// --- Implementação das Funções do Cabeçalho (selecao.h) ---

int linear_search(int vetor[], int tamanho, int elemento_alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento_alvo) {
            return i; // Retorna o índice onde o elemento foi encontrado
        }
    }
    return -1; // Elemento não encontrado
}

int quick_select(int vetor[], int inicio, int fim, int k) {
    // Se k for um número válido dentro do intervalo
    if (k > 0 && k <= fim - inicio + 1) {
        
        // Particiona o vetor e obtém a posição do pivô
        int indice_pivo = particionar(vetor, inicio, fim);

        // Se a posição do pivô for exatamente o que buscamos
        if (indice_pivo - inicio == k - 1) {
            return vetor[indice_pivo];
        }

        // Se a posição for maior, busca na partição da esquerda
        if (indice_pivo - inicio > k - 1) {
            return quick_select(vetor, inicio, indice_pivo - 1, k);
        }

        // Caso contrário, busca na partição da direita
        return quick_select(vetor, indice_pivo + 1, fim, k - (indice_pivo - inicio + 1));
    }

    return -1; // Caso k esteja fora dos limites
}