/*O pedreiro Jão da Pedra para calcular o custo de murar um terreno, ele utiliza o perímetro do terreno e
a altura do muro (quantidade de metros quadrados de muro). O valor do metro quadrado do muro pode
variar de acordo com o tipo de bloco utilizado. Faça um algoritmo capaz de calcular o preço total para
murar um terreno retangular, deve-se apresentar a quantidade de metros quadrados de muro a ser
construído.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Perimetro, Altura, Valor_Metro, Valor_Final, Metro_Quadrado;

    printf("\nDigite o perimetro do terreno: ");
    scanf("%f", &Perimetro);

    printf("\nQual a altura do muro desejado: ");
    scanf("%f", &Altura);

    printf("\nQual o valor do Metro quadrado: ");
    scanf("%f", &Valor_Metro);

    Valor_Final = (Perimetro*Altura*Valor_Metro);
    Metro_Quadrado = (Perimetro*Altura);

    printf("\nMedida do terreno a ser murado: %0.2fm2", Metro_Quadrado);
    printf("\nO valor para murar o terreno: R$%0.2f\n", Valor_Final);

    system("pause");
}