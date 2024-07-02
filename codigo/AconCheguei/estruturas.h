/*********************************************************
* NOME DO ARQUIVO : estruturas.h
* DESCRIÇÃO : Declaração de estruturas
* NOTAS :
* Estas estruturas estão sendo usadas no arquivo
* "funcoes-cadastro.h".
* AUTOR : Brenda Evers
* DATA DE INÍCIO : 24 Jun 2024
*********************************************************/
#include <time.h>

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
    int numeroQuarto;
    int quantidadeHospedes;
    float precoDiaria;
    char status[20];
} structQuarto;


typedef struct {
    int codigoCliente;
    int codigoEstadia;
    int numeroQuarto;
    struct tm dataEntrada;
    struct tm dataSaida;
    int quantidadeDiarias;
} structEstadia;


#endif
