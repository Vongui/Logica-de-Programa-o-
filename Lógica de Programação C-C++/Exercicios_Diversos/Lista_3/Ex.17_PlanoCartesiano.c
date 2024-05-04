#include <stdio.h>
#include <stdlib.h>
/*Um ponto no plano cartesiano é representado pelas coordenadas (X, Y). Fazer um programa capaz de ler
as coordenadas de um ponto e apresentar:
• O ponto está na origem do sistema – as coordenadas X e Y forem zero;
• O ponto está sobre o eixo X – a coordenada Y é igual a zero;
• O ponto está sobre o eixo Y – a coordenada X é igual a zero;
• O ponto está em um dos quadrantes, de acordo com a figura abaixo.*/
int main()
{
    float X, Y;

    printf("\nDigite a coordenada X: ");
    scanf("%f", &X);
    printf("\nDigite a coordenada Y: ");
    scanf("%f", &Y);

    //Verificação da coordenada
    if (X == 0 && Y == 0)
    {   
        printf("\nO ponto esta na origem do sistema\n");
    }
    else if (Y == 0)
    {
        printf("\nO ponto esta sobre o eixo X\n");
    }
    else if (X == 0)
    {
        printf("\nO ponto esta sobre o eixo Y\n");
    }
    else if (X > 0 && Y > 0)
    {
        printf("\nO ponto esta localizado no primeiro quadrante\n");
    }
    else if (X < 0 && Y > 0)
    {
        printf("\nO ponto esta localizado no segundo quadrante\n");
    }
    else if (X < 0 && Y < 0)
    {
        printf("\nO ponto esta localizado no terceiro quadrante\n");
    }
    else
    {
        printf("\nO ponto esta localizado no quarto quadrante\n");
    }
    
    system("pause");
    return 0;
}