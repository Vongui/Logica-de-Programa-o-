#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TF 25
#define clear system("cls");

void retornar(int retorno){
    printf("Valor retornado: %d", retorno);
}
 
int compara_strings(char *string, char *string_aux){
    int igualdade;

    igualdade = strcmp(string, string_aux);
    if (igualdade == 0)
    {
        igualdade = 1;
    }
    else
    {
        igualdade = 0;
    }
    return igualdade;
}

void apresentar_menu(){
    printf("============================================menu=================================================\n\n");
    printf("1- Comparar duas strings, se as strings forem iguais, essa função deve retornar 1 e se forem diferentes deve retornar 0\n");
    printf("2- qual string é maior, se a primeira for maior retornar 1, se a segunda for maior retornar 2 e se possuírem o mesmo tamanho retornar 0\n");
    printf("3- uma string dentro de outra\n");
    printf("4- A última ocorrência de um determinado caracter dentro da string\n");
    printf("5- Se a string está vazia");
    printf("6- Contar a quantidade de letras maiúsculas\n");
    printf("7- Contar quantidade de letras minúsculas\n");    
}

void leitura(char *string, char *string_aux){
    printf("Digite o conteudo da primeira string: ");
    fgets(string, TF, stdin);
    printf("\nDigite o conteudo da segunda string: ");
    fgets(string_aux, TF, stdin);
}

int comparar_tamanho(char *string, char *string_aux){
    int tamanho;

    tamanho = strcmp(string, string_aux);
    if (tamanho > 0)
    {
        tamanho = 1;
    }
    else if(tamanho < 0)
    {
        tamanho = 2;
    }
    else
    {
        tamanho = 0;
    }
    return tamanho;
}

void localizar_string(char *string, char *string_aux){
    
    if (strstr(string, string_aux) != NULL)
    {
        printf("String encontrada!\n");
    }
    else
    {
        printf("String nao encontrada!\n");
    }   
}

void localizar_caracter(char *string){
    char carac;
    
    printf("\nDigite o caracter a ser encontrado na primeira string: ");
    fflush(stdin);
    scanf("%c", &carac);
    if (strstr(string, carac) != NULL)
    {
        printf("caracter encontrado!\n");
    }
    else
    {
        printf("caracter nao encontrado!\n");
    }   
}

int verificar_vazia(char *string){
    int vazia = 0;

    if (string[0] == '\0')
        vazia = 1;
    return vazia;
}

void contar_maiusculas(char *string, char *string_aux){
    int contador = 0, i;
    int contador2 = 0;

    for ( i = 0; string[i] != '\0'; i++)
    {
        if (isupper(string[i]))
        {
            contador++;
        }
    }
}

int minusculas(char *string){
    int contador = 0, i;

    for ( i = 0; string[i] != '\0'; i++)
    {
        if (islower(string[i]))
        {
            contador++;
        }
    }
    return contador;
}

void contar_minusculas(char *string, char *string_aux){
    int contador = 0, i;
    int contador2 = 0;

    for ( i = 0; string[i] != '\0'; i++)
    {
        if (islower(string[i]))
        {
            contador++;
        }
    }
    printf("\n A string 1 possui %d letras minusculas", contador);
    for ( i = 0; string_aux[i] != '\0'; i++)
    {
        if (islower(string_aux[i]))
        {
            contador2++;
        } 
    }
    printf("\n A string 2 possui %d letras minusculas",contador2);
}



void escolha(char *string, char *string_aux, int retorno)
{
    int escolha;
    char menu;

    do
    {
        do
        {
            apresentar_menu();
            printf("\nEscolha uma opcao: ");
            scanf("%d", &escolha);
        } while (escolha > 7 || escolha < 1);
        switch (escolha)
        {
        case 1:
            retorno = compara_strings(string, string);
            retornar(retorno);
            break;
        case 2:
            retorno = comparar_tamanho(string, string_aux);
            retornar(retorno);
            break;
        case 3:
            localizar_string(string, string_aux);
            break;
        case 4:
            localizar_caracter(string);
            break;
        case 5:
            verificar_vazia(string);
            break;
        case 6:
            contar_maiusculas(string, string_aux);
            break;
        case 7:
            printf("Quantidade de minusculas: %d\n", minusculas(string));
            printf("Quantidade de minusculas: %d\n", minusculas(string_aux));
            break;
        default:
            printf("\nOpcao invalida!!!");
            break;
        }

        printf("Deseja continuar? S/N ");
        fflush(stdin);
        scanf("%c", &menu);
    } while (menu == 's' || menu == 'S');
}

int main(){
    char string[TF], string_aux[TF];
    int retorno;

    leitura(string, string_aux);
    puts(string);
    puts(string_aux);
    escolha(string, string_aux, retorno);
    retorno = compara_strings(string, string_aux);
    printf("Valor retornado: %d", retorno);

}