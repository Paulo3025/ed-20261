#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

// Definição da estrutura interna.

struct conta_t {
    int numero;
    double saldo;
};

// Implementação da função para criar a conta
Conta* conta_criar(int numero, double saldo_inicial) {
    // Aloca memória para a estrutura
    Conta* nova_conta = (Conta*) malloc(sizeof(Conta));
    
    if (nova_conta != NULL) {
        nova_conta->numero = numero;
        nova_conta->saldo = saldo_inicial;
    }
    
    return nova_conta;
}

// Implementação do depósito
void conta_depositar(Conta* c, double valor) {
    if (c != NULL && valor > 0) {
        c->saldo += valor;
    }
}

// Implementação do saque com verificação de saldo
int conta_sacar(Conta* c, double valor) {
    if (c != NULL && valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        return 1; // Sucesso
    }
    return 0; // Falha (saldo insuficiente ou parâmetros inválidos)
}

// Retorna o saldo atual
double conta_ver_saldo(Conta* c) {
    if (c != NULL) {
        return c->saldo;
    }
    return 0.0;
}

// Libera a memória alocada
void conta_destruir(Conta* c) {
    if (c != NULL) {
        free(c);
    }
}