#include <stdio.h>
#include <stdlib.h>
/*Considerando um veículo que participa de um rally passou pelo km 50 do percurso a 90 km/h, se essa
velocidade média for mantida, em que km do percurso o veículo estará nas próximas 12 horas? Faça um
programa em linguagem C capaz de imprimir a cada hora o km em que o veículo estará.*/

int main()
{
    int i;
    int km, velocidade;

    velocidade = 90;// Valores passados pelo enunciado
    km = 50;

    for ( i = 1; i <= 12; i++)
    {
        km = km + velocidade; // aplicação da formula passada(Descontando o valor da hora, pois sempre aumentará em 1)
        printf("Hora: %d ---> Quilometro: %d\n", i, km);
    }
    
    system("pause");
    return 0;
}