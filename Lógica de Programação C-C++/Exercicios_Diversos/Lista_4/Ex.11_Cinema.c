#include <stdio.h>
#include <stdlib.h>
#define VALOR_ENTRADA 18.00 //Valor do enuciado
/*Fazer um programa que gerencie uma sessão de cinema, onde o valor da entrada é de R$18,00 e pessoas
com idade inferior a 12 anos e superior a 59 anos pagam meia entrada. No final da sessão o proprietário
gostaria de saber:
a) A quantidade de entradas integrais vendidas;
b) A quantidade de meias entradas vendidas;
c) A quantidade de crianças que assistiram essa sessão;
d) A quantidade de idosos que assistiram a sessão;
e) O total arrecadado com a sessão.*/
int main() {
    int num_Inteiras = 0;
    int num_Meias = 0;
    int num_Criancas = 0;
    int num_Idosos = 0;
    int num_Pessoas;
    float total_arrecadado;
    int idade;

    printf("Digite o numero total de pessoas na sessao: ");
    scanf("%d", &num_Pessoas);

    for (int i = 0; i < num_Pessoas; i++) {

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idade);

        if (idade < 12 || idade > 59) {
            num_Meias++;
            if (idade < 12) {
                num_Criancas++;
            } else {
                num_Idosos++;
            }
        } else {
            num_Inteiras++;
        }
    }

    total_arrecadado = num_Inteiras * VALOR_ENTRADA + num_Meias * (VALOR_ENTRADA / 2);

    printf("\nQuantidade de entradas inteiras vendidas: %d\n", num_Inteiras);
    printf("Quantidade de meias entradas vendidas: %d\n", num_Meias);
    printf("Quantidade de crianças que assistiram a sessao: %d\n", num_Criancas);
    printf("Quantidade de idosos que assistiram a sessao: %d\n", num_Idosos);
    printf("Total arrecadado com a sessao: R$ %.2f\n", total_arrecadado);

    system("pause");
    return 0;
}
