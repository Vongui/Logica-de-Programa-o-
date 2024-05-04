#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba três notas de um aluno, calcule e imprima a média aritmética entre essas
três notas e uma mensagem que segue a tabela abaixo:
Média Mensagem
Menor que 6 Reprovado
Maior ou igual a 6 Aprovado*/
int main()
{
    float n1, n2, n3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = (n1+n2+n3)/3;
    if (media >=6)
    {
        printf("\nMedia do aluno......: %.2f\nSituacao............: Aprovado!!\n", media);
    }
    else
    {
        printf("\nMedia do aluno......: %.2f\nSituacao............: Repovado!!\n", media);
    }
    
    system("pause");
    return 0;
}
