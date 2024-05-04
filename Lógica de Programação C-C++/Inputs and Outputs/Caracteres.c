#include <stdio.h>
#include <stdlib.h>

//Função scanf() -> não aceita "nomes" com espaço
//Função gets() -> Aceita Nomes intercalado com espaços
//Usar as funções scanf() e gets() no mesmo código gera buffer de teclado, ou seja, dá erro de compilação
//Obs -> ao usar entradas numéricas e dps entradas Strings: limpar o buffer de teclado
int main()
{
    char Letra;
    char Nome[30];//Imita a função Sting -> entre colchetes é o nº de caracteres que poderão ser armazenados

    printf("\nDigite uma letra: ");
    scanf("%c", &Letra);
    fflush(stdin);//Funçaõ ffflush -> limpa o buffer de teclado/ stdin -> Padrão de entrada

    printf("Digite o seu nome: ");
    //scanf("%s", &Nome[0]);// %s-> =String, nesse caso ele detecta que vai ser uma sequência de caracteres
    // Nome[0] -> Mostra a máquina a partir de qual número ela irá armazenar
    gets(Nome); // -> Aceita nomes intercalados com espaço

    printf("\nA letra digitada foi: %c\n", Letra);
    printf("O nome digitado foi %s\n", Nome);

    system("pause");
    return 0;
}