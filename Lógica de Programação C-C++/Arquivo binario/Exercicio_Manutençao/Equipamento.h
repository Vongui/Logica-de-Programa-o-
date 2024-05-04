#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    char descricao[100];
    int num_lab;
    int num_maq;
    char situacao;
} Equipamento ;


int existe_equipamento(){
    FILE *arquivo;
    int controle = 0;

    arquivo = fopen("..\\equipamentos.dat", "rb");
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

void apresentar_contagem_total(int cod, int atendimentos){
    printf("\nCod Equipamento %d--> Quantidade de atendimentos: %d\n", cod, atendimentos);
}

void apresentar_contagem_lab(int atendimentos){
    printf("\nNumero de atendimentos para o laboratorio: %d\n", atendimentos);
}

void laboratorio_inesxistente(){
    printf("\n===========Laboratorio inesxistente===========\n");
}

void equipamento_inesistente(){
    printf("\nEquipamento nao existente!!!\n");
}

void localizar_manutencao_equipamento(){
    FILE *arquivo;
    Equipamento ferramenta;
    int controle = 0;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Impossivel localizar o arquivo");
    }
    else
    {
        while(fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            if (ferramenta.situacao == 'M'){
                apresentar_struct_equipamento(ferramenta);
                localizar_codigo_equipamento(ferramenta.cod);
                controle = 1;
            }
        }
    }
    if (!controle)
    {
        sem_atendimento();
    }
    fclose(arquivo);
}

void verifica_lab(){
    int atendimentos = 0, laboratorio, controle = 0;
    FILE *arquivo;
    Equipamento ferramenta;

    printf("\nDigite o numero do laboratorio: ");
    scanf("%d", &laboratorio);

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while (fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            if (ferramenta.num_lab == laboratorio)
            {
                atendimentos += contar_atendimentos(ferramenta.cod);
                controle = 1;
            }
            
        }
    }
    
    if (controle == 1)
    {
        apresentar_contagem_lab(atendimentos);
    }
    else 
    {
        laboratorio_inesxistente();
    }
    fclose(arquivo);
}

void apresentar_quantidade_atendimento_lab(Equipamento ferramenta, int qtd_lab){

    printf("\n------------------------------");
    printf("\n====Atendimentos====");
    printf("\nLaboratorio: %d", ferramenta.num_lab);
    printf("\nQuantidade: %d", qtd_lab);
}

void apresentar_lab_maq(Equipamento ferramenta){

    printf("Laboratorio: %d", ferramenta.num_lab);
    printf("\nNumero da maquina: %d", ferramenta.num_maq);
}

void localizar_equipamento(int prontuario){
    FILE *arquivo;
    Equipamento ferramenta;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Impossivel localizar o arquivo");
    }
    else
    {
        while(fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            if (ferramenta.cod == prontuario){
                apresentar_lab_maq(ferramenta);
            }
        }
    }
    fclose(arquivo);
}

void trocar_situacao_fechamento(Equipamento *ferramenta){

    if (ferramenta->situacao == 'M')
    {
        ferramenta->situacao = 'F';
    }
    
}

void localizar_equipamento_fechamento(int cod){
    FILE *arquivo;
    Equipamento ferramenta;
    long posicao;

    arquivo = fopen("..\\equipamentos.dat", "rb+");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while(fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            if (ferramenta.cod == cod){
                trocar_situacao_fechamento(&ferramenta);
                posicao = ftell(arquivo) - sizeof(Equipamento);
                fseek(arquivo, posicao, SEEK_SET);
                fwrite(&ferramenta, sizeof(Equipamento), 1, arquivo);
                fflush(arquivo);
            }
        }
    }
    fclose(arquivo);
}

void trocar_situacao(Equipamento *ferramenta){

    if (ferramenta->situacao == 'F')
    {
        ferramenta->situacao = 'M';
    }
}

void procurar_situacao(int codigo_equipamento){
    FILE *arquivo;
    Equipamento ferramenta;
    long posicao;

    arquivo = fopen("..\\equipamentos.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("Impossivel abrir o arquivo");
    }
    else
    {
        while (fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            if (ferramenta.cod == codigo_equipamento)
            {
                trocar_situacao(&ferramenta);
                posicao = ftell(arquivo) - sizeof(Equipamento);
                fseek(arquivo, posicao, SEEK_SET);
                fwrite(&ferramenta, sizeof(Equipamento), 1, arquivo);
                fflush(arquivo);
            }
        }
    }
    fclose(arquivo);
}

