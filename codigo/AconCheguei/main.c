#include <stdio.h>
#include "estruturas.h"
#include "funcoes-cadastro.h"
#include "funcoes-uteis.h"

int main()
{
    int opcao;

    do
    {
        printf("\n===Hotel Descanso Garantido===\n");
        printf("\n=====Menu Principal=====\n");
        printf("\nO que deseja escolher?\n");
        printf("\n1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionario\n");
        printf("3. Cadastrar Quarto (Estadia)\n");
        printf("4. Realizar Pesquisas\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            cadastrarCliente();
        }
        else if (opcao == 3)
        {
            cadastrarQuarto();
        }
        else
        {
            printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    }
    while (opcao!=5);

    return 0;
}
