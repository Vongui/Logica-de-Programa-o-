#include <stdio.h>
#include <stdlib.h>

/*
> -> maior que
< -> menor que 
>= -> maior ou igual
<= -> menor ou igual 
== -> igual
!= -> diferente
*/
int main()
{
    int num;

    printf("\ndigite um numro: ");
    scanf("%d", &num);

    if (num>=0)//Só testa se eh V ou F
    {
        printf("\no numero %d eh positivo ", num);
    }
    
    system("\npause");
    return 0;
}