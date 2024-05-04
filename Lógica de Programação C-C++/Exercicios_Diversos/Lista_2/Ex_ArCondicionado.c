#include <stdio.h>
#include <stdlib.h>

int main()
{
    int BArea, BPessoas, BEquipamentos, BTotal; //BTUS por categoria
    float MedidaAmbiente, QtdPessoas, QtdEquipamentos; 

    printf("Digite a area em metros quadrados: ");
    scanf("%f", & MedidaAmbiente);

    printf("\nQuantas pessoas ficarao na sala?: ");
    scanf("%f", & QtdPessoas);

    printf("\nQuantos Aparelhos Eletronicos?: ");
    scanf("%f", & QtdEquipamentos);

    //Valor dos Btus por categoria
    BPessoas = 600;
    BEquipamentos = 300;
    BArea = 500;

    //Cálculo total
    BTotal = (MedidaAmbiente*BArea)+(QtdPessoas*BPessoas)+(QtdEquipamentos*BEquipamentos);
    //Saida do resultado pro usuário
    printf("\nA Capacidade minima necessaria e de : %d BTUS\n", BTotal);

    system("Pause");
    return 0;
}
