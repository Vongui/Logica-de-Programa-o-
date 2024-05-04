#include <stdio.h>
#include <stdlib.h>

struct S_Vendas
{
    int dia;
    int mes;
    int ano;
    int qtd;
    int codigo;
    float valor;
};

void exportar_vendas(struct S_Vendas tab_vendas[], int tl_vendas){
    FILE *arquivo_vendas;

    arquivo_vendas = fopen("..\\exportacao_vendas.txt", "w");
    if (arquivo_vendas == NULL)
    {
        printf("Impossivel criar arquivo!");
    }
    else
    {
        fprintf(arquivo_vendas, "%d\n", tl_vendas);
        for (int i = 0; i < tl_vendas; i++)
        {
            fprintf(arquivo_vendas, "%d ", tab_vendas[i].dia);
            fprintf(arquivo_vendas, "%d ", tab_vendas[i].mes);
            fprintf(arquivo_vendas, "%d\n", tab_vendas[i].ano);
            fprintf(arquivo_vendas, "%d ", tab_vendas[i].qtd);
            fprintf(arquivo_vendas, "%.2f ", tab_vendas[i].valor);
            fprintf(arquivo_vendas, "%d\n", tab_vendas[i].codigo);
        }
    }
    fclose(arquivo_vendas);
}

void importar_vendas(struct S_Vendas tab_vendas[], int *tl){

    FILE *arquivo_vendas;

    arquivo_vendas = fopen("..\\importar_vendas.txt", "r");
    if (arquivo_vendas == NULL)
    {
        printf("\nImpossivel abrir o arquivo!");
    }
    else
    {
        fscanf(arquivo_vendas, "%d", &(*tl));
        for (int i = 0; i < (*tl); i++)
        {
            fscanf(arquivo_vendas, "%d ", &tab_vendas[i].dia);
            fscanf(arquivo_vendas, "%d ", &tab_vendas[i].mes);
            fscanf(arquivo_vendas, "%d\n", &tab_vendas[i].ano);
            fscanf(arquivo_vendas, "%d ", &tab_vendas[i].qtd);
            fscanf(arquivo_vendas, "%f ", &tab_vendas[i].valor);
            fscanf(arquivo_vendas, "%d\n", &tab_vendas[i].codigo);
        }       
    }
    fclose(arquivo_vendas);
}

void quantidade_indisponivel(){
    printf("\n====Quantidade indisponivel!!====\n");
}

void apresentar_padrao(){
    printf("\nSem Movimentacoes!!!\n");
}

int ler_dia(){
    int dia;

    do{
        printf("Digite o dia:(DD) ");
        scanf("%d", &dia);
    }while(dia > 31 || dia < 1);

    return dia;
}

int ler_ano(){
    int ano;

    printf("Digite o ano:(AAAA) ");
    scanf("%d", &ano);

    return ano;
}

int ler_mes(){
    int mes;

    do{
        printf("Digite o mes:(MM) ");
        scanf("%d", &mes);
    }while(mes < 1 || mes > 12);

    return mes;
}

int ler_qtd_venda(){
    int qtd;

    printf("Digite a quantidade produtos que deseja comprar: ");
    fflush(stdin); 
    scanf("%d", &qtd);

    return qtd;
}


int validar_venda(struct S_Produtos tab_produtos[], int tl_produtos, int cod, int quantidade){
    int pos, controle = -1;

    pos = localizar_posicao(cod, tab_produtos, tl_produtos);
    if(pos >= 0){
        if (quantidade <= tab_produtos[pos].estoque)
        {
            tab_produtos[pos].estoque -= quantidade;
        }
       else
       {
        quantidade_indisponivel();
        controle = 1;
       }
        
    }
    return controle;
}

float valor_venda(int quantidade, int cod, int tl_produtos, struct S_Produtos tab_produtos[]){
    int posicao, venda = 0;

    posicao = localizar_posicao(cod, tab_produtos, tl_produtos);
    venda = (tab_produtos[posicao].preco*quantidade);

    return venda;
}

void incluir_venda(struct S_Vendas tab_vendas[], struct S_Produtos tab_produtos[], int tl_produtos, int *tl_vendas)
{
    int cod, codvalido, quantidade, venda_valida = -1;

    tab_vendas[*tl_vendas].dia = ler_dia();
    tab_vendas[*tl_vendas].mes = ler_mes();
    tab_vendas[*tl_vendas].ano = ler_ano();
    do
    {
       cod = ler_codigo();
       codvalido = validar_codigoV(cod, tab_produtos, tl_produtos);
    } while (codvalido > 0);
    if (codvalido == -1)
    {
       do
       {
        quantidade = ler_qtd_venda();
        venda_valida = validar_venda(tab_produtos, tl_produtos, cod, quantidade);
        if (venda_valida == -1)
        {
            printf("\nvalor total da venda...: R$ %.2f\n", valor_venda(quantidade, cod, tl_produtos, tab_produtos));
            tab_vendas[*tl_vendas].qtd = quantidade;
            tab_vendas[*tl_vendas].codigo = cod;
            tab_vendas[*tl_vendas].valor = valor_venda(quantidade, cod, tl_produtos, tab_produtos);
            (*tl_vendas)++;
        }
       } while (venda_valida == 1);
    }
}

int validar_codigo_venda(int tl_vendas, struct S_Vendas tab_vendas[], int cod){
    int controle = 1;

    for (int i = 0; i <= tl_vendas; i++)
    {
        if (tab_vendas[i].codigo == cod)
        {
            controle = -1;
            i = tl_vendas;
        }
    }
    
    return controle;
}

