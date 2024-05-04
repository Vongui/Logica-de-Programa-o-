#include <stdio.h>
#include <stdlib.h>
/*No curso de técnico em informática, a nota final do estudante é calculada a partir de 3 notas atribuídas
respectivamente a um trabalho de laboratório, a uma avaliação semestral e a um exame final. As notas
variam de 0 a 10 e a nota final é a média ponderada das 3 notas mencionadas. Os pesos são:
• Laboratório - peso 2
• Av. semestral - peso 3
• Exame final - peso 5
Com base na nota do aluno apresentar se ele está aprovado (média >= 6), reprovado (média < 4.0) ou
em exame para os alunos que obtiveram média entre 4,0 e 6,0.*/
int main()
{
    float n1, n2, n3, media;
    
    printf("\nDigite a nota do laboratorio: ");
    scanf("%f", &n1);
    printf("\nDigite a nota da avalicao semestral: ");
    scanf("%f", &n2);
    printf("\nDigite a nota do exame final: ");
    scanf("%f", &n3);

    media = ((n1*2)+(n2*3)+(n3*5))/10;
    printf("\nMedia: %.2f", media);
    if (media >= 6)
    {
        printf("\nAluno Aprovado!!!\n");
    }
    else if (media < 4.0 )
    {
        printf("\nAluno Reprovado!!\n");
    }
    else
    {
        printf("\nAluno ficou de Exame!!\n");
    }
    
    system("pause");
    return 0;
}