#include <stdio.h>
#include <stdlib.h>

/*
Uma empresa de fretamento para fazer um or�amento do valor de uma viagem utiliza a dist�ncia total
percorrida, valor total dos ped�gios, valor da hora do motorista e o valor por km percorridos. Fa�a um
algoritmo capaz de calcular o valor total do frete de uma viagem, onde a empresa define a velocidade
do ve�culo de acordo com o tipo de rodovia.
*/
int main()
{
    float orcamento, orcamentofinal, precokm, distanciatotal, motorista, pedagio, kmpercorrido;

    printf("\nBem-vinda a nossa empresa de fretamento.\nPara comecarmos digite a distancia total em Km: ");
    scanf("%f", &distanciatotal);

    printf("\nAgora, digite o valor dos pedagios: ");
    scanf("%f", &pedagio);

    printf("\nQual o valor da hora do motorista? ");
    scanf("%f", &motorista);

    printf("\nQual o valor por Km percorrido: ");
    scanf("%f", &kmpercorrido);

    printf("\nRealizamos o calculo e por conta do seu trajeto a velocidade maxima do onibus sera de : 80Km/H \n");

    //Cálculo do preço do km 
    precokm = (kmpercorrido*distanciatotal);

    //Cálculo do orçamento e do orçamento final
    orcamento = precokm+motorista+pedagio;
    orcamentofinal = (orcamento*0.1) + orcamento;

    printf("O valor final do seu orcamento e: R$%.2f\n\n", orcamentofinal);

    system("pause");
    return 0;
}