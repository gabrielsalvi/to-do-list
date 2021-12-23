# To Do List

Esse repositório armazena a minha solução para o trabalho final de Pesquisa e Ordenação de Dados, cujo objetivo foi implementar um programa para gerenciar uma lista de tarefas a ser persistida em disco. 

## Funcionalidades

* Criar uma nova tarefa
* Deletar uma tarefa
* Atualizar os dados de uma tarefa
* Listar todas as tarefas em ordem alfabética
* Consultar uma tarefa pelo nome

## Organização dos Dados em Memória

Durante a execução do programa as tarefas são inseridas em uma lista duplamente encadeada - estrutura de dados onde cada elemento guarda o endereço de memória do seu elemento anterior e do seu próximo elemento.

## Persistência dos Dados

Na saída do programa, todos os dados em memória são persistidos em um arquivo de texto, assim, garantindo que os dados não sejam perdidos ao final de cada execução.

A partir desse arquivo gerado, ao executar o código novamente, o programa lê os dados do arquivo de texto, e se existirem, adiciona-os de volta na memória do computador.

## Listagem de Tarefas em Ordem Alfabética

O método de ordenação utilizado para realizar a listagem, em ordem alfabética, das tarefas presentes na lista foi o bubble sort. 

Esse método foi escolhido por ter uma fácil implementação, e, também, por se sair bem trabalhando com quantidades pequenas de dados. Visto que, muito provavelmente, o usuário não terá um número muito alto de tarefas cadastradas no sistema.