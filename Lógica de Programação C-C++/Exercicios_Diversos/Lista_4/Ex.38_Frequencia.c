#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Fazer um programa que:
a) Preencha aleatoriamente (random) um vetor de caracteres contendo 40 notas dos alunos de uma turma
(de A a E);
b) Calcule a frequência absoluta e a frequência relativa de cada nota;
c) imprima uma tabela contendo a nota (de A a E) e suas respectivas frequências absoluta e relativa.*/
int main()
{
    char vetor[40];
    int contadorA = 0, contadorB = 0, contadorC = 0, contadorD = 0, contadorE = 0;
    float frequencia_relativaA, frequencia_relativaB, frequencia_relativaC, frequencia_relativaD, frequencia_relativaE;
    int i;

    srand(time(NULL));

    for ( i = 0; i < 40; i++)
    {
        vetor[i] = 'A' +rand()%5 ;
    }

    for ( i = 0; i < 40; i++)
    {
        if (vetor[i] == 'A')
        {
            contadorA++;
        }
        else if(vetor[i] == 'B')
        {
            contadorB++;
        }
        else if (vetor[i] == 'C')
        {
            contadorC++;
        }
        else if(vetor[i] == 'D')
        {
            contadorD++;
        }
        else if (vetor[i] == 'E')
        {
            contadorE++;
        }
    }

    frequencia_relativaA = (float) contadorA/40*100;
    frequencia_relativaB = (float) contadorB/40*100;
    frequencia_relativaC = (float) contadorC/40*100;
    frequencia_relativaD = (float) contadorD/40*100;
    frequencia_relativaE = (float) contadorE/40*100;

    printf("Frequencia absoluta de A..: %d\nFrequencia relativa de A..: %.2f%%\n\n", contadorA, frequencia_relativaA);
    printf("Frequencia absoluta de B..: %d\nFrequencia relativa de B..: %.2f%%\n\n", contadorB, frequencia_relativaB);
    printf("Frequencia absoluta de C..: %d\nFrequencia relativa de C..: %.2f%%\n\n", contadorC, frequencia_relativaC);
    printf("Frequencia absoluta de D..: %d\nFrequencia relativa de D..: %.2f%%\n\n", contadorD, frequencia_relativaD);
    printf("Frequencia absoluta de E..: %d\nFrequencia relativa de E..: %.2f%%\n\n", contadorE, frequencia_relativaE);

    system("pause");
    return 0;
}