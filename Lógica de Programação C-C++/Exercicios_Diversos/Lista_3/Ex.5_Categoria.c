#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que receba a idade de um nadador e imprima a sua categoria seguindo as regras:
Categoria Idade Idade
Infantil A 5 - 7 anos
Infantil B 8 - 10 anos
Juvenil A 11- 13 anos
Juvenil B 14- 17 anos
Adulto maiores de 18 anos*/
int main()
{
    int Idade;

    printf("Digite a a idade do Competidor (A partir de 5 anos): ");//Pede ao usuario a idade
    scanf("%d", &Idade);
//utiliza uma sequencia de else ifs
    if (Idade >=5 && Idade <=7)
    {
        printf("\nA sua Categoria eh: Infantil A \n");
    }
    else if (Idade >=8 && Idade <=10)
    {
        printf("\nA sua Categoria eh: Infantil B \n");
    }
    else if (Idade >=11 && Idade <=13)
    {
        printf("\nA sua Categoria eh: Juvenil A \n");
    }
    else if (Idade >=14 && Idade <=17)
    {
        printf("\nA sua Categoria eh: Juvenil B \n");  
    }
    else if (Idade >=18)
    {
        printf("\nA sua Categoria eh: Adulto \n");
    }
    else
    {
        printf("\nInfelizmente nao ha categoria para essa faixa etaria!!!\n");
    }
    

    system("pause");
    return 0;
}