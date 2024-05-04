#include <stdio.h>
#include <stdlib.h>
/*Faça um programa em linguagem C que leia a nota dos dois bimestres dos alunos de uma turma,
apresente a média final do aluno e seja capaz de calcular e apresentar os itens abaixo.
a) Total e o percentual de aprovados;
b) Média da turma;
c) Total e percentual de alunos reprovados.*/

int main()
{
    int  i, qtdAlunos;
    float notaBimestre1, notaBimestre2, media_Aluno;
    float media_Turma, soma_nota = 0.0, P_aprovados = 0.0, P_reprovados = 0.0;
    int aprovados = 0, reprovados = 0;

    printf("Digite o numero de alunos: ");
    scanf("%d", &qtdAlunos);

    for ( i = 1; i <= qtdAlunos; i++)
    {
        printf("\nNota Bimestre 1 do aluno %d: ", i);
        scanf("%f", &notaBimestre1);
        printf("Nota Bimestre 2 do aluno %d: ", i);
        scanf("%f", &notaBimestre2);
    
        media_Aluno = (notaBimestre1+notaBimestre2) / 2;
        printf("media do aluno...: %.2f\n", media_Aluno);

        // Verificação de aprovação ou reprovação
        if (media_Aluno >= 6.0) {
            aprovados++;
        } else {
            reprovados++;
        }

        // Soma das notas para cálculo da média da turma
        soma_nota += media_Aluno;
    }
    //cálculo da média
    media_Turma = soma_nota / qtdAlunos;
    //porcetagem de aprovados ou reprovados
    P_aprovados = ((float) aprovados/qtdAlunos)*100;
    P_reprovados = ((float) reprovados/qtdAlunos)*100;
    
    printf("\n--------Relatorio Final--------");
    printf("\nMedia da turma: %.2f\n", media_Turma);
    printf("\nTotal de aprovados: %d\n", aprovados);
    printf("Percentual de aprovados: %.2f%%\n", P_aprovados);
    printf("\nTotal de reprovados: %d\n", reprovados);
    printf("Percentual de reprovados: %.2f%%\n\n", P_reprovados);

    system("pause");
    return 0;
}