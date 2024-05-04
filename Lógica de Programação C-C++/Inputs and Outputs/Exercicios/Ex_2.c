#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que calcule e apresente o valor do volume de uma lata de óleo (a lata
tem o formato de um cilindro), utilizando a fórmula: “volume = 3.14159 * raio² * altura”.
Obs.: O programa deve ler os valores das variáveis: raio e altura, armazenar o resultado do
cálculo na variável volume.*/

int main()
{
    double raio, altura, volume;

    printf("\nDigite o valor do raio: ");
    scanf("%lf", &raio);
    printf("\nDigite o valor da altura: ");
    scanf("%lf", &altura);

    volume = 3.14159 * (raio*raio) * altura;

    printf("\nO volume desse cilindro eh: %.2lf\n", volume);

    system("pause");
    return 0;
}