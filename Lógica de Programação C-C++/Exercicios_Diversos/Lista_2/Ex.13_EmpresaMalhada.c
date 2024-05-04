/*Dona Conceição revende roupas para a Empresa Malhada. Sabe-se que sobre o preço de custo das
roupas, a Empresa Malhada coloca 50% de ganho e repassa para a Dona Conceição que irá revendê-las.
Dona Conceição, por sua vez, repassa para seus clientes com 35% de ganho. Faça um algoritmo que ao
ser fornecido o preço de custo de uma roupa, calcule:
- valor da venda pela Empresa Malhada;
- valor da venda pela Dona Conceição;
- lucro da empresa Malhada;
- lucro da Dona Conceição.
Todos os valores calculados deverão ser apresentados ao usuário.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float LucroEmpresa, LucroDona, VendaEmpresa, VendaDona, VendaUsario;
    float PrecoCusto;

    printf("\nDigite o preco de custo do produto em reais: ");
    scanf("%f", &PrecoCusto);

    VendaEmpresa= (PrecoCusto*0.5)+PrecoCusto;
    VendaDona= (VendaEmpresa*0.35)+VendaEmpresa;
    VendaUsario= VendaDona;

    LucroEmpresa= (PrecoCusto*0.5);
    LucroDona= (VendaEmpresa*0.35);

    printf("\nValor de venda Empresa Malhada: R$%0.2f", VendaEmpresa);
    printf("\nValor de venda Dona Conceicao: R$%0.2f", VendaDona);
    printf("\nValor do lucro Empresa Malhada: R$%0.2f", LucroEmpresa);
    printf("\nValor de lucro Dona Conceicao: R$%0.2f", LucroDona);
    printf("\nValor de venda ao consumidor final: R$%0.2f\n", VendaUsario);

    system("pause");
}