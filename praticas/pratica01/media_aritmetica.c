#include <stdio.h>

// Função que calcula a média
float calcular_media(int n, float valores[]){
    if(n <= 0 || n > 100){
        return 0; // inválido
    }

    float soma = 0;

    for(int i = 0; i < n; i++){
        soma += valores[i];
    }

    return soma / n;
}

int main(){

    printf("\n\n========== TESTES PARA  CALCULAR MEDIA ARITMETICA     ========\n\n");

    float media;

    // Caso 1 - inválido (n = 0)
    float v1[] = {};
    media = calcular_media(0, v1);
    printf("n=0 Media=%.2f => Valido: %d\n", media, media > 0);

    // Caso 2 - válido (3 valores)
    float v2[] = {10, 20, 30};
    media = calcular_media(3, v2);
    printf("n=3 Media=%.2f => Correto: %d\n", media, media == 20);

    // Caso 3 - válido (5 valores)
    float v3[] = {5, 5, 5, 5, 5};
    media = calcular_media(5, v3);
    printf("n=5 Media=%.2f => Correto: %d\n", media, media == 5);

    // Caso 4 - inválido (n > 100)
    float v4[101];
    media = calcular_media(101, v4);
    printf("n=101 Media=%.2f => Valido: %d\n\n\n", media, media > 0);

    return 0;
}