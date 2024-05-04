#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, resultado, resto;

    printf("\nDigite um valor: ");
    scanf("%f", &num1);

    printf("\nDigite outro valor: ");
    scanf("%f", &num2);

    resultado = num1/num2;
    resto = (int) num1 % (int) num2;

    printf("o resultado: %.2f", resultado);
    printf("\no resto da divisao: %.2f\n", resto);

    system("pause");
}