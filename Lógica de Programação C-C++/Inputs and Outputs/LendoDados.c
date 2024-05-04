#include <stdio.h>
#include <stdlib.h>
//int -> valor inteiro; float -> valor real; double -> valor Real +preciso; char -> caracter
//%i -> scanf int; %f -> scanf float; %d -> scanf double; %c -> scanf char
//printf("") -> imprimi na tela; scanf() -> lê o teclado, e armazena nas variaveis

int main()
{
    int n1, n2, resultado; //Declaração de variavéis

    printf("Digite o priemrio valor: ");
    scanf("%d", &n1);//Saída de Dados
    
    printf("Digite o segundo valor: ");
    scanf("%d", &n2);

    resultado = n1+n2;//Processamento

    printf("A soma desses valores e: %d\n", resultado);//Saída de Dados

    system("pause");//Congela a tela
    return 0;
}