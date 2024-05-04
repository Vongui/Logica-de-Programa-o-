#include <stdio.h>
#include <stdlib.h> 
#define Gravidade 10
/*Considerando que uma bolinha de gude cai do último andar de um prédio de 20 andares. Qual a
velocidade da bolinha e a distância percorrida a cada segundo? O tempo gasto para atingir o solo foi de
7 segundos*/

int main()
{
    int i, tempo, velocidade, distanciaPercorrida;

    tempo = 1; //pois quer saber o tempo em cada segundo
    for ( i = 1; i <= 7; i++)
    {
        velocidade = tempo * Gravidade;
        distanciaPercorrida = (Gravidade*(tempo*tempo))/2;
        printf("\nVelocidade no segundo %d: %d m/s\n", tempo, velocidade);
        printf("Distancia no segundo %d: %d metros \n", tempo, distanciaPercorrida);
        tempo++;
    }
    
    system("pause");
    return 0;
}