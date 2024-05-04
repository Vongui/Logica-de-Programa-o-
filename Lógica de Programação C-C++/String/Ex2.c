#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 25


void armazena_dados(char *string){
    printf("Digite a frase desejada: ");
    fgets(string, TF, stdin);
}

void inverter(char *string){
    int j = 0, i;
    char auxiliar[TF];
    int pos;

    pos = strlen(string);
    for ( i = pos >= 0; i--)
    {
        auxiliar[j] = string[i];
        j++;
    }
}



int main(){
    char string[TF];

    armazena_dados(string);
}