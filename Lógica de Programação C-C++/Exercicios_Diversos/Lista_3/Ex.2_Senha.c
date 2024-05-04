#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que verifique a validade de uma senha fornecida pelo usuário. A senha é o número
2023. O programa deve imprimir mensagem de permissão ou negação de acesso.*/
int main()
{
    int senha;

    printf("Digite a senha: ");
    scanf("%d", &senha);
    if (senha==2023)
    {
        printf("\nAcesso permitido\nBem-Vindo!!\n");
    }
    else
    {
        printf("\nAcesso Negado!!!\n");
    }
    
    system("pause");
    return 0;
}