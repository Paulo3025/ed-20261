#include <stdio.h>

// pensar as variáveis , peso, altura e imc.
// peso e altura <= 0 , escrever 0 .
// calcular imc
// testar o valor do imc


int main( ){ 

float peso = 0;
float altura = 0;

printf( "Qual o seu peso : \n");
scanf("%.2f",&peso);

printf("Qual a sua altura : \n");
scanf("%.2f",&altura);

float imc ;

imc = peso / (peso*peso);

if ( imc < 18.5f){
    printf("Peso abaixo do rcomendo\n");
}
else if (18.5 <= imc <= 24.9){
    printf("Peso normal)\n");
}
else if (25.0 <= imc <= 29.9 ){
    printf("Sobrepeso\n");
}
else {
    (imc > 30.0f);
    printf("Obsidade");
}

    return 0;
}
