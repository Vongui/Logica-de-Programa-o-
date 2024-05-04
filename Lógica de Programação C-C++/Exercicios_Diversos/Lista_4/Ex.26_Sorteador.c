#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Informe dois números ao computador variando de 1 a 75, após os números serem fornecidos
computador deve começar a gerar números aleatórios e parar quando ele conseguir acertar os dois
números que você escolheu. Informe quantos sorteios foram necessários para que ele acertasse sua
escolha e quais foram os números que ele sorteou.*/
int main()
{
    int num1_usuario, num2_usuario;
    int contador = 0, sorteador, sorteador2;

    srand(time(NULL));
    
    printf("Digite o primerio numero: (de 1 a 75) ");
    scanf("%d", &num1_usuario);
    while (num1_usuario < 1 || num1_usuario > 75) {
        printf("Número inválido. Digite novamente: ");
        scanf("%d", &num1_usuario);
    }
    printf("Digite o segundo numero: (de 1 a 75) ");
    scanf("%d", &num2_usuario);
    while (num2_usuario < 1 || num2_usuario > 75) {
        printf("Número inválido. Digite novamente: ");
        scanf("%d", &num2_usuario);
    }
    do
    {
        sorteador = rand() %75+ 1;
        sorteador2 = rand() %75 + 1;
        contador++;
        printf("Numero do sorteio %d: %d %d\n", contador, sorteador, sorteador2);

    } while ((sorteador != num1_usuario || sorteador2 != num2_usuario) && (sorteador != num2_usuario || sorteador2 != num1_usuario));

    printf("O Computador finalmente acertou os numeros em %d tentativas!!!\n", contador);

    system("pause");
    return 0;
}