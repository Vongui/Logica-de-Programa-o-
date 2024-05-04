#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void separar_imprimir_elementos(){
    FILE *auxiliar;
    char linha[256];
    int controle = 0;
    char comeco;


    auxiliar = fopen("..\\auxiliar.txt", "r");
    if (auxiliar == NULL)
    {
        printf("Arquivo nao existe!!!");
    }
    else
    {
        while (controle == 0)
        {
            fgets(linha, 256, auxiliar);
            comeco = linha[0];
            
            if (comeco == '#')
            {
                printf("Identificador: %s", linha);
            }
            else if (comeco == '.')
            {
                printf("Classe: %s", linha);
                controle = 1;
            }
           else if (comeco != '.' && comeco != '#'  && comeco != ' ')
           {
                printf("Elemento: %s", linha);
           }    
        }
    }
    fclose(auxiliar);
}

void prepara_arquivo(FILE *arquivo, FILE *auxiliar)
{
    int gravar  = 1;
    char caracter;

    caracter = fgetc(arquivo);
    while(caracter != EOF)
    {
        if (caracter == '{')
           gravar = 0;
        if (caracter == '}')
           gravar = 1;

        if (gravar)
        {
            if (caracter == '}')
            {
                
            }
            else
            {
                fputc(caracter, auxiliar);
            }
        }
        caracter = fgetc(arquivo);
    }
    caracter = EOF;
    fclose(auxiliar);
    separar_imprimir_elementos();
}

void abrir_auxiliar(FILE *arquivo){
    FILE *auxiliar;

    auxiliar = fopen("..\\auxiliar.txt", "w");
    if (auxiliar == NULL)
    {
        printf("Arquivo com erro!!");
    }
    else
    {
        prepara_arquivo(arquivo, auxiliar);
    }
    
}

void processa_arquivo(){

    FILE *arquivo;

    arquivo = fopen("..\\codigo.css", "r");
    if (arquivo == NULL)
    {
        printf("\nArquivo nao encontrado!!!");
    }
    else
    {
        abrir_auxiliar(arquivo);
    }
    fclose(arquivo);
}


void main(){

    processa_arquivo();
}
 