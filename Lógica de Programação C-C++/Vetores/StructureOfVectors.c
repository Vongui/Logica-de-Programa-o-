#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaração de vetores -> Tipo de dado - variavel[tamanho];
    float notas[6];
    int i;

    // lendo dados do vetor -> obs: utiliza a função for
    for ( i = 0; i < 6; i++)
    {
        printf("Digite uma nota: ");
        scanf("%f", &notas[i]);
    }
    
    // Mostrando os dados do vetor - 
    for ( i = 0; i < 6; i++)
    {
        printf("Nota armazenada: %.2f\n", notas[i]);
    }
    
    return 0;
}