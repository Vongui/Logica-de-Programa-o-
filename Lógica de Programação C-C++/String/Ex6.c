#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TF 50


void armazena_dados(char nome[], char nome2[]){
    printf("Digite o primeiro nome: ");
    fgets(nome, TF, stdin);
    printf("Digite o segundo nome: ");
    fgets(nome2, TF, stdin);
}

int caracteres_nome1(char nome[]){
    int contador1 = 0;

    contador1 = strlen(nome);
    return contador1;
}

int caracteres_nome2(char nome2[]){
    int contador2;

    contador2 = strlen(nome2);
    return contador2;
}

void compara(char nome[], char nome2[]){
    int contador1 = 0, contador2 = 0;

    contador1 = caracteres_nome1(nome);
    contador2 = caracteres_nome2(nome2);

    if (contador1 > contador2)
    {
        printf("O nome %s eh maior e possui %d caracteres\n", nome, contador1);
    }
    else if (contador2 > contador1)
    {
        printf("O nome %s eh maior e possui %d caracteres\n", nome2, contador2);
    }
    else
    {
        printf("Os dois nomes possuem o mesmo numero de caracteres!!\n");
    }
}

void quebra_linha(char nome[], char nome2[]){
    nome[strcspn(nome, "\n")] = '\0';
    nome2[strcspn(nome2, "\n")] = '\0';
}

int main(){
    char nome[TF], nome2[TF];

    armazena_dados(nome, nome2);
    quebra_linha(nome, nome2);
    compara(nome, nome2);
}