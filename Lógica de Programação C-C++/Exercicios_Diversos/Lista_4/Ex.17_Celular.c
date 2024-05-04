#include <stdio.h>
#include <stdlib.h>
/*Faça um programa em linguagem C que solicita o valor do celular que a Maria gostaria de comprar e o
valor que ela já possui, sendo que o valor do celular deve ser maior que ela possui, e seja capaz de receber
um conjunto de atividades que ela fez até conseguir o seu objetivo, considerando que as opções são: J –
quando ajuda o João, C – ajuda a Cleusa, B – Bia e M – a sua mãe. Não deve ser permitido a digitação de
valores diferentes a esses. Ao final das tarefas realizadas pela Maria deve-se apresentar:
a) Quantidade de tarefas realizadas;
b) Quantidade de horas trabalhadas;
c) Valor total arrecadado com a execução das tarefas;
d) Valor que sobrou para a Maria após a compra do celular, considerando que na hora da compra ela
conseguiu 5% de desconto, por comprar à vista.*/
int main() {
    float valor_Celular = 0.0, valor_Possui = 0.0;
    int qtd_tarefas = 0;
    int qtd_horas = 0;
    float valor_Arrecadado = 0.0;
    float Sobrou = 0.0, desconto;
    char escolha;

    printf("Digite o valor do celular que Maria deseja comprar: R$ ");
    scanf("%f", &valor_Celular);

    printf("Digite o valor que Maria já possui: R$ ");
    scanf("%f", &valor_Possui);

    while (valor_Possui < valor_Celular) {
        printf("\n=== Atividades ===\n");
        printf("J - Ajudar o tio João \n");
        printf("C - Ajudar a Dona Cleusa \n");
        printf("B - Ajudar a Bia da quitanda \n");
        printf("M - Ajudar a sua mãe \n");
        printf("Digite a atividade que Maria realizou: ");
        fflush(stdin);
        scanf("%c", &escolha);

        switch (escolha) {
            case 'J':
            case 'j':
                qtd_tarefas++;
                qtd_horas += 5;
                valor_Arrecadado += 50.0;
                valor_Possui += 50.0;
                break;
            case 'C':
            case 'c':
                qtd_tarefas++;
                qtd_horas += 12;
                valor_Arrecadado += 120.0;
                valor_Possui += 120.0;
                break;
            case 'B':
            case 'b':
                qtd_tarefas++;
                qtd_horas += 4;
                valor_Arrecadado += 60.0;
                valor_Possui += 60.0;
                break;
            case 'M':
            case 'm':
                qtd_tarefas++;
                qtd_horas += 3;
                valor_Arrecadado += 50.0;
                valor_Possui += 50.0;
                break;
            default:
                printf("Digite uma opcao valida. Tente novamente.\n");
                break;
        }

    }
    desconto = valor_Celular * 0.05;
    valor_Celular -= desconto;
    Sobrou = valor_Possui - valor_Celular;

    printf("\n=== Resultados ===\n");
    printf("Quantidade de tarefas realizadas: %d\n", qtd_tarefas);
    printf("Quantidade de horas trabalhadas: %d\n", qtd_horas);
    printf("Valor total arrecadado com as tarefas: R$ %.2f\n", valor_Arrecadado);
    printf("Valor que sobrou após a compra do celular: R$ %.2f\n", Sobrou);

    system("pause");
    return 0;
}