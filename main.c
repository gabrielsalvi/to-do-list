/*
 Este é um esqueleto que deve ser utilzado como base para implementação da Lista de tarefas;
	- As funções não têm os parâmetros definidos; se necessário, estes devem ser incluídos;
 	- Devem ser respeitados os nomes atribuidos aos métodos e estruturas, porém, novas estruturas e funções podem ser criadas, caso julgue necessário;
	- Faça os includes necessários;
	- A organização das funções fica a critério do programador;
	- Códigos não indentados sofrerão duras penalidades;
	- Não serão toleradas variaveis globais;
	- Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 
#include <stdlib.h>

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month;
} Date;

// Estrutura que contém os campos dos registros das tarefas
struct REC {
    char nome[50];
    int prioridade;
    Date entrega; 
    struct REC *next; // implemente como lista, como árvore BST, AVL...
    struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op = 0;
    while (op != EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
       
    }
    return op;
}

// Permite o cadastro de uma tarefa
void insTask()
{
    return;
}

// Permite excluir uma tarefa
void delTask ()
{
    return;
}

// Lista o conteudo da lista de tarefas (todos os campos)
void listTasks ()
{
    return;
}

// Permite consultar uma tarefa da lista pelo nome
void querytask ()
{
    return;
}

// Permite a atualização dos dados de uma tarefa
void upTask ()
{
    return;
}

// Programa principal
int main()
{
    int op = 0;
    Task t;

    while (op!=EXIT)
    {
        op = menu();
        switch(op)
        {
            case 1 : insTask();
            case 2 : delTask();
            case 3 : upTask();
            case 4 : queryTask();
            case 5 : listTasks();
        }
    }
}