#include <stdio.h>  
#include <stdlib.h>
/*Fazer um programa em linguagem C capaz de imprimir o quadrado e o cubo dos números de 1 ate 20*/

int main()
{
    int i;
    int quadrado[21], cubo[21];

    printf("Ao Quadrado...: ");
    for ( i = 1; i <= 20; i++)
    {
        quadrado[i] = i*i;
        printf("%d ", quadrado[i]); 
    }
    printf("\nAo Cubo.......: ");
    for ( i = 1; i <= 20; i++)
    {
        cubo[i] = i*i*i;
        printf("%d ", cubo[i]); 
    }
    
    system("pause");
    return 0;
}