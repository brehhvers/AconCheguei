/*********************************************************
* NOME DO ARQUIVO : funcoes-cadastro.h
* DESCRIÇÃO : Biblioteca de funções usadas para realizar
* cadastros de clientes, funcionários e estadias.
* FUNÇÕES PÚBLICAS :
* - void cadastrarCliente(structCliente clientes[], int *numClientes)
* - void pesquisarCliente(structCliente clientes[], int numClientes)
* - void salvarClientes(structCliente clientes[], int numClientes)
* - void carregarClientes(structCliente clientes[], int *numClientes)
* - void salvarQuartos(structQuarto quartos[], int numQuartos)
* - void carregarQuartos(structQuarto quartos[], int *numQuartos)
* - void salvarEstadias(structEstadia estadias[], int numEstadias)
* - void carregarEstadias(structEstadia estadias[], int *numEstadias)
* - void listarEstadiaCliente(structEstadia estadias[], int numEstadias, int codigoCliente)
* - void baixaEstadia(structEstadia estadias[], int *numEstadias, structQuarto quartos[], int numQuartos)
* - void cadastrarEstadia(structEstadia estadias[], int *numEstadias, structQuarto quartos[], int numQuartos, structCliente clientes[], int numClientes)
* - void cadastrarFuncionario(structFuncionario funcionarios[], int *num_funcionarios)
* - void pesquisarFuncionario(structFuncionario funcionarios[], int num_funcionarios)
* - void salvarFuncionarios(structFuncionario funcionarios[], int num_funcionarios)
* - void carregarFuncionarios(structFuncionario funcionarios[], int *num_funcionarios)
*
* NOTAS :
* Estas funções estão sendo usadas no arquivo "main.c".
*
* AUTOR : Brenda Evers
* AUTOR : Gabriel Lacerda Lemos da Silva
* DATA DE INÍCIO : 24 Jun 2024
*********************************************************/


#include <stdio.h>
#include <string.h>
#include "funcoes-uteis.h"
#include "estruturas.h"
#include "funcoes-cadastro.h"



