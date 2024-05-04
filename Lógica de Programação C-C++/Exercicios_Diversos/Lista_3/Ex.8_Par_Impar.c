#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba um número, verifique se este número é par ou ímpar e imprima a
mensagem.*/
int main()
{
    int num;

    printf("Digite o numero: ");
    scanf("%d", &num);
    if (num % 2 ==0)
    {
        printf("\nO numero %d eh par\n", num);
    }
    else
    {
        printf("\nO numero %d eh impar\n", num);
    }
    
    system("pause");
    return 0;
}