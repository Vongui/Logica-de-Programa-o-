#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10];
    int i, valor, contador = 0;

    for (i = 0; i < 10; i++)
    {
        do
        {
            printf("\nDigite um numero positivo (0 > ) para a posicao %d: ", i+1);
            scanf("%d", &valor);
        } while (valor < 0);
        vetor[i] = valor;
    }

    for ( i = 9; i > 0; i--)
    {
        vetor[i] = vetor[i-1];
    }
    vetor[0] = 0;
    
    for (i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    printf("\nDigite um valor para a verificacao de ocorrencia: ");
    scanf("%d", &valor);
    for (i = 0; i < 10; i++)
    {
        if (vetor[i] == valor)
        {
            contador++;
        }
    }
    printf("\nQuantidade de ocorrencia do vetor eh igual a %d ", contador);

    system("pause");
    return 0;
}