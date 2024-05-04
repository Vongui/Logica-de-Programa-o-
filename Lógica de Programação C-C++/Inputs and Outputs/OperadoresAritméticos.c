#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Biblioteca que libera a raiz->sqrt(num) e outras funções matemáticas

int main()
{
    int n1, n2;
    int Somar, Subtrair, Multiplicar, Dividir, Resto, Potencia, Raiz;

    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);

    printf("Digite o segundo valor: ");
    scanf("%d", &n2);

    Somar = n1 + n2;
    Subtrair = n1 - n2;
    Multiplicar = n1 * n2;
    Dividir = n1 / n2;
    Resto = n1 % n2;//% -> sinal de módulo que dá como resultado o resto de uma divisão inteira
    Potencia = n1^2;//^-> eleva algum número ao expoente(após o sinal circunflexo)
    Raiz = sqrt(n1);//raiz quadrada de um número inteiro, necessita da biblioteca <math.h>
    
    printf("\nOs resultados sao: \nSomar = %d\nSubtracao = %d\nMultiplicacao = %d\nDivisao = %d",Somar, Subtrair, Multiplicar, Dividir);
    printf("\nOutros resultados: Resto = %d\nPotencia = %d\nRaiz = %d\n", Resto, Potencia, Raiz);

    system("pause");
    return 0;
}