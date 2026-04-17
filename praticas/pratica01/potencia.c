#include <stdio.h>

// Função que calcula a potência
int calcular_potencia(int base, int expoente)
{
    if (expoente < 0)
    {
        return 0; // inválido (somente expoente positivo)
    }

    int resultado = 1;

    for (int i = 0; i < expoente; i++)
    {
        resultado = resultado * base;
    }

    return resultado;
}

int main()
{
    int resultado;
     printf("\n\n========== TESTES PARA  calcular_potencia  ========\n\n");

    // Caso 1 - inválido (expoente negativo)
    resultado = calcular_potencia(2, -3);
    printf("Base=2 Expoente=-3 Resultado= %d => Valido: %d\n", resultado, resultado != 0);

    // Caso 2 - expoente zero
    resultado = calcular_potencia(5, 0);
    printf("Base=5 Expoente=0 Resultado= %d => Correto: %d\n", resultado, resultado == 1);

    // Caso 3 - potência simples
    resultado = calcular_potencia(2, 3);
    printf("Base=2 Expoente=3 Resultado= %d => Correto: %d\n", resultado, resultado == 8);

    // Caso 4 - potência maior
    resultado = calcular_potencia(3, 4);
    printf("Base=3 Expoente=4 Resultado= %d => Correto: %d\n\n\n", resultado, resultado == 81);

    return 0;
}