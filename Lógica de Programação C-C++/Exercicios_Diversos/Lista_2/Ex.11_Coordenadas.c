/*Calcule a distância entre dois pontos do plano cartesiano. A coordenada de cada um dos pontos é
formada por (x, y). A distância é calculada de acordo com a figura abaixo. A raiz quadrada é extraída
utilizando sqrt(numero) e expoente deve-se utilizar ^.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    //utilizei da galeria Math, pois não estava funcionando com '^'
int main()
{
    float x1, x2, y1, y2, DistanciaTotal;
    
    printf("\nDigite a primeira coordenada: ");
    scanf("\n%f %f", &x1, &y1);

    printf("\nDigite a segunda coordenada: ");
    scanf("\n%f %f", &x2, &y2);

    //Faz cálculo com potência
    DistanciaTotal = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("\nO valor da distancia entre esses pontos e: %0.2f\n", DistanciaTotal);

    system("pause");
}