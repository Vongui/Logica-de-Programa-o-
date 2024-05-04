#include <stdio.h>
#include <stdlib.h>

void main(){
    
    FILE *arquivo;

    char nome[40];
    int quantidade;
    float valor;

    arquivo = fopen("../produtos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel criar o arquivo \n");   
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            fflush(stdin);
            printf("\nDigite o nome do produto: ");
            gets(nome);

            printf("\nDigite o valor do produto: ");
            scanf("%f", &valor);

            printf("\nDigite a quantidade em estoque: ");
            scanf("%d", &quantidade);

            fprintf(arquivo, "%s,%.2f,%d\n", nome, valor, quantidade);
        }
        fclose(arquivo);
    }
}