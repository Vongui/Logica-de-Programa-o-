#include <stdio.h>
#include <stdlib.h>
/*Uma empresa decide dar um aumento de 25% aos funcionários cujo salário é inferior a 1.800,00 reais.
Escreva um algoritmo que receba o salário de um funcionário e imprima o valor do salário reajustado ou
uma mensagem caso o funcionário não tenha direito ao aumento.
*/
int main()
{
    float Salario, SalarioFinal;

    printf("\nDigite o valor do salario do funcionario: ");
    scanf("%f", &Salario);
    if (Salario<1800)
    {
        SalarioFinal = Salario*1.25;
        printf("\nValor do salario reajustado........: R$%.2f\n", SalarioFinal);
    }
    else
    {
        printf("\nInfelizmente voce nao tem o direito ao reajuste salarial!!\n");
    }
    
    system("pause");
    return 0;
}