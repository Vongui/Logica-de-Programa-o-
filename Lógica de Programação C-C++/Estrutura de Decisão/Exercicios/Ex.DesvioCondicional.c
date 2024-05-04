#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[70];
    float n1, n2, media;

    printf("\nDigite o nome do aluno completo: ");
    gets(nome);

    printf("\nDigite a primeira nota: ");
    fflush(stdin);
    scanf("%f", &n1);

    printf("\nDigite a segunda nota: ");
    scanf("%f", &n2);
    
    media = (n1+n2)/2;
    if(media>=6)
    {
        printf("\nAluno: %s ------> %0.2f \nSituacao -------> Aprovado\n", nome, media);
    }
    else
    {
        printf("\nAluno: %s ------> %0.2f \nSituacao -------> Reprovado\n", nome, media);
    }

    system("pause");
    return 0;
}