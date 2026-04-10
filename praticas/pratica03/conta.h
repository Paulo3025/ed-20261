#ifndef CONTA_H
#define CONTA_H

/* * Definição do tipo Conta. 
    * Cada conta possui um número identificador e um saldo. */

typedef struct {
    int numero;
    double saldo;
} Conta;

/* --- Protótipos das Funções --- */

// Cria uma nova conta com um número e saldo inicial./
 
Conta* conta_criar(int numero, double saldo_inicial);


 // Adiciona um valor ao saldo da conta./
 
void conta_depositar(Conta* c, double valor);

//Remove um valor do saldo da conta, se houver saldo suficiente.//
 
int conta_sacar(Conta* c, double valor);


 // Retorna o saldo atual da conta.//
 
double conta_ver_saldo(Conta* c);

//Libera a memória alocada para a conta.
 
void conta_destruir(Conta* c);

#endif // CONTA_H