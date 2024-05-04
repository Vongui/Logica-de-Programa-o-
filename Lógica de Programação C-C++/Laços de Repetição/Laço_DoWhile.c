#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;

    do
    {
        system("cls");
        printf("Menu de opcoes:\n0 - Encerra o programa\n1 - inclui panela\n2 - inclui chaleira\n3 - inlcui prato\n");
        scanf("%d", &opcao);
    } while (opcao != 0);
    
}