void cadastrarCliente(structCliente clientes[], int *numClientes) {
    structCliente novoCliente;
    printf("Digite o codigo do cliente: ");
    scanf("%d", &novoCliente.codigo);

    int i = 0;
    while (i < *numClientes) {
        if (clientes[i].codigo == novoCliente.codigo) {
            printf("Erro: Ja existe um cliente com esse codigo.\n");
            return;
        }
        i++;
    }

    printf("Digite o nome do cliente: ");
    scanf(" %s", novoCliente.nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %s", novoCliente.endereco);
    printf("Digite o telefone do cliente: ");
    scanf(" %s", novoCliente.telefone);

    clientes[*numClientes] = novoCliente;
    (*numClientes)++;
    printf("Cliente cadastrado com sucesso.\n");
}

void pesquisarCliente(structCliente clientes[], int numClientes) {
    int codigo;
    char nome[100];
    int opcao;

    printf("Pesquisar por: 1- Codigo 2- Nome: ");
    scanf("%d", &opcao);

    int i = 0;
    if (opcao == 1) {
        printf("Digite o codigo do cliente: ");
        scanf("%d", &codigo);
        while (i < numClientes) {
            if (clientes[i].codigo == codigo) {
                printf("Cliente encontrado:\n");
                printf("Codigo: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
                return;
            }
            i++;
        }
    } else if (opcao == 2) {
        printf("Digite o nome do cliente: ");
        scanf(" %s", nome);
        while (i < numClientes) {
            if (strcmp(clientes[i].nome, nome) == 0) {
                printf("Cliente encontrado:\n");
                printf("Codigo: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
                return;
            }
            i++;
        }
    }
    printf("Cliente não encontrado.\n");
}

void salvarClientes(structCliente clientes[], int numClientes) {
    FILE *file = fopen("clientes.dat", "wb");
    fwrite(&numClientes, sizeof(int), 1, file); // fwrite- escrever dados em um arquivo binário
   fwrite(clientes, sizeof(structCliente), numClientes, file); // sizeof- retorna o tamanho em bytes de um tipo de dado

    fclose(file);
}

void carregarClientes(structCliente clientes[], int *numClientes) {
    FILE *file = fopen("clientes.dat", "rb");
    if (file) {
        fread(numClientes, sizeof(int), 1, file); // fread- ler blocos de dados a partir de um arquivo
        fread(clientes, sizeof(structCliente), *numClientes, file);

        fclose(file); // fclose- fechar um arquivo que foi aberto anteriormente
    } else {
        *numClientes = 0;
    }
}
void salvarQuartos(structQuarto quartos[], int numQuartos) {
    FILE *file = fopen("quartos.dat", "wb");
    fwrite(&numQuartos, sizeof(int), 1, file);
    fwrite(quartos, sizeof(structQuarto), numQuartos, file);

    fclose(file);
}

void carregarQuartos(structQuarto quartos[], int *numQuartos) {
    FILE *file = fopen("quartos.dat", "rb");
    if (file) {
        fread(numQuartos, sizeof(int), 1, file);
        fread(quartos, sizeof(structQuarto), *numQuartos, file);

        fclose(file);
    } else {
        *numQuartos = 0;
    }
}

void salvarEstadias(structEstadia estadias[], int numEstadias) {
    FILE *file = fopen("estadias.dat", "wb");
    fwrite(&numEstadias, sizeof(int), 1, file);
    fwrite(estadias, sizeof(structEstadia), numEstadias, file);

    fclose(file);
}

void carregarEstadias(structEstadia estadias[], int *numEstadias) {
    FILE *file = fopen("estadias.dat", "rb");
    if (file) {
        fread(numEstadias, sizeof(int), 1, file);
        fread(estadias, sizeof(structEstadia), *numEstadias, file);
        fclose(file);
    } else {
        *numEstadias = 0;
    }
}


void listarEstadiaCliente(structEstadia estadias[], int numEstadias, int codigoCliente) {
    printf("Estadias do cliente %d:\n", codigoCliente);

    int i = 0;
    while (i < numEstadias) {
        if (estadias[i].codigoCliente == codigoCliente) {
            printf("Codigo da Estadia: %d\n",estadias[i].codigoEstadia);
            printf("Quarto: %d\n",estadias[i].numeroQuarto);
            printf("Data de Entrada: %02d/%02d/%04d %02d:%02d\n",estadias[i].dataEntrada.tm_mday,estadias[i].dataEntrada.tm_mon+ 1, estadias[i].dataEntrada.tm_year + 1900,estadias[i].dataEntrada.tm_hour, estadias[i].dataEntrada.tm_min);
            printf("Data de Saida: %02d/%02d/%04d %02d:%02d\n",estadias[i].dataSaida.tm_mday, estadias[i].dataSaida.tm_mon + 1, estadias[i].dataSaida.tm_year + 1900, estadias[i].dataSaida.tm_hour, estadias[i].dataSaida.tm_min);
            printf("Quantidade de Diarias: %d\n",estadias[i].quantidadeDiarias);
        }
        i++;
    }
}

void baixaEstadia(structEstadia estadias[], int *numEstadias, structQuarto quartos[], int numQuartos) {
    int codigoEstadia;
    printf("Digite o codigo da estadia: ");
    scanf("%d", &codigoEstadia);

    int i = 0;
    while (i < *numEstadias) {
        if (estadias[i].codigoEstadia == codigoEstadia) {
            int numeroQuarto = estadias[i].numeroQuarto;
            int quantidadeDiarias = estadias[i].quantidadeDiarias;
            float valorDiaria = 0;

            int j = 0;


            float valorTotal = quantidadeDiarias * valorDiaria;
            printf("Valor total a ser pago: Rs%.2f\n", valorTotal);

            int k = i;
            while (k < *numEstadias - 1) {
                estadias[k] = estadias[k + 1];
                k++;
            }
            (*numEstadias)--;
            printf("Estadia finalizada com sucesso.\n");
            return;
        }
        i++;
    }
    printf("Erro: Estadia nao encontrada.\n");
}

void cadastrarEstadia(structEstadia estadias[], int *numEstadias, structQuarto quartos[], int numQuartos, structCliente clientes[], int numClientes) {
    structEstadia novaEstadia;
    int codigoCliente, quantidadeHospedes;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    // Verifica se o cliente existe
    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Erro: Cliente nao cadastrado.\n");
        return;
    }

    printf("Digite a quantidade de hospedes: ");
    scanf("%d", &quantidadeHospedes);

    // Procura por um quarto disponível que acomode a quantidade de hospedes
    int quartoEncontrado = 0;
    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].quantidadeHospedes >= quantidadeHospedes && strcmp(quartos[i].status, "desocupado") == 0) {
            novaEstadia.numeroQuarto = quartos[i].numeroQuarto;
            strcpy(quartos[i].status, "ocupado");
            quartoEncontrado = 1;
            break;
        }
    }

    if (!quartoEncontrado) {
        printf("Erro: Nao ha quartos disponiveis para a quantidade de hospedes desejada.\n");
        return;
    }

    printf("Digite a data de entrada (dd mm yyyy hh mm): ");
    scanf("%d %d %d %d %d", &novaEstadia.dataEntrada.tm_mday, &novaEstadia.dataEntrada.tm_mon, &novaEstadia.dataEntrada.tm_year, &novaEstadia.dataEntrada.tm_hour, &novaEstadia.dataEntrada.tm_min);
    novaEstadia.dataEntrada.tm_mon -= 1;
    novaEstadia.dataEntrada.tm_year -= 1900;

    printf("Digite a data de saída (dd mm yyyy hh mm): ");
    scanf("%d %d %d %d %d", &novaEstadia.dataSaida.tm_mday, &novaEstadia.dataSaida.tm_mon, &novaEstadia.dataSaida.tm_year, &novaEstadia.dataSaida.tm_hour, &novaEstadia.dataSaida.tm_min);
    novaEstadia.dataSaida.tm_mon -= 1;
    novaEstadia.dataSaida.tm_year -= 1900;


    time_t entrada = mktime(&novaEstadia.dataEntrada);
    time_t saida = mktime(&novaEstadia.dataSaida);
    double segundos = difftime(saida, entrada);
    novaEstadia.quantidadeDiarias = (segundos / (60 * 60 * 24)) + 1;

    novaEstadia.codigoCliente = codigoCliente;
    novaEstadia.codigoEstadia = *numEstadias + 1;

    estadias[*numEstadias] = novaEstadia;
    (*numEstadias)++;

    printf("Estadia cadastrada com sucesso.\n");
}
void cadastrarFuncionario(structFuncionario funcionarios[], int *num_funcionarios) {
    structFuncionario novoFuncionario;
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &novoFuncionario.codigo);

    int i = 0;
    while (i < *num_funcionarios) {
        if (funcionarios[i].codigo == novoFuncionario.codigo) {
            printf("Erro: Ja existe um funcionario com esse codigo.\n");
            return;
        }
        i++;
    }

    printf("Digite o nome do funcionario: ");
    scanf(" %s", novoFuncionario.nome);
    printf("Digite o telefone do funcionario: ");
    scanf(" %s", novoFuncionario.telefone);
    printf("Digite o cargo do funcionario: ");
    scanf(" %s", novoFuncionario.cargo);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);

    funcionarios[*num_funcionarios] = novoFuncionario;
    (*num_funcionarios)++;
    printf("Funcionario cadastrado com sucesso.\n");
}

