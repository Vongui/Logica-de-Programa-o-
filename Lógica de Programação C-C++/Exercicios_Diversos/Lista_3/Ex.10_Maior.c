#include <stdio.h>
#include <stdlib.h>
/*. Faça um algoritmo que receba dois números e imprima os dois números em ordem crescente.*/
int main()
{
    float n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    if (n1>n2)
    {
        printf("em ordem crescente: %.2f, %.2f\n", n2, n1);
    }
    else
    {
        printf("em ordem crescente: %.2f, %.2f\n", n1, n2);    
    }
    
    system("pause");
    return 0;
}