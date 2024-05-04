#include <stdio.h>
#include <stdlib.h>
/*Na Festa das Nações em Presidente Epitácio será realizado o controle do caixa, onde cada pessoa pode
comprar várias fichas de R$ 5,00 e R$2,00. Considerando que não sabemos quantas pessoas virão
comprar fichas e nem a quantidade de fichas serão compradas pelas pessoas. Faça um programa em
linguagem C capaz de imprimir a quantidade de pessoas que compraram fichas, a quantidade de fichas
de R$ 2,00 compradas, a quantidade de fichas de R$ 5,00 e o valor total arrecadado no caixa.*/
int main()
{
    float valor_Arrecadado = 0.0, valor_Pessoa=0.0;
    int i, fichas, qtd_Ficha2 = 0, qtd_Ficha5 = 0, qtd_Pessoas = 0;
    char escolha;
    int ficha_valor;

    do
    {
        printf("Digite a quantidade de fichas compradas: ");
        scanf("%d", &fichas);
        if (fichas > 0)
        {
            for ( i = 0; i < fichas; i++)
            {
                printf("\nDigite o valor da ficha(somente 5 ou 2): ");
                scanf("%d", &ficha_valor);
                if (ficha_valor == 2)
                {
                    qtd_Ficha2++;
                    valor_Pessoa += 2;
                }
                else if (ficha_valor == 5)
                {
                    qtd_Ficha5++; 
                    valor_Pessoa += 5;                  
                }
                else
                {
                    printf("\nValor invalido!!!!!. Valor desconsiderado!\n");
                }
            }
            qtd_Pessoas++;

        }
        else
        {
            printf("Numero de fichas incorreto!!!\n");
        }

        printf("Deseja continuar a registras fichas? (S/N) ");
        fflush(stdin);
        scanf("%c", &escolha);
            
    } while (escolha == 'S' || escolha == 's');
    
    valor_Arrecadado = valor_Arrecadado + valor_Pessoa;
    printf("\nQuantidade de pessoas...: %d\n", qtd_Pessoas);
    printf("Quantidade de ficha de R$2,00 adquiridas: %d\n", qtd_Ficha2);
    printf("Quantidade de ficha de R$5,00 adquiridas: %d\n", qtd_Ficha5);
    printf("Valor total arrecadado..: R$ %.2f\n", valor_Arrecadado);

    system("pause");
    return 0;
}