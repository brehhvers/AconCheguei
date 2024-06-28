/*********************************************************
* NOME DO ARQUIVO : funcoes-cadastro.h
* DESCRIÇÃO : Bliblioteca de funções usadas para realizar
* cadastros.
* FUNÇÕES PÚBLICAS :
*
* NOTAS :
* Estas funções estão sendo usadas no arquivo
* "main.c".
*
* AUTOR : Brenda Evers
* AUTOR : Gabriel Lacerda Lemos da Silva
* DATA DE INÍCIO : 24 Jun 2024
*********************************************************/

#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes-cadastro.h"

void cadastrarCliente() {
    structCliente cliente;

    printf("\nCodigo do cliente: ");
    scanf("%d", &cliente.codigo);
    getchar();

    printf("Nome do cliente: ");
    fgets(cliente.nome, 80, stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = 0;

    printf("Endereco do cliente: ");
    fgets(cliente.endereco, 120, stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = 0;

    printf("Telefone do cliente: ");
    fgets(cliente.telefone, 20, stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = 0;

    FILE *file = fopen("cadastros.txt", "a");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }

    fprintf(file, "%d %s %s %s\n", cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone);
    fclose(file);

    printf("\n**Cadastrado com sucesso!**\n");
    printf("\n============================\n");
}

void cadastrarQuarto() {
    structQuarto quarto;

    printf("\nDigite o numero do Quarto: ");
    scanf("%d",&quarto.numero);

    printf("Digite a quantidade de hospedes: ");
    scanf("%d",&quarto.quantidadeHospedes);

    printf("Digite o valor da diaria: ");
    scanf("%f",&quarto.valorDiaria);

    quarto.status = 0;

    FILE *file = fopen("quartos.txt", "a");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }
    fprintf(file, "%d %d %.2f %d\n",quarto.numero, quarto.quantidadeHospedes, quarto.valorDiaria, quarto.status);
    fclose(file);

    printf("\n**Cadastrado com sucesso!**\n");
    printf("\n============================\n");
}
