#include <stdio.h>
#include <stdlib.h>

struct S_Produtos
{
    int cod;
    char nome[50];
    float preco;
    int estoque;
};

void exportar_produtos(struct S_Produtos tab_produtos[], int tl){
    FILE *arquivo_produtos;

    arquivo_produtos = fopen("..\\exportacao_produtos.txt", "w");
    if (arquivo_produtos == NULL)
    {
        printf("Impossivel criar arquivo!");
    }
    else
    {
        fprintf(arquivo_produtos, "%d\n", tl);
        for (int i = 0; i < tl; i++)
        {
            fprintf(arquivo_produtos, "%03d\n", tab_produtos[i].cod);
            fprintf(arquivo_produtos, "%s\n", tab_produtos[i].nome);
            fprintf(arquivo_produtos, "%.2f ", tab_produtos[i].preco);
            fprintf(arquivo_produtos, "%d\n", tab_produtos[i].estoque);
        }
    }
    fclose(arquivo_produtos);
} 

void importar_produtos(struct S_Produtos tab_produtos[], int *tl){
    FILE *arquivo_prod;

    arquivo_prod = fopen("..\\importar_produtos.txt", "r");
    if (arquivo_prod == NULL)
    {
        printf("\nImpossivel abrir o arquivo!");
    }
    else
    {
        fscanf(arquivo_prod, "%d", &(*tl));
        for (int i = 0; i < (*tl); i++)
        {
            fscanf(arquivo_prod, "%d", &tab_produtos[i].cod);
            fscanf(arquivo_prod, " %[^\n]", tab_produtos[i].nome);
            fscanf(arquivo_prod, "%f", &tab_produtos[i].preco);
            fscanf(arquivo_prod, "%d", &tab_produtos[i].estoque);
        }       
    }
    fclose(arquivo_prod);
}

void codigo_n_encontrado(){
    printf("\nCodigo nao encontrado!!!\n");
}

int localizar_posicao(int cod, struct S_Produtos tab_produtos[], int tl_produtos){
    int posicao;

    for (int i = 0; i < tl_produtos; i++)
    {
        if (tab_produtos[i].cod == cod)
        {
            posicao = i;
            i = tl_produtos;
        }
    }
    return posicao;
}

// Incluir_Produto()
void ler_nome(struct S_Produtos tab_produtos[], int tl_produtos){
    fflush(stdin);
    printf("Digite o nome do produto: ");
    gets(tab_produtos[tl_produtos].nome);
}

float ler_Preco(){
    float preco;

    printf("Digite o valor...: ");
    fflush(stdin);
    scanf("%f", &preco);

    return preco;
}

int ler_estoque(){
    int estoque;

    printf("Digite o valor do estoque...: ");
    fflush(stdin);
    scanf("%d", &estoque);

    return estoque;
}

int validar_codigo(int codigo, struct S_Produtos tab_produtos[], int *tl_produtos){
    int i, controle = 1;

    for ( i = 0; i <= *tl_produtos; i++)
    {
        if (tab_produtos[i].cod == codigo)
        {
            controle = -1;
            printf("Codigo invalido!!\n");
            i = *tl_produtos;
        }
    }
    return controle;
}

int validar_codigoV(int codigo, struct S_Produtos tab_produtos[], int tl_produtos){
    int i, controle = 1;

    for ( i = 0; i <= tl_produtos; i++)
    {
        if (tab_produtos[i].cod == codigo)
        {
            controle = -1;
            printf("\nCodigo Encontrado!!\n");
            i = tl_produtos;
        }
    }
    return controle;
}

int ler_codigo(){
    int cod;

    do{
        printf("Digite o codigo do produto: ");
        scanf("%d", &cod);
    }while(cod < 1);
    return cod;
}
// Incluir_Produto()
void incluir_produtos(int *tl_produtos, struct S_Produtos tab_produtos[]){
    int cod;
    int codvalido;
    
    do{
        cod = ler_codigo();
        codvalido = validar_codigo(cod, tab_produtos, tl_produtos);
    }while(codvalido < 0);
    if(codvalido == 1){
        tab_produtos[*tl_produtos].cod = cod;
        ler_nome(tab_produtos, (*tl_produtos));
        tab_produtos[*tl_produtos].preco = ler_Preco();
        tab_produtos[*tl_produtos].estoque = ler_estoque();
        (*tl_produtos)++;
    }
}

// Alterar_Produto

