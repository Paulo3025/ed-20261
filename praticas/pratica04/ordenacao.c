#include "ordenacao.h"

/* ===================== BUBBLE SORT ===================== */
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ===================== SELECTION SORT ===================== */
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/* ===================== QUICK SORT ===================== */

/* Função auxiliar: particionamento */
int partition(int arr[], int inicio, int fim) {
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

/* Quick Sort principal */
void quick_sort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int p = partition(arr, inicio, fim);

        quick_sort(arr, inicio, p - 1);  // esquerda
        quick_sort(arr, p + 1, fim);    // direita
    }
}