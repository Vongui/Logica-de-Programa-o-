#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que calcule e imprima o salário reajustado de um funcionário de acordo com a
seguinte regra:
• salários até 2.500,00, reajuste de 15%
• salários maiores que 2.500,00, reajuste de 10%
*/
int main()
{
    float Salario, SalarioFinal;

    printf("\nDigite o valor so Salario do funcionario: ");
    scanf("%f", &Salario);
    if (Salario<=2500)
    {
        SalarioFinal = Salario*1.15;
        printf("\nValor do salario reajustado.......: R$%.2f\n", SalarioFinal);
    }
    else
    {
        SalarioFinal = Salario*1.10;
        printf("\nValor do salario reajustado.......: R$%.2f\n", SalarioFinal);   
    }
    
    system("pause");
    return 0;
}