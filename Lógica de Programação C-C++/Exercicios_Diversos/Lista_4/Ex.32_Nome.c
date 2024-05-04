#include <stdio.h>
#include <stdlib.h>
/*Fazer um programa em linguagem C capaz de ler um nome por extenso com no máximo 30 caracteres e
seja capaz de:
a) Apresentar a quantidade de palavras no nome;
b) A quantidade de letras, 'sem contar espaços em branco;
c) Apresentar apenas o primeiro nome*/
int main()
{
    char nome[30], caracter;
    int i, contador = 1, tl=0, qtdLetras = 0;

    printf("Digite o seu nome completo: (máximo de 30 caracteres) ");
    do {
        scanf("%c", &caracter);
        nome[tl] = caracter;
        tl++;
        } while( caracter != 10 &&  tl < 30);

    printf("Primeiro Nome: ");
    for ( i = 0; i < tl; i++)
    {
        if (nome[i] == ' ' && nome[i+1] != ' ' && nome[i+1] != '\0')
        {
            contador++;
        }
        if (nome[i] != ' ' && nome[i] != 10)
        {
            qtdLetras++;
        }
    }
    i = 0;
    do
    {
        printf("%c", nome[i]);
        i++;
    } while (nome[i] != ' ' && i < tl);
    
    printf("\nQuantidade de palavras: %d", contador);
    printf("\nQuantidade de Letras: %d\n", qtdLetras);

    system("pause");
    return 0;
}