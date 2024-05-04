#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_tl(){
    int tamanho;




    return tamanho;
}

void main(){

    FILE *arquivo;

    char nome[50];
    int tl = 0;
    char cargo[30];
    int dia;
    int mes;
    int ano;


    arquivo = fopen("../funcionarios.txt", "r");
    if (arquivo == NULL)
    {
        printf("\nArquivo nao localizado!!");
    }
    else
    {

        tl = ler_tl();




    }
    fclose(arquivo);
}