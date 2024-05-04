#include <stdio.h>
#include <stdlib.h>
#define TL 3

void main()
{
    int vetorA[TL], vetorB[TL], vetorC[TL];
    int i;

    printf("Digite o valores do primeiro vetor: ");
    for ( i = 0; i < TL; i++)
    {
        scanf("%d", &vetorA[i]);
    }

    printf("Digite os valores do segundo vetor: ");

    for ( i = 0; i < TL; i++)
    {
        scanf("%d", &vetorB[i]);
    }

    for ( i = 0; i < TL; i++)
    {
        vetorC[i] = vetorA[i] + vetorB[i];
    }

    for ( i = 0; i < TL; i++)
    {
        printf("%d + %d = %d\n", vetorA[i], vetorB[i], vetorC[i]);
        printf("Elemento %d do vetor A: %d\n", i+1, vetorA[i]);
        printf("Elemento %d do vetor B: %d\n", i+1, vetorB[i]);
        printf("Elemento %d do vetor C: %d\n", i+1, vetorC[i]);
    }
        
}