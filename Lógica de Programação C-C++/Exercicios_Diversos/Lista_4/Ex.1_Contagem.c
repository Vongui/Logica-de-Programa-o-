#include <stdio.h>
#include <stdlib.h> 
/*Fazer um programa em linguagem C capaz de imprimir de 0 a 30 de dois em dois e depois imprimir de
29 até 1 de um em um.*/

int main()
{
    int i;

    for ( i = 0; i <= 30; i++)
    {
        if (i%2 == 0)
        {
            printf("%d ", i);
        }
    }
    for ( i = 29; i < 30 && i >= 1; i--)
    {
        printf("%d ", i);
    }
    
    system("pause");
    return 0;
}