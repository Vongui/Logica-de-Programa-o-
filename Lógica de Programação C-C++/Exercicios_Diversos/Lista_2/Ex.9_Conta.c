#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Primeiro, Segundo, Terceiro, Total;

    printf("\nQual o valor total da conta?: \n");
    scanf("%f", &Total);
    //Operação para se separar o resto da divisão do valor inteiro
    Primeiro = (int)(Total / 3);
    Segundo = (int)(Total / 3);
    //o ultimo paga os centavos + o valor inteiro
    Terceiro = Total - (Primeiro+Segundo);

    printf("\nPrimeira Parte: R$%0.2f", Primeiro);
    printf("\nSegunda Parte: R$%0.2f", Segundo);
    printf("\nTerceira Parte: R$%0.2f\n", Terceiro);

    system("pause");
}
