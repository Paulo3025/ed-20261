#include <stdio.h>
#include "conta.h"

int main() {
    // 1. Criar uma nova conta com saldo inicial de R$ 1255,00

    printf("--- Criando conta 25128 com saldo de R$ 2550.00 ---\n");
    Conta* minha_conta = conta_criar(25128, 2550.00);

    if (minha_conta == NULL) {
        printf("Erro ao criar conta!\n");
        return 1;
    }

    // 2. Consultar saldo inicial

    printf("Saldo inicial: R$ %.2f\n", conta_ver_saldo(minha_conta));

    // 3. Testar Depósito

    printf("\nDepositando R$ 550.00...\n");
    conta_depositar(minha_conta, 550.00);
    printf("Novo saldo: R$ %.2f\n", conta_ver_saldo(minha_conta));

    // 4. Testar Saque com sucesso

    printf("\nTentando sacar R$ 1800.00...\n");
    if (conta_sacar(minha_conta, 800.00)) {
        printf("Saque realizado! Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));
    } else {
        printf("Falha no saque!\n");
    }

    // 5. Testar Saque sem saldo suficiente

    printf("\nTentando sacar R$ 2856.00 (mais que o saldo)...\n");
    if (conta_sacar(minha_conta, 2856.00)) {
        printf("Saque realizado!\n");
    } else {
        printf("Saque negado: Saldo insuficiente.\n");
    }

    // 6. Consultar saldo final e destruir
    printf("\nSaldo final na conta: R$ %.2f\n", conta_ver_saldo(minha_conta));
    
    printf("Destruindo conta e liberando memoria...\n");
    conta_destruir(minha_conta);

    return 0;
}