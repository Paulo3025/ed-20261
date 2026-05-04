#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

int main() {
    // 1. Declara o ponteiro para a lista
    Lista *minha_lista = NULL;

    // 2. Inicializa a lista
    printf("--- Criando a Lista ---\n");
    lista_criar(&minha_lista);

    if (lista_esta_vazia(minha_lista)) {
        printf("Lista criada com sucesso e esta vazia.\n");
    }

    // 3. Testando Inserções
    printf("\n--- Inserindo Elementos ---\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_inserir(minha_lista,60);
    lista_exibir(minha_lista);

    // 4. Testando Busca
    printf("\n--- Buscando Elementos ---\n");
    int valor_busca = 30;
    int pos = lista_buscar(minha_lista, valor_busca);
    if (pos != -1) {
        printf("O valor %d foi encontrado no indice: %d\n", valor_busca, pos);
    } else {
        printf("Valor %d nao encontrado.\n", valor_busca);
    }

    // 5. Testando Remoção
    printf("\n--- Removendo Elementos (20 e 40) ---\n");
    if (lista_remover(minha_lista, 20)) {
        printf("Valor 20 removido.\n");
    }
    if (lista_remover(minha_lista, 40)) {
        printf("Valor 40 removido (ultimo elemento).\n");
    }
    lista_exibir(minha_lista);

    // 6. Testando inserção após remoção
    printf("\n--- Inserindo valor 50 ---\n");
    lista_inserir(minha_lista, 50);
    lista_exibir(minha_lista);

    // 7. Destruindo a lista e liberando memória
    printf("\n--- Destruindo a Lista ---\n");
    lista_destruir(&minha_lista);

    if (minha_lista == NULL) {
        printf("Memoria liberada e ponteiro definido como NULL.\n");
    }

    return 0;
}