#include <stdio.h>
#include <stdlib.h>

/*A pousada Sono Tranquilo calcula o valor total da hospedagem de pessoas em seus apartamentos pela
quantidade de di�rias e o total dos outros gastos, como refei��es e bebidas. O valor do apartamento �
fixo e definido pelo propriet�rio. No fechamento da conta, o funcion�rio pode definir um percentual de
desconto para o cliente. Fa�a um algoritmo capaz de calcular o valor total da hospedagem, o valor do
desconto e o valor a ser pago pelo cliente.
*/

int main()
{
    int QtdDiarias;
    float Bebidas, Comidas, Desconto, Total, TotalFinal;

    printf("\nVamos fechar a conta!! \nPrimeiro digite a quntidade de diarias: (Vale lembrar que o valor de cada diaria e R$120,00) ");
    scanf("%i", &QtdDiarias);

    printf("\nQuanto que foi Gasto com Bebidas: ");
    scanf("%f", &Bebidas);

    printf("\nQuanto foi o Valor gasto com Refeicoes: ");
    scanf("%f", &Comidas);
    //Funcionário pode digitar o valor do desconto em porcentagem
    printf("\nDigite o Valor do desconto (digitar em %%): ");
    scanf("%f", &Desconto);
    
    //Atribuições finais as variavéis
    Desconto = Desconto/100;
    Total = ((QtdDiarias*120)+Bebidas+Comidas);
    TotalFinal = Total-(Total*Desconto);

    printf("\nValor da fatura sem desconto: R$%0.2f \nValor do Desconto: R$%0.2f \nValor Total: R$%0.2f\n\n", Total, Desconto, TotalFinal);

    system("pause");
    return 0;
}
