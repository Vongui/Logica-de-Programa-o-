#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, soma;
    numero = soma = 0; //iniciar duas variaveis de mesmo tipo; 

    // while-> Laço com quantidade de repetição indeterminada
    while(numero != -1)
    {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero != -1)
        {       
            soma = soma + numero;
        }
    }
    printf("Somatorio: %d\n", soma);
    
}