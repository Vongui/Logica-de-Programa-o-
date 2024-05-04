#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 10

void limpar_espaco(char nome[]){
    if (nome[strlen(nome) - 1] == '\n')
    {
        nome[strlen(nome) - 1] = '\0';
    }
}

void armazenar_nome(char lista_nome[][50], int *tl, char nome_lido[]){
    if (*tl < TF)
    {
        limpar_espaco(nome_lido);
        strcpy(lista_nome[*tl], nome_lido);
        (*tl)++;
    }
    else
    {
        printf("\nNao ha mais espaco na lista de nomes\n");
    }
}

void apresentar_nomes(char lista_nome[][50], int tl){
    
    printf("\nLista de Nomes\n");
    for (int i = 0; i < tl; i++)
    {
        printf("%d - %s\n", i+1, lista_nome[i]);
    }
}

void main(){

    FILE *arquivo;

    char lista_nome[10][50];
    char nome_lido[50];
    int tl = 0;

    arquivo = fopen("../nomes.txt", "r");
    if (arquivo == NULL)
    {
        printf("\nArquivo nao localizado!!");
    }
    else
    {
        while (fgets(nome_lido, 49, arquivo) != 0)
        {
            armazenar_nome(lista_nome, &tl, nome_lido);
        }
        apresentar_nomes(lista_nome, tl);
        fclose(arquivo);
    }
}