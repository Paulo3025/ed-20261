#include <stdio.h>

// Função de busca sequencial
int busca_sequencial(int vetor[], int n, int chave) {
    for(int i = 0; i < n; i++) {
        if(vetor[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main() {

    printf("\n Chave  Posicao  Resultado         Valido(0/1)   Analise\n");
    printf("------------------------------------------------------------------\n");

    // Vetor de teste
    int vetor[] = {10, 20, 30, 40, 50};
    int n = 5;

    int chaves[] = {10, 30, 50, 70};
    int tamanho = 4;

    for(int i = 0; i < tamanho; i++) {

        int chave = chaves[i];
        int valido = 1;

        if(n <= 0 || n > 100) {
            valido = 0;
            printf("%5d   --------  Dados invalidos   %d\n", chave, valido);
        } else {

            int pos = busca_sequencial(vetor, n, chave);

            if(pos == -1) {
                // Pior caso: percorreu todo o vetor e não achou
                printf("%5d   %8d  Nao encontrado     %d          Pior Caso (O(n))\n", chave, pos, valido);
            } else {
                if(pos == 0) {
                    // Melhor caso: achou na primeira tentativa
                    printf("%5d   %8d  Encontrado         %d          Melhor Caso (O(1))\n", chave, pos, valido);
                } else if(pos == n - 1) {
                    // Pior caso: achou apenas na última posição
                    printf("%5d   %8d  Encontrado         %d          Pior Caso (O(n))\n", chave, pos, valido);
                } else {
                    // Caso médio
                    printf("%5d   %8d  Encontrado         %d          Caso Medio\n", chave, pos, valido);
                }
            }
        }
    }

    return 0;
}