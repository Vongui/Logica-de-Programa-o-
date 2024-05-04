#include <stdio.h>
#include <stdlib.h>

int main()
{
    float   nota_1, nota_2, nota_3, media;
    float   pesoN_1, pesoN_2, pesoN_3; //media ponderada-> pesos de cada nota

    printf("Digite a nota da avaliacao bimestral: ");
    scanf("%f", &nota_1);

    printf("\nDigite a nota do trabalho: ");
    scanf("%f", &nota_2);

    printf("\nDigite a nota do simulado: ");
    scanf("%f", &nota_3);

// atribuindo valor aos pesos de cada nota
    pesoN_1 = 6;
    pesoN_2 = 2;
    pesoN_3 = 2;

    media = ((nota_1*pesoN_1)+(pesoN_2*nota_2)+(pesoN_3*nota_3))/(pesoN_1+pesoN_2+pesoN_3);

    printf("\nAvaliacao Bimestral: %0.2f \nTrabalho pratico: %0.2f \nSimulado: %0.2f", nota_1, nota_2, nota_3);
    printf("\n\nA sua media final e: %.2f\n", media);

    system("pause");
    return 0;

}