void apresentar_struct_equipamento(Equipamento ferramenta){

    printf("\nCodigo do equipamento: %d", ferramenta.cod);
    printf("\nDescricao do equipamento: %s", ferramenta.descricao);
    printf("Numero do laboratorio: %d", ferramenta.num_lab);
    printf("\nNumero da maquina: %d", ferramenta.num_maq);
    printf("\nSituacao: %c", ferramenta.situacao);
    printf("\n-----------------------");
}

void apresentar_lista_equipamentos(){
    Equipamento lista;
    FILE *arquivo;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        printf("\n==========Lista de equipamentos==============");
        while (fread(&lista, sizeof(Equipamento), 1, arquivo) == 1)
        {
            apresentar_struct_equipamento(lista);
        }
        
    }
    fclose(arquivo);
}

int valida_codigo_maquina(int n_maq)
{
    FILE *arquivo;
    Equipamento ferramenta;
    int controle = -1;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if(arquivo != NULL)
    {
        while(fread(&ferramenta, sizeof(Equipamento), 1, arquivo) && controle == -1)
        {
            if (ferramenta.num_maq == n_maq || n_maq < 0){
                controle = 0;
            }
        }
    }
    else if (arquivo == NULL)
    {
        if (n_maq < 0){
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

int valida_codigo_equipamento(int codigo)
{
    FILE *arquivo;
    Equipamento ferramenta;
    int controle = -1;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if(arquivo != NULL)
    {
        while(fread(&ferramenta, sizeof(Equipamento), 1, arquivo) && controle == -1)
        {
            if (ferramenta.cod == codigo || codigo < 0)
                controle = 0;
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

Equipamento leitura_equipamento(){
    Equipamento novo_equipamento;
    int cod, n_maq;
    
    printf("\n--Cadastro de novo equipamento--");
    do {
        printf("\nCodigo........: ");
        scanf("%d", &cod);
        if(valida_codigo_equipamento(cod) != -1) {
            printf("\nCodigo invalido. Digite um novo codigo.");
        }
    } while(valida_codigo_equipamento(cod) != -1);
    novo_equipamento.cod = cod;

    printf("Digite a descricao do equipamento: ");
    fflush(stdin);
    fgets(novo_equipamento.descricao, 99, stdin);

    printf("Digite o numero do laboratorio: ");
    scanf("%d", &novo_equipamento.num_lab);

    do {
        printf("Digite o numero da maquina....: ");
        scanf("%d", &n_maq);
        if(valida_codigo_maquina(n_maq) != -1) {
            printf("\nNumero de maquina invalido. Digite um novo numero da maquina");
        }
    } while(valida_codigo_maquina(n_maq) != -1);
    novo_equipamento.num_maq = n_maq;

    novo_equipamento.situacao = 'F';

    return novo_equipamento;
}

void incluir_dados_equipamento(Equipamento novo_equipamento)
{
    FILE *arquivo_equipamentos;

    arquivo_equipamentos = fopen("..\\equipamentos.dat", "ab");

    if (arquivo_equipamentos == NULL)
       arquivo_equipamentos = fopen("..\\equipamentos.dat", "wb");

    if (arquivo_equipamentos == NULL)
    {
        printf("\nProblema na hora de criar o arquivo!!");
    }
    else
    {
        fwrite(&novo_equipamento, sizeof(novo_equipamento), 1, arquivo_equipamentos);
    }
    fclose(arquivo_equipamentos);
}

void contabilizar_cod(){
    int atendimentos = 0, cod = 0;
    Equipamento ferramenta;
    FILE *arquivo;

    arquivo = fopen("..\\equipamentos.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while (fread(&ferramenta, sizeof(Equipamento), 1, arquivo) == 1)
        {
            atendimentos = 0;
            cod = ferramenta.cod;
            atendimentos += contar_total_atendimentos(cod);
            apresentar_contagem_total(cod, atendimentos);
        }
    }
    fclose(arquivo);
}