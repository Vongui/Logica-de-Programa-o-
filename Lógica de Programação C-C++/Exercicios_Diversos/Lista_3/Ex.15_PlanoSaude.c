#include <stdio.h>
#include <stdlib.h>
/*Depois da liberação do governo para as mensalidades dos planos de saúde, as pessoas começaram a
fazer pesquisas para descobrir um bom plano, não muito caro. Um vendedor de um plano de saúde
apresentou a tabela a seguir. Criar um programa que entre com a idade de uma pessoa e imprima o
valor que ela deverá pagar, segundo a seguinte tabela:
Idade Valor
Até 18 anos R$ 180,00
Acima de 18 até 30 anos R$ 240,00
Acima de 30 até 45 anos R$ 300,00
Acima de 45 até 59 anos R$ 340,00
Acima de 59 até 65 anos R$ 400,00
maior que 65 anos R$ 610,00*/
int main()
{
    int Idade; 

    printf("Digite a sua idade: ");
    scanf("%d", &Idade);
    if (Idade<=18)
    {
        printf("\nValor a pagar....: R$180.00\n");
    }
    else if (Idade >18 && Idade <=30)
    {
        printf("\nValor a pagar....: R$240.00\n");
    }
    else if (Idade >30 && Idade<=45)
    {
        printf("\nValor a pagar....: R$300.00\n");
    }
    else if (Idade >45 && Idade <=59)
    {
        printf("\nValor a pagar....: R$340.00\n");
    }
    else if (Idade >59 && Idade <=65)
    {
        printf("\nValor a pagar....: R$400.00\n");
    }
    else
    {
        printf("\nValor a pagar....: R$610.00\n");
    }
    
    system("pause");
    return 0;
}