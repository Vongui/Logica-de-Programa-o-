/*A galera da faculdade foi no Boteco do João pois souberam que no boteco há um desconto de 10% para
os alunos do curso de Bacharelado em Ciência da Computação, faça um algoritmo que a partir do total
da conta, calcula o valor a ser pago, com o desconto. E também o valor a ser pago individualmente pelos
integrantes da confraternização.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Participantes;
    float Desconto, Valor, ValorTotal, ValorPessoal;

    printf("\nQual o valor da conta?: ");
    scanf("%f", &Valor);

    printf("\nQuantos Integrantes na Confraternizacao: ");
    scanf("%d", &Participantes);

    Desconto = 0.1;
    ValorTotal = Valor-(Desconto*Valor);
    ValorPessoal = ValorTotal/Participantes;

    printf("\nValor da conta: R$%0.2f", Valor);
    printf("\nValor da conta com desconto aplicado: R$%0.2f", ValorTotal);
    printf("\nValor da conta divido entre os participantes: R$%0.2f\n", ValorPessoal);
    
    system("pause");
}