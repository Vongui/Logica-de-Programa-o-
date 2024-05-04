#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 20


void armazena_nome(char nome[], char nome2[], char nome3[]){
    printf("Digite o nome do primeiro aluno: ");
    fgets(nome, TF, stdin);
    printf("\nDigite o nome do segundo aluno: ");
    fgets(nome2, TF, stdin);
    printf("\nDigite o nome do terceiro aluno: ");
    fgets(nome3, TF, stdin);
    }

void coloca_em_ordem(char nome[], char nome2[], char nome3[]){
    char temp[TF];

    if (strcmp(nome, nome2) > 0) {
        strcpy(temp, nome);
        strcpy(nome, nome2);
        strcpy(nome2, temp);
    }

    if (strcmp(nome, nome3) > 0) {
        strcpy(temp, nome);
        strcpy(nome, nome3);
        strcpy(nome3, temp);
    }

    if (strcmp(nome2, nome3) > 0) {
        strcpy(temp, nome2);
        strcpy(nome2, nome3);
        strcpy(nome3, temp);
    }
}

void apresentar(char nome[], char nome2[], char nome3[]){
    printf("Nomes em ordem alfabetica:\n%s%s%s", nome, nome2, nome3);
}

int main(){
    char nome[TF], nome2[TF], nome3[TF];

    armazena_nome(nome, nome2, nome3);
    coloca_em_ordem(nome,nome2,nome3);
    apresentar(nome, nome2, nome3);
}
