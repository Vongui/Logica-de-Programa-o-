#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, resultado;
    int i; // geralmente se utiliza essa variavel para o incremento de For

    // For-> repete a estrutura em um numero pré-determinado de vezes
    for (i = 0; i < 5; i++)//declara o valor inicial da variável; a expressão desejada ; incremento - 1++ = 'i=i+1'
    {
        printf("Digite um numero: ");
        scanf("%d", &numero);
        resultado = numero * 3;
        printf("Resultado = %d\n", resultado);
    }
    
    system("pause");
    return 0;
}