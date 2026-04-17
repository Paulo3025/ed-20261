
#include "selecao.h"

int busca_sequencial( int v[], int n , int valor){
    for(int i = 0 ; i<n; i++){
        if(v[i]== valor){
            return i;

        }
    }
return -1;
}

/* Função auxiliar: particionamento */
int partition(int arr[], int inicio, int fim, int valor ) {
    int pivo = arr[fim];   // escolhe o último elemento como pivô
    int i = inicio - 1;
    int j, temp;

    for (j = inicio; j < fim; j++) {
        if (arr[j] < pivo) {
            i++;


            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;

    return i + 1;
}

/* Quick Select principal */
void quick_select(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int p = partition(arr, inicio, fim);

        quick_select(arr, inicio, p - 1);  // esquerda
        quick_select(arr, p + 1, fim);    // direita
    }
}