float calcular_total_venda(float valor){
    float total = 0;

    total += valor;

    return total;
}

void apresentar_total_venda(float valor){
    printf("\nValor total da venda....: R$%.2f\n", valor);
}

void apresentar_vendas_codigo(int tl_vendas, struct S_Vendas tab_vendas[], int cod){
    float total = 0;

    for (int i = 0; i <= tl_vendas; i++)
    {
        if (tab_vendas[i].codigo == cod)
        {
            printf("\n=====================================\n");
            printf("\nData venda....: %d/%d/%d", tab_vendas[i].dia, tab_vendas[i].mes, tab_vendas[i].ano);
            printf("\nCodigo........: %03d", tab_vendas[i].codigo);
            printf("\nQuantidade....: %d", tab_vendas[i].qtd);
            printf("\nValor total...: R$%.2f", tab_vendas[i].valor);
            total += calcular_total_venda(tab_vendas[i].valor);
        }
    }
    apresentar_total_venda(total);
}

void localizar_venda_pelo_codigo(int tl_vendas, struct S_Vendas tab_vendas[]){
    int cod, codvalido;

    do{
        cod = ler_codigo();
        codvalido = validar_codigo_venda(tl_vendas, tab_vendas, cod);
        if (codvalido > 0)
        {
            apresentar_padrao();
        }
        
    }while(codvalido > 0);
    if (codvalido == -1){
        apresentar_vendas_codigo(tl_vendas, tab_vendas, cod);
    }    
}

void apresentar_venda_data(int i, struct S_Vendas tab_vendas[]){

    printf("\n=====================================\n");
    printf("\nData venda....: %d/%d/%d", tab_vendas[i].dia, tab_vendas[i].mes, tab_vendas[i].ano);
    printf("\nCodigo........: %03d", tab_vendas[i].codigo);
    printf("\nQuantidade....: %d", tab_vendas[i].qtd);
    printf("\nValor total...: R$%.2f", tab_vendas[i].valor);
}

void localizar_venda_pela_data(int tl_vendas, struct S_Vendas tab_vendas[]){
    int dia, mes, ano;
    int controle = -1;
    float total = 0;

    dia = ler_dia();
    mes = ler_mes();
    ano = ler_ano();

    for ( int i = 0; i <= tl_vendas; i++)
    {
        if (dia == tab_vendas[i].dia && mes == tab_vendas[i].mes && ano == tab_vendas[i].ano)
        {
            apresentar_venda_data(i, tab_vendas);
            total += calcular_total_venda(tab_vendas[i].valor);
            controle = 1;
        }
    }
    if (controle == -1)
    {
        apresentar_padrao();
    }
    
    apresentar_total_venda(total);
}

void apresentar_vendas_quantidade(int quantidade, struct S_Produtos tab_produtos[], int i){

    printf("\n======================================\n");
    printf("\nCodigo.................: %03d", tab_produtos[i].cod);
    printf("\nNome...................: %s", tab_produtos[i].nome);
    printf("\nQuantidade Vendida.....: %d", quantidade);
}



void apresentar_todas_vendas(int tl_produtos, int tl_vendas, struct S_Produtos tab_produtos[], struct S_Vendas tab_vendas[]){
    int quantidade = 0;    

    for (int i = 0; i < tl_produtos; i++)
    {
        for (int j = 0; j < tl_vendas; j++)
        {
            if (tab_produtos[i].cod == tab_vendas[j].codigo)
            {
                quantidade += tab_vendas[j].qtd;
            }
        }
        apresentar_vendas_quantidade(quantidade, tab_produtos, i);
        quantidade = 0;
    }
}

void apresentar_total_mes(float total){
    float valor;

    valor = total;
    printf("\n=============================");
    printf("\nTotal arrecadado...: R$%.2f\n", valor);
}

void total_arrecado_mes(int tl_vendas, struct S_Vendas tab_vendas[]){
    int mes, controle = -1;
    float total = 0;

    mes = ler_mes();
    for (int i = 0; i <= tl_vendas; i++)
    {
        if (mes == tab_vendas[i].mes)
        {
            total += tab_vendas[i].valor;
            controle = 1;
        }
    }
    if (controle == 1)
    {
        apresentar_total_mes(total);
    }
    else
    {
        apresentar_padrao();
    }
}

void excluir_posicao(int posicao, struct S_Produtos tab_produtos[], int *tl_produtos){
    int i;

    if (posicao != -1)
    {
        for (i = posicao; i < *tl_produtos; i++)
        {
            tab_produtos[i] = tab_produtos[i + 1];
        }
        printf("\n====Produto Excluido com Sucesso!!====\n");
    }
}

void excluir_produto_nvendido(int *tl_produtos, struct S_Produtos tab_produtos[], int tl_vendas, struct S_Vendas tab_vendas[]){
    int cod, codvalido, validar_venda, posicao;

    do
    {
        cod = ler_codigo();
        codvalido = validar_codigoV(cod, tab_produtos, &tl_produtos);
        validar_venda = validar_codigo_venda(tl_vendas, tab_vendas, cod);
    } while (codvalido > 0);
    if (codvalido == -1 && validar_venda == 1)
    {
        posicao = localizar_posicao(cod, tab_produtos, tl_produtos);
        excluir_posicao(posicao, tab_produtos, tl_produtos);
        (*tl_produtos)--;
    }
    else
    {
        produto_vendido();
    }
}