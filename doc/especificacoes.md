Cargos:

- Recepcionista
- Auxiliar de Limpeza
- Garçom
- Gerente

Controle de:

- Cliente
- Estadia
- Funcionário

**Problema: um mesmo quarto é reservado para mais de um cliente.**

DESEJA-SE

Cadastrar: 

- Funcionários
- Estadias de hotel
- Clientes

Informações a serem cadastradas:

- ` `Cliente 
  - Código
  - Nome
  - Endereço
  - Telefone.
- Funcionário
  - Código
  - Nome
  - Telefone
  - Cargo
  - Salário
- Estadia
  - Código da estadia
  - Data de entrada
  - Data de saída
  - Quantidade de diárias
  - Código do cliente
  - Número do quarto

- Quarto
  - Número do quarto
  - Quantidade de hóspedes
  - Valor diária
  - Status	\_\_\_\_\_\_\_\_ Ocupado

    `		`|\_\_ Desocupado


Requisitos:

- Para cadastrar uma estadia, é preciso que o CLIENTE e o 	QUARTO estejam CADASTRADOS.
- As estadias devem ser cadastradas apenas para quartos com status desocupados.
- Não devem ser feitas mais de uma estadia para um mesmo quarto em um mesmo período (data de entrada, data de saída).
  - **Início da diária: 14 horas do dia atual**
  - **Fim da diária: 12 horas do dia seguinte**

**	Implementações principais:

- Função de **cadastro de cliente** - garantir que não há mais de um cliente com o mesmo código.
- Função de **cadastro de funcionário** - garantir que não há mais de um cliente com o mesmo código.
- Função de **cadastro de estadia** - o sistema deve receber do usuário:
  - O código do cliente que deseja se hospedar;
  - Quantidade de hóspedes;
  - Data de entrada
  - Data de saída.

A partir dessas informações, o sistema deve encontrar um quarto que esteja disponível para quantidade de hóspedes desejados.

`	`A quantidade de diárias deverá ser calculada com base na data de entrada e saída.

- Função que **dê baixa em uma determinada estadia**, **calcule** e **mostre o valor total a ser pago por um determinado cliente.**

`	`**Alterar o status para desocupado.**

- Funções que realizam pesquisa tanto para clientes quanto para funcionários. Ao digitar o nome ou código, apresenta na tela todas as informações do cliente ou funcionário.
- Função que mostre na tela todas as estadias de um determinado cliente(histórico).

  Na main, testar o sistema acima:

Opção de:

- Cadastrar um cliente;
- Funcionário;
- Estadia;
- Realizar pesquisas

Deve ficar em loop até o usuário selecionar a opção de SAIR.

Todas as informações deverão ser armazenadas em arquivos. Realizar leitura e escrita em arquivos.
