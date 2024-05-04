#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa em linguagem C capaz de simular uma conta corrente, onde será possível as
seguintes ações: (a) consultar saldo, (b) sacar um determinado valor, (c) fazer depósito e (d) sair. O saldo
deve iniciar em R$ 0,00. A cada saque ou depósito o valor do saldo deve ser atualizado. Lembrar que a
pessoa não pode sacar se não tiver saldo.*/
int main()
{
    float saldo = 0.0;
    float valor_saque, valor_deposito;
    int menu;

    do
    {
        printf("\n-------Menu-------\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Fazer saque\n");
        printf("3 - Fazer deposito\n");
        printf("4 - Sair\n");
        scanf("%d", &menu);

        switch (menu){
        case 1:
            printf("Seu Saldo: %.2f\n", saldo);
            break;
        case 2:
            if (saldo > 0)
            {
                printf("Qual valor desejado de saque: ");
                scanf("%f", &valor_saque);

                if (valor_saque <= saldo)
                {
                    saldo -= valor_saque;
                    printf("Operacao efetuada com sucesso!!!\n");
                    printf("Valor do saldo: %.2f", saldo);
                }
                else
                {
                    printf("Saldo insuficiente para o saque!!\n");
                }
            }
            else
            {
                printf("Saldo insuficiente para essa operacao!!!\n");
            }
            break;
        case 3:
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor_deposito);
            saldo += valor_deposito;
            printf("Valor do saldo: %.2f\n", saldo);
            printf("Deposito efetuado com succeso\n");
            break;
        case 4:
            printf("Fechando o programa....\n");
            break;
        default:
            printf("Digite uma opcao valida!!!!\n");
            break;
        }
    } while (menu != 4);

    system("pause");
    return 0;
}