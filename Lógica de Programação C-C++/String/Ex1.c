#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 50
#define clear system("cls");

void apresentar_string(char *string){

    puts(string);
}

void apresentar_menu(){

        printf("========================Menu de Acoes========================\n");
        printf("1- Excluir um caracter de uma determinada posição de uma string\n");
        printf("2- Incluir um caracter em uma determinada posição de uma string\n");
        printf("3- Copiar uma parte de uma string para dentro de outra, para isso deve-se conhecer a posição inicial e o final a ser copiada\n");
        printf("4- Copiar a última palavra de uma string para outra string\n");
        printf("5- Copiar a primeira palavra de uma string para outra\n");
        printf("6- Retirar os espaços em branco repetidos de uma string\n");
        printf("7- Retirar os espaços em branco do final de uma string\n");
        printf("8- Retirar os espaços em branco do início de uma string\n");
        printf("9- Copiar o conteúdo de uma string para outra\n");
        printf("10- Apagar o conteúdo de uma string\n");
        printf("11- Apresentar String!\n");
}

void escolha(char string[], char string_aux[]){
    int escolha;
    char menu;

    do
    {
        clear; //Limpa a tela
        apresentar_menu();
        do{
            printf("Digite a opcao: ");
            scanf("%d", &escolha);
        }while (escolha > 11 || escolha < 1);

        switch (escolha)
        {
        case 1:
            excluir_caracter_posicao(string);
            break;
        case 2:
            incluir_caracter(string);
            break;
        case 3:
            copiar_parte(string,string_aux);
            break;
        case 4:
            copiar_ultima_palavra(string, string_aux);
            break;
        case 5:
            copiar_primeira_palavra(string, string_aux);
            break;
        case 6:
            retirar_espacos_em_branco(string);
            break;
        case 7:
            remover_espaco_final(string);
            break;
        case 8:
            remover_espaco_inicio(string);
            break;
        case 9:
            copiar_string(string, string_aux);
            break;
        case 10:
            apagar_string(string);
            break;
        case 11:
            apresentar_string(string);
            break;
        default:
            printf("escolha invalida!!\n");
            break;
        }

        printf("Deseja voltar ao menu? S/N ");
        fflush(stdin);
        scanf("%c", &menu);
    } while (menu == 's' || menu == 'S');
}

void remover_espaco_inicio(char *string){
    int i, j = 0;
    while (string[j] == ' ') {
        j++;
    }
    for (i = 0; string[j + i] != '\0'; i++) {
        string[i] = string[j + i];
    }
    string[i] = '\0';
}

void remover_espaco_final(char *string){
    int i = strlen(string) - 1;
    while (i >= 0 && string[i] == ' ') {
        string[i] = '\0';
        i--;
    }
}

void retirar_espacos_em_branco(char *string){
    int i, j;
    int espacoAnterior = 0;
    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' || !espacoAnterior) {
            string[j++] = string[i];
        }
        espacoAnterior = (string[i] == ' ');
    }
    string[j] = '\0';
}

void copiar_string(char string[], char string_aux[]){
    strcpy(string, string_aux);
}

void copiar_parte(char *string, char *string_aux){
    int pos1, pos2, intervalo;

    fflush(stdin);
    printf("\nDigite a posicao inicial: ");
    scanf("%d", &pos1);
    printf("\nDigite a posicao final: ");
    scanf("%d", &pos2);
    intervalo = pos2 - pos1 + 1;
    strncpy(string_aux, string+pos1, intervalo);
    string_aux[intervalo] = '\0';
}

void copiar_ultima_palavra(char *string, char *string_aux){
    memset(string_aux, 0, strlen(string_aux)); // Limpa a variavel auxiliar antes de armazenar um novo valor

    if (strrchr(string, ' ') == NULL)
    {
        strcpy(string_aux, string);
    }
    else
    {
        strcpy(string_aux, strrchr(string, ' ') + 1);
    }
}

void copiar_primeira_palavra(char *string, char *string_aux){
    memset(string_aux, 0, strlen(string_aux));
    strcpy(string_aux, strtok(string, " "));
}

void incluir_caracter(char *string){
    int i, pos;
    char carc;

    printf("\nDigite a posicao em que deseja adicionar ");
    scanf("%d", &pos);
    printf("\nDigite o caracter a ser adicionado: ");
    fflush(stdin);
    scanf("%c", &carc);
    for (i = 0; i < strlen(string); i++)
    {
        if (i == pos)
        {
        string[i] = carc;   
        }
    }
}

void excluir_caracter_posicao(char string[]){
    int i, posicao;

    printf("Digite a posicao que deseja excluir: ");
    scanf("%d", &posicao);

    for ( i = posicao; string[i] != '\0'; i++)
    {
        string[i] = string[i+1];
    } 
} 

void apagar_string(char string[]){
    memset(string, 0, strlen(string));
}

int main(){

    char string[TF], string_aux[TF];

    printf("Digite uma mensagem inicial: ");
    fgets(string, TF, stdin);
    escolha(string, string_aux);
    printf("\nPrograma Encerrando..... ");
}