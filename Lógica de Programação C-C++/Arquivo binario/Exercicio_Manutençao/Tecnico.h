#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int prontuario;
    char nome[50];
    int ramal;
} Tecnico ;


int existe_tecnico(){
    int controle = 0;
    FILE *arquivo;

    arquivo = fopen("..\\tecnicos.dat", "rb");
    if (arquivo == NULL)
    {
        controle = 0;
    }
    else
    {
        controle = 1;
    }

    fclose(arquivo);
    return controle;
}

void padrao(){
    printf("\nArquivo nao existe!!!!\n");
}

void apresentar_tecnicos(Tecnico funcionario){

    printf("\nProntuario: %d", funcionario.prontuario);
    printf("\nNome: %s", funcionario.nome);
    printf("Ramal: %d", funcionario.ramal);
    printf("\n-----------------------------\n");
}

void lista_tecnico(){
    FILE *arquivo;
    Tecnico funcionario;

    arquivo = fopen("..\\tecnicos.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Impossivel ler o arquivo");
    }
    else
    {
        printf("\n==========Lista de Tecnicos==============");
        while (fread(&funcionario, sizeof(Tecnico), 1, arquivo) == 1)
        {
            apresentar_tecnicos(funcionario);
        }
    }
    fclose(arquivo);
}

int valida_ramal_tecnico(int ramal){
    FILE *arquivo;
    Tecnico funcionario;
    int controle = -1;

    arquivo = fopen("..\\tecnicos.dat", "rb");
    if(arquivo != NULL)
    {
        while(fread(&funcionario, sizeof(Tecnico), 1, arquivo) && controle == -1)
        {
            if (funcionario.ramal == ramal || ramal < 0){
                controle = 0;
            }
        }
    }
    else if (arquivo == NULL)
    {
        if (ramal < 0){
            controle = 0;
        }
    }
    else
    {
        controle = -1;
    }

    fclose(arquivo);
    return controle;
}

int valida_codigo_tecnico(int codigo)
{
    FILE *arquivo;
    Tecnico funcionario;
    int controle = -1;

    arquivo = fopen("..\\tecnicos.dat", "rb");
    if(arquivo != NULL)
    {
        while(fread(&funcionario, sizeof(Tecnico), 1, arquivo) && controle == -1)
        {
            if (funcionario.prontuario == codigo || codigo < 0){
                controle = 0;
            }
        }
    }
    else if (arquivo == NULL)
    {
        if (codigo < 0){
            controle = 1;
        }
    }
    else
    {
        controle = -1;
    }

    fclose(arquivo);
    return controle;
}

Tecnico leitura_tecnico()
{
    Tecnico tecnico;
    int codigo, ramal;

    printf("\nCadastro de Tecnicos");

    // Verifica se o codigo já existe dentro do arquivo binario e se ele é negativo
    do {
        printf("\nDigite o Codigo........: ");
        scanf("%d", &codigo);
        if(valida_codigo_tecnico(codigo) != -1) {
            printf("\nCodigo invalido. Digite um novo codigo.");
        }
    } while(valida_codigo_tecnico(codigo) != -1);
    tecnico.prontuario = codigo; // Passando da verificação basica ele atribui o valor ao struct
    
    printf("Digite o Nome...: ");
    fflush(stdin);
    fgets(tecnico.nome, 49, stdin);

    // verifica se o Ramal já existe dentro do arquivo binario e se ele é negativo
    do {
        printf("\nDigite o ramal........: ");
        scanf("%d", &ramal);
        if(valida_ramal_tecnico(ramal) != -1) {
            printf("\nRamal invalido. Digite um novo ramal.");
        }
    } while(valida_ramal_tecnico(ramal) != -1);
    tecnico.ramal = ramal;


    return tecnico;
}

void incluir_dados_tecnico(Tecnico novo_funcionario)
{
    FILE *arquivo_funcionarios;

    arquivo_funcionarios = fopen("..\\tecnicos.dat", "ab");

    if (arquivo_funcionarios == NULL)
       arquivo_funcionarios = fopen("..\\tecnicos.dat", "wb");

    if (arquivo_funcionarios == NULL)
    {
        printf("\nProblema na hora de criar o arquivo!!");
    }
    else
    {
        fwrite(&novo_funcionario, sizeof(Tecnico), 1, arquivo_funcionarios);
        
    }
    fclose(arquivo_funcionarios);
}