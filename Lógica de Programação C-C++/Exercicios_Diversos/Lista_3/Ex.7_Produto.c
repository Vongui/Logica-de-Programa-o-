#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba o preço de um produto e o seu código de origem e imprima a sua
procedência. A procedência obedece a seguinte tabela:
Codigo de Origem Procedencia
1 a 5 Sul
6 ou 7 Norte
8, 9 ou 10 Centro-oeste
11 até 20 Sudeste
20 até 25 Nordeste*/
int main()
{
    int Codigo;
    float Preco;

    printf("Digite o Valor do produto: ");
    scanf("%f", &Preco);
    printf("Digite o codigo do produto(1-25): ");
    scanf("%d", &Codigo);

    if (Codigo > 1 && Codigo <=5)
    {
        printf("\nValor do produto -> %.2f e tem procedencia do Sul!\n", Preco);
    }
    else if (Codigo == 6 || Codigo == 7)
    {
        printf("\nValor do produto -> %.2f e tem procedencia do Norte!\n", Preco);
    }
    else if (Codigo >= 8 && Codigo <=10)
    {
        printf("\nValor do produto -> %.2f e tem procedencia do Centro-oeste!\n", Preco);
    }
    else if (Codigo >= 11 && Codigo <=20)
    {
        printf("\nValor do produto -> %.2f e tem procedencia do Sudeste!\n", Preco);
    }
    else if (Codigo >=20 && Codigo <=25)
    {
        printf("\nValor do produto -> %.2f e tem procedencia do Nordeste!\n", Preco);
    }
    else
    {
        printf("\nCodigo digitado invalido!!\n");
    }
    
    system("pause");
    return 0;
}