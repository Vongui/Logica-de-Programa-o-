#include <stdio.h>
#include <stdlib.h>
/*Faça um programa em linguagem C capaz de ler uma frase (vetor de caracter) de até 50 posições e seja
capaz de calcular a quantidade de palavras existentes na frase, a quantidade de vogais. O programa deve
também apresentar os números existentes no texto.*/
int main()
{
    char vetor[50], caracter;
    int qtdPalavras = 1, qtdVogais = 0, num = 0;
    int tl = 0, i;

    printf("\nDigite uma frase (no maximo de 50 caracteres): ");
    do
    {
        scanf("%c", &caracter);
        vetor[tl] = caracter;
        tl++;
    } while (caracter != 10 && tl < 50);

    for (i = 0; i < tl; i++)
    {
        if (vetor[i] == ' ' && vetor[i + 1] != ' ' && vetor[i + 1] != '\0')
        {
            qtdPalavras++;
        }
        else if (vetor[i] == 'a' || vetor[i] == 'e' || vetor[i] == 'i' || vetor[i] == 'o' || vetor[i] == 'u' ||
                 vetor[i] == 'A' || vetor[i] == 'E' || vetor[i] == 'I' || vetor[i] == 'O' || vetor[i] == 'U')
        {
            qtdVogais++;
        }
        else if(vetor[i] >= '0' && vetor[i] <= '9') 
        {
            num++;
        }
    }

    printf("\nQuantidade de palavras: %d ", qtdPalavras);
    printf("\nQuantidade de vogais: %d ", qtdVogais);
    printf("\nQuantidade de numeros: %d \n", num);
    system("pause");
    return 0;
}