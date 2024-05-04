#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TF 20

void armazena_dados(char nome[], char sobrenome[], char titulo[], char editora[], char cidade[], char ano[]){
    printf("Digite o primeiro nome do escritor: ");
    fgets(nome, TF, stdin);
    printf("Digite o sobrenome: ");
    fgets(sobrenome, TF, stdin);
    printf("Digite o titulo: ");
    fgets(titulo, TF, stdin);
    printf("Digite a editora: ");
    fgets(editora, TF, stdin);
    printf("Digite o nome da cidade: ");
    fgets(cidade, TF, stdin);
    printf("Digite o ano da publicacao: ");
    fgets(ano, 5, stdin);
}

void maiusculo_sobrenome(char sobrenome[]){
    int i = 0;

    while (sobrenome[i] != '\0')
    {
        sobrenome[i] = toupper(sobrenome[i]);
        i++;
    }
}

void quebra_linha(char nome[], char sobrenome[], char titulo[], char editora[], char cidade[], char ano[]){

    nome[strcspn(nome, "\n")] = '\0';
    sobrenome[strcspn(sobrenome, "\n")] = '\0';
    titulo[strcspn(titulo, "\n")] = '\0';
    editora[strcspn(editora, "\n")] = '\0';
    cidade[strcspn(cidade, "\n")] = '\0';
    ano[strcspn(ano, "\n")] = '\0';
}

void forma_string(char nome[], char sobrenome[], char titulo[], char editora[], char cidade[], char ano[]){
    char string_saida[200];

    strcpy(string_saida, sobrenome);
    strcat(string_saida, ", ");
    strcat(string_saida, nome);
    strcat(string_saida, ". " );
    strcat(string_saida, titulo);
    strcat(string_saida, ". " );
    strcat(string_saida, editora);
    strcat(string_saida, ": " );
    strcat(string_saida, cidade);
    strcat(string_saida, ", " );
    strcat(string_saida, ano);
    strcat(string_saida, "." );
    printf("%s", string_saida);
}

int main(){
    char nome[TF], sobrenome[TF], titulo[TF], editora[TF], cidade[TF], ano[5];

    armazena_dados(nome, sobrenome, titulo, editora, cidade, ano);
    maiusculo_sobrenome(sobrenome);
    quebra_linha(nome, sobrenome, titulo, editora, cidade, ano);
    forma_string(nome, sobrenome, titulo, editora, cidade, ano);
}