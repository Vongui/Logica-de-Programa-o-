#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que leia o ano de nascimento de uma pessoa. Calcular e apresentar a
idade desta pessoa e a quantidade de dias, de horas, de minutos e a quantidade de segundos
que esta pessoa vive desde o seu nascimento.*/

int main()
{
    int anoAtual,nascimento, idade, minutos, segundos, horas, dias;

    printf("\nDigite o ano atual: ");
    scanf("%d", &anoAtual);
    printf("\nDigite o ano do seu anscimento: ");
    scanf("%d", &nascimento);
    
    idade = anoAtual - nascimento;
    dias = idade * 365;
    horas = dias * 60;
    minutos = horas * 60;
    segundos = minutos * 60;

    printf("\nVoce vive a %d dias %d horas %d minutos e %d segundos\n", dias, horas, minutos, segundos);

    system("pause");
    return 0;
}