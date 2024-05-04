#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dia;
    int mes;
    int cod_tecnico;
    int cod_equipamento;
    char problema[50];
    char solucao[50];
    char situacao;
    
} Manutencao ;

int existe_manutencao(){
    int controle = 0;
    FILE *arquivo;

    arquivo = fopen("..\\manutencao.dat", "rb");
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

void Sem_manutencoes(){
    printf("\nEquipamento sem manutencoes pendentes!!!");
}

void fechamento_cancelado(){
    printf("\n========Fechamento cancelado========\n");
}

void arquivo_n_localizado(){
    printf("\n=========Arquivo nao localizado!!=========\n");
}

void sem_atendimento(){
    printf("\n==============\nSem Historico\n==============\n");
}

void apresentar_manutencao(Manutencao maquina){

    printf("\n------------------------------");
    printf("\nData: %01d/%d\n", maquina.dia, maquina.mes);
    printf("Problema: %s", maquina.problema);
    printf("Solucao: %s", maquina.solucao);
}

void apresentar_struct_manutencao(Manutencao maquina){

    printf("\n------------------------------");
    printf("\nData: %01d/%d\n", maquina.dia, maquina.mes);
    printf("Codigo Tecnico: %d\n", maquina.cod_tecnico);
    printf("Codigo Equipamento: %d\n", maquina.cod_equipamento);
    printf("Problema: %s", maquina.problema);
    printf("Solucao: %s", maquina.solucao);
}

void apresentar_solucao_problema(Manutencao maquina){

    printf("\nProblema: %s", maquina.problema);
    printf("Solucao: %s", maquina.solucao);
    printf("---------------");
}

int contar_atendimentos(int cod){
    int atendimentos = 0;
    Manutencao maquina;

    FILE *arquivo_manutencao;

    arquivo_manutencao = fopen("..\\manutencao.dat", "rb");
    if (arquivo_manutencao == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while (fread(&maquina, sizeof(Manutencao), 1, arquivo_manutencao) == 1)
        {
            if (cod == maquina.cod_equipamento)
            {
                atendimentos++;
            } 
        }
    }

    fclose(arquivo_manutencao);
    return atendimentos;
}

int valida_historico_mes(int mes){
    FILE *arquivo;
    Manutencao maquina;
    int controle = -1;

    arquivo = fopen("..\\manutencao.dat", "rb");
    if(arquivo != NULL)
    {
        while (fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (maquina.mes == mes)
            {
                controle = 0;
            }
        }
    }
    
    fclose(arquivo);
    return controle;
}

void historico_atendimento_mes(){
    FILE *arquivo;
    Manutencao maquina;
    int mes;

    do
    {
        printf("\nMes....: ");
        scanf("%d", &mes);
    } while(validar_mes(mes) != 0);

    if(valida_historico_mes(mes) != 0) {
        sem_atendimento();
    }
    else
    {
        arquivo = fopen("..\\manutencao.dat", "rb");
        if (arquivo != NULL)
        {
            while (fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
            {
                if (maquina.mes == mes)
                {
                    apresentar_struct_manutencao(maquina);
                }
            }
        }
    }
    fclose(arquivo);
}

void historico_atendimento_equipamento(){
    FILE *arquivo;
    Manutencao maquina;
    int cod, controle = 1;

    printf("\nCodigo....: ");
    scanf("%d", &cod);
    if(valida_codigo_equipamento(cod) != 0) {
        equipamento_inesistente();
    }
    else
    {
        arquivo = fopen("..\\manutencao.dat", "rb");
        if (arquivo != NULL)
        {
            while (fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
            {
                if (maquina.cod_equipamento == cod)
                {
                    apresentar_struct_manutencao(maquina);
                    controle = 0;
                }
            }
            fclose(arquivo);
        }
        if (controle == 1)
        {
            sem_atendimento();
        }
    }
}

void localizar_codigo_equipamento(int cod){
    FILE *arquivo;
    Manutencao maquina;

    arquivo = fopen("..\\manutencao.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while(fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (maquina.cod_equipamento == cod ){
                if(maquina.situacao == 'P')
                apresentar_solucao_problema(maquina);                
            }
        }
    }
   fclose(arquivo); 
}

void localizar_manutencao(int prontuario){
    FILE *arquivo;
    Manutencao chamado;

    arquivo = fopen("..\\manutencao.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while(fread(&chamado, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (chamado.cod_tecnico == prontuario){
                apresentar_manutencao(chamado);
                localizar_equipamento(prontuario);
            }
        }
    }
    fclose(arquivo);
}

int valida_prontuario_manutencao(int prontuario){
    FILE *arquivo;
    Manutencao maquina;
    int controle = -1;

    arquivo = fopen("..\\manutencao.dat", "rb");
    if(arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while(fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (maquina.cod_tecnico == prontuario){
                controle = 0;
            }
        }
    }
    fclose(arquivo);

    return controle;
}

