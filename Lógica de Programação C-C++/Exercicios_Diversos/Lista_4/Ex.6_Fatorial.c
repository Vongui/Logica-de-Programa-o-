#include <stdio.h>
#include <stdlib.h>
/*Fazer um programa em linguagem C capaz de calcular o fatorial de um determinado número digitado
pelo usuário.
fatorial de 5 = 5! = 5*4*3*2*1 = 120*/

int main()
{
    int num, fatorial = 1, i;

    printf("Digite o numero desejado: ");
    scanf("%d", &num);

    for ( i = 1; i <= num; i++)
    {
        fatorial *= i;
    }
    printf("A valor fatorial desse numero eh: %d\n", fatorial);
    
    system("pause");
    return 0;
}