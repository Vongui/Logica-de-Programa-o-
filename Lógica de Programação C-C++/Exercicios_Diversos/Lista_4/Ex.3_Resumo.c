#include <stdio.h>
#include <stdlib.h>

/*Faça um programa em linguagem C capaz de ler N números inteiros (negativos e positivos) e seja capaz
de apresentar um resumo contendo a quantidade de números positivos, negativos e zeros digitados pelo
usuário.*/

int main()
{
    int i, numero, N, qtdPositivos, qtdNegativos, qtdZeros;
    qtdPositivos = qtdNegativos = qtdZeros = 0;

    printf("Digite a quantidade numeros que seram digitados: ");
    scanf("%d", &N);
    for ( i = 0; i < N; i++)
    {
        printf("Digite o numero: ");
        scanf("%d", &numero);
        if (numero > 0)
        {
            qtdPositivos += 1;
        }
        else if (numero < 0)
        {
            qtdNegativos += 1;
        }
        else
        {
            qtdZeros += 1;
        }
    }

    printf("\nQuantidade de numeros positivos: %d", qtdPositivos);
    printf("\nQuantidade de numeros negativos: %d", qtdNegativos);
    printf("\nQuantidade de zeros: %d\n", qtdZeros);

    system("pause");
    return 0;
}