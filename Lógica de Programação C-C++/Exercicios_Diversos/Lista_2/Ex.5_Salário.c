/*Um vendedor recebe um salário fixo mais 5% de comissão sobre o total de suas vendas. Faça um
algoritmo que receba o salário fixo do vendedor e o valor de suas vendas. Em seguida, calcule e
apresente a comissão e seu salário final.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Salario_Fixo, Salario_Final, Vendas, Comissao, Valor_Comissao;

    printf("Digite o valor do seu salario: ");
    scanf("%f", &Salario_Fixo);

    printf("Digite a quantidade de vendas realizadas: ");
    scanf("%f", &Vendas);

    Comissao = 0.05;
    Valor_Comissao = Comissao*Vendas;
    Salario_Final = Salario_Fixo + Valor_Comissao;

    printf("O valor da Comissao recebida e de: R$%0.2f \nSalario Final sera de: R$%0.2f\n", Valor_Comissao, Salario_Final);

    system("pause");
    return 0;
}