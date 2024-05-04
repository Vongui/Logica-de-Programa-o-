#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba o código correspondente ao cargo de um funcionário e imprima seu cargo
e o percentual de aumento ao qual este funcionário tem direito seguindo a tabela abaixo:
Código Cargo Percentual
1 Escriturário 50%
2 Secretário 35%
3 Caixa 20%
4 Gerente 10%*/
int main()
{
    int codigo;

    printf("Digite o codigo de cargo: ");
    scanf("%d", &codigo);
    switch (codigo)
    {
    case 1:
        printf("Cargo -> Escrituario\nAumento -> 50%%\n");
        break;
    case 2:
        printf("Cargo -> Secretario\nAumento -> 35%%\n");
        break;
    case 3:
        printf("Cargo -> Caixa\nAumento -> 20%%\n");
        break;
    case 4:
        printf("Cargo -> Gerente\nAumento -> 10%%\n");
        break;
    
    default:
        printf("\nDigite um codigo valido!!!\n");
        break;
    }
    system("pause");;
    return 0;
}