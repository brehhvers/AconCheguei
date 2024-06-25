/*********************************************************
* NOME DO ARQUIVO : funcoes-cadastro.h
* DESCRI��O : Bliblioteca de fun��es usadas para realizar
* cadastros.
* FUN��ES P�BLICAS :
*
* NOTAS :
* Estas fun��es est�o sendo usadas no arquivo
* "main.c".
*
* AUTOR : Brenda Evers
* DATA DE IN�CIO : 24 Jun 2024
*********************************************************/

#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes-cadastro.h"

void cadastrarCliente() {
    structCliente cliente;

    printf("Codigo do cliente: ");
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
}
