#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura, peso, IMC;

    printf("Vamos calcular o seu IMC?, siga as intrucoes abaixo\n ");
    printf("Qual a sua altura:(em metros) ");
    scanf("%f", &altura);

    printf("\nQual o seu peso:(em kg) ");
    scanf("%f", &peso);

    IMC = peso/(altura*altura); //cálculo exclusivo de IMC

    printf("\nO calculo do seu IMC e de: %0.2f\n", IMC);

    system("pause"); //pausa o .exe
    return 0;
}