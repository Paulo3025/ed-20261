#include <stdio.h>

// Iterativo
unsigned long long fatorial_iterativo(int n) {
    unsigned long long resultado = 1;

    for(int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

// Recursivo
unsigned long long fatorial_recursivo(int n) {
    if(n == 0) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {

    printf("\n n   Fatorial(iter)   Fatorial(rec)   Valido(0/1)\n");
    printf("---------------------------------------------------\n");

    int valores[] = {5, 0, 10, -3};
    int tamanho = 4;

    for(int i = 0; i < tamanho; i++) {

        int n = valores[i];
        int valido = 1;

        if(n < 0) {
            valido = 0;
            printf(" %3d   -----------      -----------      %d\n", n, valido);
        } else {
            unsigned long long fi = fatorial_iterativo(n);
            unsigned long long fr = fatorial_recursivo(n);

            printf("%3d   %13llu   %13llu      %d\n", n, fi, fr, valido);
        }
    }

    return 0;
}