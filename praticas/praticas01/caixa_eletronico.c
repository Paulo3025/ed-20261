#include <stdio.h>
#include <stdbool.h>

#define LIMITE_MAX 1000
#define QTD_CEDULAS 7

// Estrutura para organizar os dados das cédulas
typedef struct {
    int valor;
    int quantidade;
} Cedula;

// Função principal de processamento
int processarSaque(int valorSaque) {
    // Validação inicial de limite
    if (valorSaque > LIMITE_MAX || valorSaque <= 0) {
        return 0;
    }

    // Inicialização das cédulas disponíveis
    Cedula caixa[] = {
        {200, 0}, {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}
    };

    int restante = valorSaque;
    int totalNotas = 0;

    // Cálculo das notas
    for (int i = 0; i < QTD_CEDULAS; i++) {
        caixa[i].quantidade = restante / caixa[i].valor;
        restante %= caixa[i].valor;
        totalNotas += caixa[i].quantidade;
    }

    // Se houver resíduo (ex: R$ 1 ou R$ 3), o saque é inválido
    if (restante > 0) {
        return 0;
    }

    // Se o saque for válido, imprime o detalhamento
    printf("Detalhamento para R$ %d:\n", valorSaque);
    for (int i = 0; i < QTD_CEDULAS; i++) {
        if (caixa[i].quantidade > 0) {
            printf("  -> %d nota(s) de R$ %d\n", caixa[i].quantidade, caixa[i].valor);
        }
    }

    return totalNotas;
}

int main() {
    // Casos de teste
    int testes[] = {1200, 100, 277, 1000, 11};
    int n = sizeof(testes) / sizeof(testes[0]);

    printf("========== TESTES PARA caixa_eletronico ==========\n\n");

    for (int i = 0; i < n; i++) {
        int valor = testes[i];
        
        // Executa a lógica e recebe o total de notas
        int resultado = processarSaque(valor);

        // Formatação final conforme o padrão solicitado
        if (resultado == 0) {
            printf("Saque=%-5d Resultado= 0 notas => Valido: 0\n", valor);
        } else {
            printf("Saque=%-5d Resultado= %d notas => Correto: 1\n", valor, resultado);
        }
        printf("--------------------------------------------------\n");
    }

    return 0;
}