#include <stdio.h>
#include <stdlib.h>
/*. Construa programa para determinar se o indivíduo está com um peso favorável. Essa situação é
determinada através do IMC (Índice de Massa Corpórea), que é definida como sendo a relação entre o
peso (PESO) e o quadrado da Altura (ALTURA) do indivíduo. E, a situação do peso é determinada pela
tabela abaixo:
Condição do IMC Situação
abaixo de 20 Abaixo do peso
de 20 até 25 Peso Normal
acima de 25 até 30 Sobrepeso
acima de 30 até 40 Obesidade
acima de 40 Obesidade mórbida*/
int main()
{
    float Peso, IMC, Altura;

    printf("Digite a sua altura(em metros): ");
    scanf("%f", &Altura);
    printf("Digite o seu peso(em Kg): ");
    scanf("%f", &Peso);

    IMC = Peso/(Altura*Altura);
    printf("Valor IMC....: %.2f", IMC);
    if (IMC<20)
    {
        printf("\nSituacao.....: Abaixo do peso\n");
    }
    else if (IMC >=20 && IMC <=25)
    {   
        printf("\nSituacao.....: Peso Normal\n");
    }
    
    else if (IMC >25 && IMC <=30)
    {
        printf("\nSituacao.....: Sobrepeso\n");
    }
    else if (IMC >30 && IMC <=40)
    {
        printf("\nSituacao.....: Obsidade\n");
    }
    else
    {
        printf("\nSituacao.....: Obsidade morbida\n");
    }
    
    system("pause");
    return 0;
}