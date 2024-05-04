#include <stdio.h>
#include <stdlib.h>
/*Ler o nome do aluno, as 3 notas e calcular a média*/
int main()
{
    char nome[40];
    float n1, n2, n3, media;

    printf("\nDigite o nome do aluno: ");
    gets(nome);
    fflush(stdin);

    printf("\nDigite a primeira nota: ");
    scanf("%f", &n1);

    printf("\nDigite a segunda nota: ");
    scanf("%f", &n2);

    printf("\nDigite a terceira nota: ");
    scanf("%f", &n3);

    media = (n1+n2+n3)/3;

    printf("\nA media do aluno - %s --> %0.2f\n", nome, media);

    system("pause");
    return 0;
}