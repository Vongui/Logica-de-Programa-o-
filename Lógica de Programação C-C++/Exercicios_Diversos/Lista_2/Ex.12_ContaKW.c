/*Ao ser fornecido a quantidade de kw de uma residência e o valor do salário mínimo, calcule e imprima
o valor em reais de cada kw, o valor em reais devido pelo consumidor, e o valor a ser pago por essa
residência com um desconto de 10%. Sabe-se que 100 kilowatts custa 1/7 do salário mínimo.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salarioMinimo, precoKw, ValorTotal, Desconto, Consumo;

    printf("\nDigite o valor do salario minimo: ");
    scanf("%f", &salarioMinimo);
    precoKw = (salarioMinimo/7)/100;

    printf("\nDigite o consumo total de Kw: ");
    scanf("%f", &Consumo);
    ValorTotal = Consumo*precoKw;

    printf("\nValor de cada Kw: R$%0.2f", precoKw);
    printf("\nO valor a ser pago e: R$%0.2f", ValorTotal);
    Desconto= ValorTotal-(ValorTotal*0.1);
    printf("\nValor Total com desconto de 10%%: R$%0.2f\n", Desconto);

    system("pause");
}