/*********************************************************
* NOME DO ARQUIVO : estruturas.h
* DESCRI��O : Declara��o de estruturas
* NOTAS :
* Estas estruturas est�o sendo usadas no arquivo
* "funcoes-cadastro.h".
* AUTOR : Brenda Evers
* DATA DE IN�CIO : 24 Jun 2024
*********************************************************/

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int codigo;
    char nome[80];
    char endereco[120];
    char telefone[20];
} structCliente;

typedef struct {
    int codigo;
    char nome[80];
    char telefone[20];
    char cargo[15];
    float salario;
} structFuncionario;

typedef struct {
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    int status;
} structQuarto;

#endif
