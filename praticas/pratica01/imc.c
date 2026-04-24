#include <stdio.h>

/* função fora da main: calcula IMC */
float calcular_imc(float peso, float altura)
{
    return peso / (altura * altura);
}

int main()
{
    float pesos[] = {60, 72, 86, 110, -70, 80};
    float alturas[] = {1.75, 1.75, 1.75, 1.75, 1.75, 0};
    int n = 6;

    printf("\n\nPeso   Altura   IMC     Classificacao        Valido(0/1)\n\n");
    printf("--------------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        float peso = pesos[i];
        float altura = alturas[i];
        float imc = 0;
        int valido;

        /* validação lógica */
        if(peso > 0 && altura > 0)
            valido = 1;
        else
            valido = 0;

        if(valido == 1)
        {
            imc = calcular_imc(peso, altura);

            printf("%5.1f   %5.2f   %5.2f   ", peso, altura, imc);

            if(imc < 18.5)
                printf("Abaixo do peso      ");
            else if(imc <= 24.9)
                printf("Peso normal         ");
            else if(imc <= 29.9)
                printf("Sobrepeso           ");
            else
                printf("Obesidade           ");

            printf("%d\n", valido);
        }
        else
        {
            printf("%5.1f   %5.2f   -----   Dados invalidos     %d\n", peso, altura, valido);
        }
    }

    return 0;
}