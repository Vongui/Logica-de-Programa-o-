#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, somaPos, somaNeg, contNeg, media;

    numero = 7;
    somaPos = somaNeg = contNeg = 0;

    while (numero != 0)
    {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero >= 0)
        {
            somaPos = somaPos + numero;
        }
        else
        {
            somaNeg = somaNeg + numero;
            contNeg++;
        } 
    }
    media =  somaNeg / contNeg;
    printf("Soma dos positivos: %d\n", somaPos);
    printf("Media negativos: %d\n", media);
}