void atendimentos_tecnico(){
    int prontuario, controle = 0;

    lista_tecnico();

    do {
        printf("\nDigite o Prontuario..: ");
        scanf("%d", &prontuario);
        if(valida_codigo_tecnico(prontuario) != 0) {
            printf("\nProntuario invalido. Digite novamente!!");
        }
    } while(valida_codigo_tecnico(prontuario) != 0);

    controle = valida_prontuario_manutencao(prontuario);
    if (controle == -1)
    {
        printf("\n----Tecnico ainda nao fez atendimentos----\n");
    }
    else
    {
        localizar_manutencao(prontuario);
    }
}

int validar_dia(int dia){
    int controle = 0;

    if (dia < 1 || dia > 31)
    {
        printf("\nInvalido. Digite novamente.");
        controle = -1;
    }

    return controle;
}

int validar_mes(int mes){
    int controle = 0;

    if (mes < 1 || mes > 12)
    {
        printf("\nInvalido. Digite novamente.");
        controle = -1;
    }

    return controle;
}

Manutencao leitura_chamado(){
    int prontuario, cod;
    int dia, mes;
    Manutencao chamado;

    printf("\n----------Central de Chamados----------");

    do
    {
        printf("\nDigite o dia: ");
        scanf("%d", &dia);
    } while (validar_dia(dia) == -1);
    chamado.dia = dia;
    
    do
    {
        printf("\nDigite o mes: ");
        scanf("%d", &mes);
    } while (validar_mes(mes) == -1);
    chamado.mes = mes;

    apresentar_lista_equipamentos();
    do {
        printf("\nCodigo do equipamento.....: ");
        scanf("%d", &cod);
        if(valida_codigo_equipamento(cod) != 0) {
            printf("\nCodigo invalido. Digite um novo codigo.");
        }
    } while(valida_codigo_equipamento(cod) != 0);
    chamado.cod_equipamento = cod;

    lista_tecnico();

    do {
        printf("\nDigite o prontuario........: ");
        scanf("%d", &prontuario);
        if(valida_codigo_tecnico(prontuario) != 0) {
            printf("\nProntuario invalido. Digite um novo prontuario.");
        }
    } while(valida_codigo_tecnico(prontuario) != 0);
    chamado.cod_tecnico = prontuario;

    printf("Digite o problema: ");
    fflush(stdin);
    fgets(chamado.problema, 99, stdin);

    printf("Digite a solucao: ");
    fgets(chamado.solucao, 99, stdin);

    chamado.situacao = 'P';
    procurar_situacao(cod);

    return chamado;
}

void abrir_chamado(Manutencao chamado){
    FILE *arquivo_manutencao;

    arquivo_manutencao = fopen("..\\manutencao.dat", "ab");

    if (arquivo_manutencao == NULL)
       arquivo_manutencao = fopen("..\\manutencao.dat", "wb");

    if (arquivo_manutencao == NULL)
    {
        printf("\nProblema na hora de criar o arquivo!!");
    }
    else
    {
        fwrite(&chamado, sizeof(Manutencao), 1, arquivo_manutencao);
    }
    fclose(arquivo_manutencao);
}

char deseja_finalizar(){
    char escolha;

    do
    {
        printf("\nDeseja finalizar o atendimento? [S/N] ");
        scanf(" %c", &escolha);
        if (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n')
        {
            printf("\nEscolha invalida. Digite novamente!!");
        }
    } while (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n');
    
    return escolha;
}

void trocar_situacao_manutencao(Manutencao *maquina){

    if (maquina->situacao == 'P')
    {
        maquina->situacao = 'F';
    }
    
}

void fechamento_atendimento(int cod){
    FILE *arquivo;
    Manutencao maquina;
    int controle = 1;
    long posicao;
    char resposta;

    arquivo = fopen("..\\manutencao.dat", "rb+");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while (fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (maquina.cod_equipamento == cod && maquina.situacao == 'P')
            {
                apresentar_struct_manutencao(maquina);
                controle = 0;
                resposta = deseja_finalizar();
                if (resposta == 's' || resposta == 'S')
                {
                    trocar_situacao_manutencao(&maquina);
                    posicao = ftell(arquivo) - sizeof(Manutencao);
                    fseek(arquivo, posicao, SEEK_SET);
                    fwrite(&maquina, sizeof(Manutencao), 1, arquivo);
                    fflush(arquivo);
                    localizar_equipamento_fechamento(cod);
                }
            }
            else
            {
                controle = -1;
            }
        }
    }
    
    if (controle == 1)
    {
        fechamento_cancelado();
    }
    else if (controle == -1)
    {
        Sem_manutencoes();
    }
    fclose(arquivo);
}

void leitura_fechamento(){
    int cod;

    printf("Codigo do equipamento.....: ");
    scanf("%d", &cod);

    if (valida_codigo_equipamento(cod) == 0)
    {
        fechamento_atendimento(cod);
    }
    else
    {
        printf("\nCodigo invalido!!!!");
    }
}

int contar_total_atendimentos(int cod){
    int atendimentos = 0;
    FILE *arquivo;
    Manutencao maquina;

    arquivo = fopen("..\\manutencao.dat", "rb");
    if (arquivo == NULL)
    {
        arquivo_n_localizado();
    }
    else
    {
        while (fread(&maquina, sizeof(Manutencao), 1, arquivo) == 1)
        {
            if (cod == maquina.cod_equipamento)
            {
                atendimentos++;
            }
        }
    }
  
    fclose(arquivo);
    return atendimentos;
}