#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[50];
    float Salario, SalarioLiquido, Desconto, Taxa;

    printf("Digite o nome do funcionario: ");
    gets(nome);

    printf("Digite o salario bruto desse funcionario: ");
    fflush(stdin);
    scanf("%f", &Salario);

    if (Salario<=1000)
    {
        Taxa = 0.08;
        Desconto = Salario*Taxa;
        SalarioLiquido = Salario - Desconto;
        Taxa = Taxa*100;
        printf("\nNome: %s\nSalario Bruto: R$%.2f\nTaxa INSS: %.0f%%\nValor Desconto: R$%.2f\nSalario liquido: R$%.2f\n", nome, Salario, Taxa, Desconto, SalarioLiquido);
    }
    else if (Salario>2000) 
    {
        Taxa = 0.1;
        Desconto = Salario*Taxa;
        SalarioLiquido = Salario - Desconto;
        Taxa = Taxa*100;
        printf("\nNome: %s\nSalario Bruto: R$%.2f\nTaxa INSS: %.0f%%\nValor Desconto: R$%.2f\nSalario liquido: R$%.2f\n", nome, Salario, Taxa, Desconto, SalarioLiquido);
    }
    else
    {
       Taxa = 0.09;
        Desconto = Salario*Taxa;
        SalarioLiquido = Salario - Desconto;
        Taxa = Taxa*100;
        printf("\nNome: %s\nSalario Bruto: R$%.2f\nTaxa INSS: %.0f%%\nValor Desconto: R$%.2f\nSalario liquido: R$%.2f\n", nome, Salario, Taxa, Desconto, SalarioLiquido); 
    }
    
}