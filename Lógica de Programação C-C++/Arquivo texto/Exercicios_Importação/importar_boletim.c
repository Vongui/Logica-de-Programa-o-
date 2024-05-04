#include <stdio.h>
#include <stdlib.h>

void main(){

    FILE *arquivo;

    char nome[10];
    double nota;
    int frequencia;

    arquivo = fopen("../boletim.txt", "r");
    if (arquivo == NULL)
    {
        printf("\nArquivo nao localizado!!");
    }
    else
    {
        printf("Disiclinas      Media    Frequencia\n");
        for(int i = 0; i < 4; i++){
        fscanf(arquivo, "%s %lf %d\n", nome, &nota, &frequencia);
        printf("%-10s %9.2lf %9d%%\n", nome, nota, frequencia);
        }
    }
    fclose(arquivo);
}