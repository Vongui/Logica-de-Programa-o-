#include <stdio.h>
#include <stdlib.h>
/*Uma empresa decidiu dar uma gratificação de Natal aos seus funcionários, baseada no número de horas
extras e no número de horas que o funcionário faltou ao trabalho. O valor do prêmio é obtido pela
consulta na tabela a seguir, em que:
H = (Número de horas extras) - (2/3 * (Números de horas-falta))
H em minutos Premio em R$
> 2400 500,00
1801 até 2400 400,00
1201 até 1800 300,00
600 até 1200 200,00
Menor que 600 100,00
Faça um algoritmo que receba o número de horas extras e o número de horas-falta em minutos de um
funcionário. Imprima o número de horas extras em horas, o número de horas-falta em horas e o valor
do prêmio.*/
int main()
{
    float Premio, H, HorasExtras, HorasFaltas;
    int Extras, Faltas;
    //Leitura das horas em minutos
    printf("\nDigite o numero de horas extras(em minutos): ");
    scanf("%d", &Extras);
    printf("\nDigite o numero de horas-faltas(em minutos): ");
    scanf("%d", &Faltas);

    HorasExtras = Extras/60;
    HorasFaltas = Faltas/60;

    //Calculo do valor de H
    H = Extras - (2.0 / 3.0 * Faltas);
    if (H < 600)//Tabela de prêmio
    {
        Premio = 100;
        printf("Horas Extras ....: %.2f Horas\nHoras-Falta......: %.2f Horas\nPremio...........: R$%0.2f\n", HorasExtras, HorasFaltas, Premio);
    }
    else if (H >= 600 && H <= 1200)
    {
        Premio = 200;
        printf("Horas Extras ....: %.2f Horas\nHoras-Falta......: %.2f Horas\nPremio...........: R$%0.2f\n", HorasExtras, HorasFaltas, Premio);
    }
    else if (H > 1200 && H <= 1800)
    {
        Premio = 300;
        printf("Horas Extras ....: %.2f Horas\nHoras-Falta......: %.2f Horas\nPremio...........: R$%0.2f\n", HorasExtras, HorasFaltas, Premio);
    }
    else if (H > 1800 && H <= 2400)
    {
        Premio = 400;
        printf("Horas Extras ....: %.2f Horas\nHoras-Falta......: %.2f Horas\nPremio...........: R$%0.2f\n", HorasExtras, HorasFaltas, Premio);
    }
    else
    {
        Premio = 500;
        printf("Horas Extras ....: %.2f Horas\nHoras-Falta......: %.2f Horas\nPremio...........: R$%0.2f\n", HorasExtras, HorasFaltas, Premio);
    }

    system("pause");
    return 0;
}