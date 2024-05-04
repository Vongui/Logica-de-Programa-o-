/*Desenvolva um algoritmo para calcular e apresentar o novo saldo de uma conta, sabendo que foi feito
um depósito inicial e sobre esse valor é aplicado um determinado percentual de remuneração mensal.
Considerando que o valor ficou aplicado durante uma determinada quantidade de meses, apresente o
valor da conta ao final do período e o valor ganho com essa aplicação. Para o cálculo do valor final da
aplicação utilizamos a seguinte fórmula:
ValorFinal = ValorInicial*(1+(TaxaJuros/100))*QuantidadeMeses*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ValorInicial, Juros, ValorFinal, Lucro;
    int QtdMeses;

    printf("\nDigite o Valor inicial da aplicacao: ");
    scanf("%f", &ValorInicial);

    printf("\nDigite quantos meses o valor ficou sendo investido: ");
    scanf("%d", &QtdMeses);

    printf("\nDigite a taxa de juros em porcentagem: ");
    scanf("%f", &Juros);

    ValorFinal = ValorInicial*(1+(Juros/100))*QtdMeses;
    Lucro = ValorFinal-ValorInicial;

    printf("\nO Valor Total da aplicacao: R$%0.2f", ValorFinal);
    printf("\nLucro gerado: R$%0.2f\n", Lucro);

    system("pause");
}
