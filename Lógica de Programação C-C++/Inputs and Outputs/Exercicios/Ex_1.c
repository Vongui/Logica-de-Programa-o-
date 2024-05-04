#include <stdio.h>
#include <stdlib.h>
/*A quilometragem inicial de um carro é 200000. Depois de uma viagem, a quilometragem final
do carro ficou em 205701. Fazer um programa para ler do teclado estes valores armazenando
em variáveis, depois calcular e armazenar a distância percorrida do carro e finalmente
apresentá-la*/

int main()
{
    int km, kmFinal, distanciaPercorrida;

    printf("\nDigite a quilometragem de inicio: ");
    scanf("%d", &km);
    printf("\nDigite a quilometragem final: ");
    scanf("%d", &kmFinal);

    distanciaPercorrida = kmFinal - km;

    printf("\nA distancia percorrida eh de: %d\n", distanciaPercorrida);

    system("pause");
    return 0;
}