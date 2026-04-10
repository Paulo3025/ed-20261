#include <stdio.h>
#include <time.h>

int main() {

    int matriz[500][500];
    int i, j, k;

    printf("\n Metodo        Tempo (ms)    Valido(0/1)\n");
    printf("------------------------------------------\n");

    // Preenchimento da matriz
    for(i = 0; i < 500; i++) {
        for(j = 0; j < 500; j++) {
            matriz[i][j] = i + j;
        }
    }

    int valido = 1;

    // =============================
    // Metodo 1: dois loops
    // =============================
    clock_t inicio1 = clock();

    for(i = 0; i < 500; i++) {
        for(j = 0; j < 500; j++) {
            int valor = matriz[i][j];
        }
    }

    clock_t fim1 = clock();

    double tempo1 = ((double)(fim1 - inicio1)) / CLOCKS_PER_SEC * 1000;

    // =============================
    // Metodo 2: loop único
    // =============================
    clock_t inicio2 = clock();

    for(k = 0; k < 250000; k++) {
        int linha = k / 500;
        int coluna = k % 500;
        int valor = matriz[linha][coluna];
    }

    clock_t fim2 = clock();

    double tempo2 = ((double)(fim2 - inicio2)) / CLOCKS_PER_SEC * 1000;

    // =============================
    // Saída
    // =============================
    printf("Dois loops     %10.5f     %d\n", tempo1, valido);
    printf("Loop unico     %10.5f     %d\n", tempo2, valido);

    return 0;
}