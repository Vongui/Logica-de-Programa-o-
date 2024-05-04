#include <stdio.h>
#include <stdlib.h>
//Diferença do simples é que nesse possui o else; else = "senão"
int main()
{
    int num;

    printf("\ndigite um numro: ");
    scanf("%d", &num);

    if (num>=0)
    {
        printf("\no numero %d eh positivo ", num);//utiliza a expressão escrita no If e testa
    }   
    else
    {
        printf("\no numero %d eh negativo\n", num);//Testa primeiro em cima e dps testa no else
    }
    
    system("\npause");
    return 0;
}