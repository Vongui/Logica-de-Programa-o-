#include <stdio.h>
#include <stdlib.h>
/*Fazer um programa em linguagem C capaz de ler 20 números reais, calcule e apresente:
a) Menor valor digitado;
b) Maior valor digitado;
c) Soma dos valores digitados;
d) Valor médio.*/

int main()
{
    int i;
    float num[19], soma, media, maior = 0, menor = 0;

    printf("Digite os 20 numeros desejados\n");
    for ( i = 0; i < 20; i++)
    {
        printf("Digite o numero: ");
        scanf("%f", &num[i]);
        soma += num[i];
    }
    menor = maior = num[0];
    for ( i = 0; i < 20; i++)
    {
        if (num[i] < menor)
        {
            menor = num[i];
        }
        else if (num[i] > maior)
        {
            maior = num[i];
        } 
    }
    
    media = soma/20;

    printf("Maior valor digitado: %.2f\n", maior);
    printf("Menor valor digitado: %.2f\n", menor);
    printf("Soma dos valores digitados: %.2f\n", soma);
    printf("Valor medio: %.2f\n", media);

    system("pause");
    return 0;
}