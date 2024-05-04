#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Produtos.h"
#include "Vendas.h"

#define TFP 30
#define TFV 100
#define clear system("cls");


void menu(struct S_Produtos tab_produtos[], int tl_produtos, struct S_Vendas tab_vendas[], int tl_vendas)
{
    char opcao;
    int escolha;


    do
    {
        clear;

        printf("\n___  ___                       _ _       _ \n");          
        printf("|  \\/  |                      | (_)     | |\n");          
        printf("| .  . | ___ _ __ ___ __ _  __| |_ _ __ | |__   ___\n");  
        printf("| |\\/| |/ _ \\ '__/ __/ _` |/ _` | | '_ \\| '_ \\ / _ \\ \n");
        printf("| |  | |  __/ | | (_| (_| | (_| | | | | | | | | (_) |\n");
        printf("\\_|  |_/\\___|_|  \\___\\__,_|\\__,_|_|_| |_|_| |_|\\___/\n");
                                                     
        printf("\n====================Menu de opcoes====================\n");
        printf("\n1 - Inclusao de produtos");
        printf("\n2 - Alterar dado de um produto");
        printf("\n3 - Exclusao de um produto, que nao tenha sido vendido");
        printf("\n4 - Pesquisar produto pelo codigo");
        printf("\n5 - Adicionar estoque comprado");
        printf("\n6 - Apresentar todos os produtos");
        printf("\n7 - Balancete do estoque");
        printf("\n8 - Produtos com estoque baixo");
        printf("\n9 - Venda de produto");
        printf("\n10 - Historico de venda de um produto");
        printf("\n11 - Historico de venda de uma data");
        printf("\n12 - Apresentar quantidade de venda de cada um dos produtos");
        printf("\n13 - Total arrecado em um determinado mes");
        printf("\n14 - Importar produtos e vendas!");
        printf("\n15 - Exportar produtos e vendas!");
        printf("\n16 - Fechar Programa!");

        printf("\nEscolha a opcao desejada.... \n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (tl_produtos < TFP)
            {
                incluir_produtos(&tl_produtos, tab_produtos);
            }
            else
            {
                printf("\nLimite de produtos alcancado!!");
            }
            break;
        case 2:
            alterar_produto(tl_produtos, tab_produtos);
            break;
        case 3:
            excluir_produto_nvendido(&tl_produtos, tab_produtos, tl_vendas, tab_vendas);
            break;
        case 4:
            pesquisar_codigo(tl_produtos, tab_produtos);
            break;
        case 5:
            comprar_produto(tl_produtos, tab_produtos);
            break;
        case 6:
            apresentar_produtos(tl_produtos, tab_produtos);
            break;
        case 7:
            balancete(tl_produtos, tab_produtos);
            printf("tl vendas: %d", tl_vendas);
            break;
        case 8:
            apresentar_produtos_estoque_baixo(tl_produtos, tab_produtos);
            break;
        case 9:
            if (tl_vendas < TFV)
            {
                incluir_venda(tab_vendas, tab_produtos, tl_produtos, &tl_vendas);
            }
            else
            {
                printf("\nLimite de vendas alcancado!!");
            }
            break;
        case 10:
            if (tl_vendas < 1)
            {
                printf("\nAinda nao ha vendas registradas!!!");
            }
            else
            {
                localizar_venda_pelo_codigo(tl_vendas, tab_vendas);
            }
            break;
        case 11:
            if (tl_vendas < 1)
            {
                printf("\nAinda nao ha vendas registradas!!!");
            }
            else
            {
                localizar_venda_pela_data(tl_vendas, tab_vendas);
            }
            break;
        case 12:
            apresentar_todas_vendas(tl_produtos,tl_vendas,tab_produtos,tab_vendas);
            break;
        case 13:
            if (tl_vendas < 1)
            {
                printf("\nSem Movimentacoes!!");
            }  
            else
            {
                total_arrecado_mes(tl_vendas, tab_vendas);
            }         
            break;
        case 14:
            importar_produtos(tab_produtos, &tl_produtos);
            importar_vendas(tab_vendas, &tl_vendas);
            break;
        case 15:
            exportar_produtos(tab_produtos, tl_produtos);
            exportar_vendas(tab_vendas, tl_vendas);
            break;
        case 16:
            printf("\nPrograma Encerrando....");
            break;
        default:
            printf("\nOpcao invalida!!!!\n");
            break;
        }

        if (escolha != 16)
        {
            printf("\nDeseja continuar e voltar ao menu? (S/N)\n");
            fflush(stdin);
            scanf("%c", &opcao);
        }

    } while ((opcao != 'n' && opcao != 'N') && escolha != 16);
}

void main(){
    int tl_produtos = 0, tl_vendas = 0;

    struct S_Produtos tab_produtos[TFP];
    struct S_Vendas tab_vendas[TFV];

    menu(tab_produtos, tl_produtos, tab_vendas, tl_vendas);


}