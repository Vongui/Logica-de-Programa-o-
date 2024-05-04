#include <stdio.h>
#include <stdlib.h>
/*. Faça um algoritmo que receba a altura e o sexo de uma pessoa, calcule e imprima o seu peso ideal,
utilizando as seguintes fórmulas:
• para homens: (72.7 * H) - 58
• para mulheres: (62.1 * H) - 44.7*/
int main() 
{
    float Altura, PesoIdeal;
    char Sexo;

    printf("Informe a altura (em metros): ");
    scanf("%f", &Altura);

    printf("Informe o sexo (M para masculino e F para feminino): ");
    fflush(stdin);
    scanf("%c", &Sexo);

    if (Sexo == 'M' || Sexo == 'm') 
    {
        PesoIdeal = (72.7 * Altura) - 58;
        printf("O peso ideal......: %.2f kg.\n", PesoIdeal);
    } 
    else if (Sexo == 'F' || Sexo == 'f') 
    {
        PesoIdeal = (62.1 * Altura) - 44.7;
        printf("O peso ideal......: %.2f kg.\n", PesoIdeal);
    } 
    else 
    {
        printf("Sexo invalido. Por favor, digite M para masculino ou F para feminino.\n");
    }

    system("pause");
    return 0;
}