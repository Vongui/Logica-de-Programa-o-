#include <stdio.h>  
#include <stdlib.h>
/*Escreva um programa que leia o nome as cinco notas escolares de um aluno. Calcule a média
do aluno e armazene em uma variável, depois apresente o nome do aluno e a sua média.
5. Escreva um programa que leia e armazene a receita e a despesa anual de uma empresa.*/

int main()
{
    float notas[5], media = 0;
    int i;
    char nome[50];

    for ( i = 1; i <= 5; i++)
    {
        printf("Digite a nota %d: ", i);
        scanf("%f", &notas[i]);
        media += notas[i];
    }
    media = media / 5;
    printf("%.2f", media);
    
}