int verificar_codigo(int tl_produtos, struct S_Produtos tab_produtos[]){
    int codigo, posicao = -1;

    codigo = ler_codigo();
    
    for (int i = 0; i < tl_produtos; i++)
    {
        if (tab_produtos[i].cod == codigo)
        {
            posicao = i;
            i = tl_produtos;
        }
    }
    
    return posicao;
}

void alterar_produto(int tl_produtos, struct S_Produtos tab_produtos[]){
    int posicao;

    posicao = verificar_codigo(tl_produtos, tab_produtos);
    if (posicao >= 0)
    {
        ler_nome(tab_produtos, posicao);
        tab_produtos[posicao].preco = ler_Preco();
        tab_produtos[posicao].estoque = ler_estoque();
    }
    else
    {
        codigo_n_encontrado();
    }
}
// pesquisar codigo
void apresentar_codigo_especifico(int posicao, struct S_Produtos tab_produtos[]){

    printf("\n---------------Produto Encontrado----------------");
    printf("\nCodigo......: %03d", tab_produtos[posicao].cod);
    printf("\nNome........: %s", tab_produtos[posicao].nome);
    printf("\nPreco.......: R$ %.2f", tab_produtos[posicao].preco);
    printf("\nEstoque.....: %d", tab_produtos[posicao].estoque);
    printf("\n---------------------------------------------------\n");
}

void pesquisar_codigo(int tl_produtos, struct S_Produtos tab_produtos[]){
    int codigo;
    
    codigo = verificar_codigo(tl_produtos, tab_produtos);
    if (codigo >= 0)
    {
        apresentar_codigo_especifico(codigo, tab_produtos);
    }
    else
    {
        codigo_n_encontrado();
    }
    
}
// aumentar estoque
void comprar_produto(int tl_produtos, struct S_Produtos tab_produtos[]){
    int codigo;

    codigo = verificar_codigo(tl_produtos, tab_produtos);
    if (codigo >= 0)
    {
        tab_produtos[codigo].estoque += ler_estoque();
    }
    else
    {
        codigo_n_encontrado();
    }
    
}
// imprimir produtos
void apresentar_produtos(int tl_produtos ,struct S_Produtos tab_produtos[]){
    int i;

    printf("\n===============Dados dos Produtos=============\n");
    for ( i = 0; i < tl_produtos; i++)
    {
        printf("\nCodigo........: %03d", tab_produtos[i].cod);
        printf("\nNome Produto..: %s", tab_produtos[i].nome);
        printf("\nPreco.........: R$ %.2f", tab_produtos[i].preco);
        printf("\nEstoque.......: %d", tab_produtos[i].estoque);
        printf("\n==============================================\n");
    } 
}

float valor_estoque_por_produto(int i, struct S_Produtos tab_produtos[]){
    float valor = 0;

    valor += (tab_produtos[i].estoque*tab_produtos[i].preco);

    return valor;
}

float valor_estoque(int i, struct S_Produtos tab_produtos[]){
    float total = 0;

    total += valor_estoque_por_produto(i, tab_produtos);

    return total;
}
// estoque
void balancete(int tl_produtos, struct S_Produtos tab_produtos[]){
    int i;
    float valor = 0;

    for ( i = 0; i < tl_produtos; i++)
    {
        printf("\nCodigo........: %03d", tab_produtos[i].cod);
        printf("\nNome Produto..: %s", tab_produtos[i].nome);
        printf("\nPreco.........: R$ %.2f", tab_produtos[i].preco);
        printf("\nEstoque.......: %d", tab_produtos[i].estoque);
        printf("\nValor estoque.: R$ %.2f", valor_estoque_por_produto(i, tab_produtos));
        printf("\n======================================\n");
        valor += valor_estoque(i, tab_produtos);
    }
    printf("Total em estoque....: %.2f", valor);
}

void apresentar_produtos_estoque_baixo(int tl_produtos, struct S_Produtos tab_produtos[]){
    int i, controle = 1;

    for ( i = 0; i < tl_produtos; i++)
    {
        if (tab_produtos[i].estoque < 5)
        {
            apresentar_codigo_especifico(i, tab_produtos);
            controle = -1;
        } 
    }
    if (controle > 0)
    {
        printf("\n=====Nenhum Produto encontrado!!!=====\n");
    }
}

void produto_vendido(){
    printf("\n===O produto nao pode ser excluido!!!===\n");
}