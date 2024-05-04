#include <stdio.h>
#include <stdlib.h>
#include "Tecnico.h"
#include "Equipamento.h"
#include "Manutencao.h"
#define pause system("\n\npause");
#define n printf("\n");

/* Authors
Guilherme Moraes - PE3021882
Larissa Biliazzi - PE3022111
*/

void main(){

    int escolha;
    Tecnico funcionario;
    Equipamento maquina;
    Manutencao chamado;

    do
    {
        system("cls");
        printf("\n========Controle de Manutencoes!========");
        printf("\n\n1 - Incluir novos tecnicos");
        printf("\n2 - Incluir novos equipamentos");
        printf("\n3 - Apresentar lista de equipamentos");
        printf("\n4 - Abrir novo chamado de atendimento");
        printf("\n5 - Apresentar atendimentos de um determinado tecnico");
        printf("\n6 - Apresentar quantidade de atendimentos de um laboratorio");
        printf("\n7 - Apresentar equipamentos em manutencao");
        printf("\n8 - Fechamento de um atendimento");
        printf("\n9 - Apresentar historico de um equipamento");
        printf("\n10 - Manutencoes realizadas em um determinado mes");
        printf("\n11 - Total de manutencoes de todos os equipamentos");
        printf("\n12 - Fechar programa");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &escolha);

        while (escolha < 1 || escolha > 12)
        {
            printf("\nOpcao invalida !!! Digite novamente: ");
            scanf("%d", &escolha);
        }
        
        switch (escolha)
        {
        case 1:
            funcionario = leitura_tecnico();
            incluir_dados_tecnico(funcionario);
            break;
        case 2:
            maquina = leitura_equipamento();
            incluir_dados_equipamento(maquina);
            break;
        case 3:
            if (existe_equipamento())
            {
                apresentar_lista_equipamentos();
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 4:
            if (existe_equipamento())
            {
                chamado = leitura_chamado();
                abrir_chamado(chamado);
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 5:
            if(existe_tecnico()){
            atendimentos_tecnico();
            }
            else
            {
                padrao();
            }
            n;
            pause;
            break;
        case 6:
            if (existe_equipamento())
            {
                verifica_lab();
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 7:

            if (existe_manutencao())
            {
                localizar_manutencao_equipamento();
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 8:
            if (existe_equipamento())
            {
                leitura_fechamento();
            }
            else
            {
                padrao();
            }
            n;
            pause;
            break;
        case 9:
            if (existe_manutencao())
            {
                historico_atendimento_equipamento();
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 10:
            if (existe_manutencao())
            {
               historico_atendimento_mes(); 
            }
            else
            {
                padrao();
            }
            pause;
            break;
        case 11:
            if (existe_equipamento())
            {
                contabilizar_cod();
            }
            else
            {
                padrao();
            }
            pause;
            break;
        default:
            break;
        }

    } while (escolha != 12);
}