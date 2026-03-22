#include <stdio.h>

int main (){

    float peso,altura, imc;
    // Solicitar ao usuário a Massa corpórea  e a estatura do usuário.
    printf("Digite o seu 'PESO' em kg: ");
    scanf("%f", &peso);
    printf("Digite a sua 'ALTURA' em metros: ");
    scanf("%f", &altura);
    // Calcular o IMC do USUÁRIO usando a fórmula IMC = peso / (altura * altura).
    imc = peso / (altura*altura);
    printf(" \n###########   CLASSIFICACAO DO IMC : ###########\n");
    printf("\n1 - ABAIXO DO PESO - MENSOR QUE 18,5");
    printf("\n2 - PESO NORMAL - ENTRE 18,5 E 24,9");
    printf("\n3 - SOBREPESO - ENTRE 25 E 29,9");
    printf("\n4 - OBESIDADE - MAIOR QUE 30 \n");
  
    // Exibir o resultado do IMC para o usuário.
    printf("\nO SEU IMC e : %.2f\n", imc);
    printf("\nA SUA CLASSIFICACAO E : ");
    if (imc < 18.5){
        printf("\nABAIXO DO PESO\n\n");
    }
    else if (imc >= 18.5 && imc <= 24.9){
        printf("\nPESO NORMAL\n\n");
    }
    else if (imc >= 25 && imc <= 29.9){
        printf("SOBREPESO\n\n");
    }else{ 
        printf("\nOBESIDADE\n\n");

    
    return 0;

}
}