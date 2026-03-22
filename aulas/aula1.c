#include <stdio.h>
#include <stdlib.h>
# include <time.h>


long int main(){
// ligar o cronometro 

clock_t tempo_inicial = clock();
// código a ser medido
long int soma = 10+ 20;// complexidade  1 - O(1) notação BIg O(1) notação Big O.

// usar laços para medir o tempo gasto em operações mais complexas

tempo_inicial = clock();

for (long int i = 0; i < 1000000000L; i++) {
   for(long int j = 0; j < 1000L; j++){
        soma += soma; //Complexidade O(n^2) notação Big O.
    }
    soma += i; //Compexidade  O(n) notação Big O.
}
// desligou o cronometro 
clock_t tempo_final = clock();

double tempo_gasto = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
printf("Tempo gasto: %.5lf segundos\n", tempo_gasto);

tempo_inicial = clock();

for (long int i = 0; i < 1000000000L  ; i++) {
    long int soma = soma + i; // O(n) notação Big O.
}
tempo_final = clock();
tempo_gasto = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
printf("Tempo gasto: %.5lf segundos\n", tempo_gasto);   
    return 0;
}
    