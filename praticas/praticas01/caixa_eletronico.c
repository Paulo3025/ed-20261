#include <stdio.h>

void calcular_notas(int valor, int *n200, int *n100, int *n50,
                   int *n20, int *n10, int *n5, int *n2) {

    *n200 = valor / 200; valor %= 200;
    *n100 = valor / 100; valor %= 100;
    *n50  = valor / 50;  valor %= 50;
    *n20  = valor / 20;  valor %= 20;
    *n10  = valor / 10;  valor %= 10;
    *n5   = valor / 5;   valor %= 5;
    *n2   = valor / 2;
}

int main() {

    printf("\nValor  200 100  50  20  10   5   2  Total  Valido(0/1)\n");
    printf("------------------------------------------------------------------\n");

    int valores[] = {60, 186, 388, 576, -70, 101, 1200, 1350, 1000, 422, 15, 55};
    int tamanho = 12;

    for(int i = 0; i < tamanho; i++) {

        int valor = valores[i];
        int n200=0,n100=0,n50=0,n20=0,n10=0,n5=0,n2=0;
        int total_notas = 0;
        int valido = 1;

        if(valor <= 0 || valor > 1000 || valor % 2 != 0) {
            valido = 0;

            printf("%5d   --- --- --- --- --- --- ---  -----     %d\n", valor, valido);
        } else {

            calcular_notas(valor, &n200, &n100, &n50, &n20, &n10, &n5, &n2);

            total_notas = n200 + n100 + n50 + n20 + n10 + n5 + n2;

            printf("%5d   %3d %3d %3d %3d %3d %3d %3d  %5d     %d\n",
                   valor, n200, n100, n50, n20, n10, n5, n2, total_notas, valido);
        }
    }

    return 0;
}