void pesquisarFuncionario(structFuncionario funcionarios[], int num_funcionarios) {
    int codigo;
    char nome[100];
    int opcao;

    printf("Pesquisar por: 1. Codigo 2. Nome: ");
    scanf("%d", &opcao);

    int i = 0;
    if (opcao == 1) {
        printf("Digite o codigo do funcionario: ");
        scanf("%d", &codigo);
        while (i < num_funcionarios) {
            if (funcionarios[i].codigo == codigo) {
                printf("Funcionario encontrado:\n");
                printf("Codigo: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalario: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
                return;
            }
            i++;
        }
    } else if (opcao == 2) {
        printf("Digite o nome do funcionario: ");
        scanf(" %s", nome);
        while (i < num_funcionarios) {
            if (strcmp(funcionarios[i].nome, nome) == 0) {
                printf("Funcionario encontrado:\n");
                printf("Codigo: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalario: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
                return;
            }
            i++;
        }
    }
    printf("Funcionario nao encontrado.\n");
}

void salvarFuncionarios(structFuncionario funcionarios[], int num_funcionarios) {
    FILE *file = fopen("funcionarios.dat", "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo funcionarios.dat");
        return;
    }

    fwrite(&num_funcionarios, sizeof(int), 1, file);
    fwrite(funcionarios, sizeof(structFuncionario), num_funcionarios, file);

    fclose(file);
}

void carregarFuncionarios(structFuncionario funcionarios[], int *num_funcionarios) {
    FILE *file = fopen("funcionarios.dat", "rb");
    if (file) {
        fread(num_funcionarios, sizeof(int), 1, file);
        fread(funcionarios, sizeof(structFuncionario), *num_funcionarios, file);

        fclose(file);
    } else {
        *num_funcionarios = 0;
    }
}


