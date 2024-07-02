#include <stdio.h>
#include "estruturas.h"
#include "funcoes-cadastro.h"
#include "funcoes-uteis.h"
#include <time.h>
#ifndef MAIN_C
#define MAIN_C


int main()
{
    structCliente clientes[100];
    structFuncionario funcionarios[100];
    structEstadia estadias[100];
    structQuarto quartos[100];

    int num_clientes = 0, num_funcionarios = 0, num_estadias = 0, num_quartos = 0;

    carregarClientes(clientes, &num_clientes);
    carregarFuncionarios(funcionarios, &num_funcionarios);
    carregarEstadias(estadias, &num_estadias);
    carregarQuartos(quartos, &num_quartos);

    if (num_quartos == 0)
    {
        quartos[0].numeroQuarto = 101;
        quartos[0].quantidadeHospedes = 2;
        quartos[0].precoDiaria = 150.0;
        strcpy(quartos[0].status, "desocupado");

        quartos[1].numeroQuarto = 102;
        quartos[1].quantidadeHospedes = 3;
        quartos[1].precoDiaria = 200.0;
        strcpy(quartos[1].status, "desocupado");

        quartos[2].numeroQuarto = 103;
        quartos[2].quantidadeHospedes = 4;
        quartos[2].precoDiaria = 250.0;
        strcpy(quartos[2].status, "desocupado");

        num_quartos = 3;
    }

    int opcao;
    do
    {
        printf("\n===Hotel Descanso Garantido===\n");
        printf("\n=====Menu Principal=====\n");
        printf("\n1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionario\n");
        printf("3. Cadastrar Estadia\n");
        printf("4. Dar Baixa em Estadia\n");
        printf("5. Pesquisar Cliente\n");
        printf("6. Pesquisar Funcionario\n");
        printf("7. Listar Estadias de um Cliente\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n");
            cadastrarCliente(clientes, &num_clientes);
            printf("\n");
            salvarClientes(clientes, num_clientes);
            printf("\n");
            break;
        case 2:
            printf("\n");
            cadastrarFuncionario(funcionarios, &num_funcionarios);
            printf("\n");
            salvarFuncionarios(funcionarios, num_funcionarios);
            printf("\n");
            break;
        case 3:
            printf("\n");
            cadastrarEstadia(estadias, &num_estadias, clientes, num_clientes, quartos, num_quartos);
            printf("\n");
            salvarEstadias(estadias, num_estadias);
            printf("\n");
            salvarQuartos(quartos, num_quartos);
            break;
        case 4:
            printf("\n");
            baixaEstadia(estadias, &num_estadias, quartos, num_quartos);
            printf("\n");
            salvarEstadias(estadias, num_estadias);
            printf("\n");
            salvarQuartos(quartos, num_quartos);
            break;
        case 5:
            printf("\n");
            pesquisarCliente(clientes, num_clientes);
            printf("\n");
            break;
        case 6:
            printf("\n");
            pesquisarFuncionario(funcionarios, num_funcionarios);
            printf("\n");
            break;
        case 7:
        {
            int codigo_cliente;
            printf("\n");
            printf("Digite o codigo do cliente: ");
            scanf("%d", &codigo_cliente);
            printf("\n");
            listarEstadiaCliente(estadias, num_estadias, codigo_cliente);
            printf("\n");
            break;
        }
        case 8:
            printf("\n");
            printf("Saindo...\n");
            break;
        default:
            printf("\n");
            printf("Opcao invalida!\n");
            break;
        }
    }
    while (opcao != 8);

    return 0;
}

#endif
