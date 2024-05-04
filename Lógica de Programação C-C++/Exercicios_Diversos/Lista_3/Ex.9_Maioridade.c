#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba a idade de uma pessoa e imprima mensagem de maioridade ou não.*/
int main()
{
    int Idade;

    printf("\nDigite a sua idade: ");
    scanf("%d", &Idade);
    if (Idade >=18)
    {
        printf("\nParabens!! voce chegou a maioridade!!\n");
    }
    else
    {
        printf("\nInfelizmente voce ainda nao chegou a maioridade\n");
    }

    system("pause");
    return 0;
}