#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Preco, CustoTeatro, QtdConvite;

// entradas: com os valores principais->
    printf("Digite o custo total da peca teatral: (em reais) ");
    scanf("%f", & CustoTeatro);

    printf("\nDigite quanto esta sendo cobrado pelo convite da peca: ");
    scanf("%f", & Preco);

// operação / Cálculo->
    QtdConvite = CustoTeatro/Preco;

// saída com resultado->
    printf("\nA quantidade de convites que deverao ser vendidos, para que se cubra o valor da peca de teatro e de: %.0f\n", QtdConvite);

    system("Pause");
    return 0;
}
