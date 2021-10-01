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

#define EXIT 10

typedef struct {
	int day;
	int month;
} Date;

struct REC {
    char nome[50];
    int prioridade;
    Date entrega; 
    struct REC *next;
    struct REC *prev;
};

typedef struct REC Task;

typedef struct
{
    Task *head;
    Task *tail;
} ToDoList;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op = 0;

    printf("\n%d Finaliza", EXIT);
    printf("\n: ");
    scanf("%d",&op);

    return op;
}

void initToDoList(ToDoList *toDoList)
{
    toDoList->head = NULL;
    toDoList->tail = NULL;
}

Task *createTask() 
{
    Task *task = (Task *)malloc(sizeof(Task));

    printf("\nDigite os dados da nova tarefa:\n");

    printf("\nNome: ");
    scanf("%s", task->nome);

    printf("Prioridade: ");
    scanf("%d", &task->prioridade);

    printf("Entrega (dd/MM): ");
    scanf("%d/%d", &task->entrega.day, &task->entrega.month);

    task->prev = NULL;
    task->next = NULL;

    return task;
}

// Permite o cadastro de uma tarefa
void insTask(ToDoList *tasksList)
{
    Task *task = createTask();

    if (task == NULL) {
        return;
    }

    // se não houver nenhuma tarefa registrada ainda
    if (tasksList->head == NULL) 
    {
        tasksList->head = task;
        tasksList->tail = task;
    }
    else 
    {
        tasksList->tail->next = task;
        task->prev = tasksList->tail;
        tasksList->tail = task;
    }

    printf("\nTarefa adicionada!\n");
}

// Permite excluir uma tarefa
void delTask()
{
    return;
}

void printTask(Task *task) 
{
    printf("\n-> Nome: %s\n   Prioridade: %d\n   Entrega: %d/%d\n", 
            task->nome, task->prioridade, task->entrega.day, task->entrega.month);
}

// Lista o conteudo da lista de tarefas (todos os campos)
void listTasks(ToDoList *toDoList)
{
    printf("\nLista de Tarefas\n----------------\n");

    for (Task *task = toDoList->head; task != NULL; task = task->next)
    {
        printTask(task);
    } 
}

// Permite consultar uma tarefa da lista pelo nome
void querytask()
{
    return;
}

// Permite a atualização dos dados de uma tarefa
void upTask()
{
    return;
}

// Programa principal
int main()
{
    ToDoList toDoList;
    initToDoList(&toDoList);

    int op = 0;
    
    while (op!=EXIT)
    {
        op = menu();

        switch(op)
        {
            case 1 : 
                insTask(&toDoList);
                break;

            // case 2 : delTask();
            // case 3 : upTask();
            // case 4 : queryTask();
            case 5 : 
                listTasks(&toDoList);
                break;
        }
    }
}