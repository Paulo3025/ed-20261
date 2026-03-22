#include <stdio.h>

// Função que calcula o total de notas para um saque e exibe o detalhamento
int calcular_saque(int valor) {
    if (valor < 0 || valor > 1000) {
        return 0; // Saque inválido
    }

    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int total_notas = 0;
    int resto = valor;

    for (int i = 0; i < 7; i++) {
        total_notas += resto / notas[i];
        resto %= notas[i];
    }

    // Se sobrou resto (ex: R$ 1 ou R$ 3), o saque não é possível com as notas atuais
    if (resto > 0) return 0;

    return total_notas;
}

int main() {
    int resultado;
    printf("\n\n========== TESTES PARA  caixa_eletronico  ========\n\n");

    // Caso 1 - Valor acima do limite
    resultado = calcular_saque(1200);
    printf("Saque=1200 Resultado= %d notas => Valido: %d\n", resultado, resultado != 0);

    // Caso 2 - Valor exato (uma nota)
    resultado = calcular_saque(100);
    printf("Saque=100  Resultado= %d notas => Correto: %d\n", resultado, resultado == 1);

    // Caso 3 - Valor composto (200 + 50 + 20 + 5 + 2)
    resultado = calcular_saque(277);
    printf("Saque=277  Resultado= %d notas => Correto: %d\n", resultado, resultado == 5);

    // Caso 4 - Valor máximo permitido
    resultado = calcular_saque(1000);
    printf("Saque=1000 Resultado= %d notas => Correto: %d\n\n\n", resultado, resultado == 5);

    return 0;
}
