#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define EXIT 10

typedef struct {
	int day;
	int month;
} Date;

typedef struct {
    char nome[50];
    int prioridade;
    Date entrega;
} Info;

struct TSK
{
    Info *info;
    struct TSK *next;
    struct TSK *prev;
};

typedef struct TSK Task;

typedef struct
{
    Task *head;
    Task *tail;
} ToDoList;

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
    Info *info = (Info *)malloc(sizeof(Info));
    Task *task = (Task *)malloc(sizeof(Task));

    printf("\nDigite os dados da nova tarefa:\n");

    printf("\nNome: ");
    scanf("\n");
    fgets(info->nome, 50, stdin);
    info->nome[strcspn(info->nome, "\n")] = 0;

    printf("Prioridade (1- baixa; 2- média; 3- alta): ");
    scanf("%d", &info->prioridade);

    while (info->prioridade < 1 || info->prioridade > 3) {
        printf("\nDigite um valor válido para a prioridade: 1 (baixa), 2 (média) ou 3 (alta)\n");

        printf("\nPrioridade (1- baixa; 2- média; 3- alta): ");
        scanf("%d", &info->prioridade);
    }

    printf("Entrega (dd/mm): ");
    scanf("%d/%d", &info->entrega.day, &info->entrega.month);

    task->info = info;
    task->prev = NULL;
    task->next = NULL;

    return task;
}

Task *getTaskByName(ToDoList *toDoList, char *name) 
{
    for (Task *task = toDoList->head; task != NULL; task = task->next) 
    {
        if (strcmp(task->info->nome, name) == 0) {
            return task;
        }
    }

    return NULL;
}

void insTask(ToDoList *toDoList, Task *task)
{
    if (!task) {
        return;
    }

    if (toDoList->head == NULL) 
    {
        toDoList->head = task;
        toDoList->tail = task;
    }
    else 
    {
        toDoList->tail->next = task;
        task->prev = toDoList->tail;
        toDoList->tail = task;
    }
}

void delTask(ToDoList *toDoList, char *name)
{
    Task *task = getTaskByName(toDoList, name);

    if (task) 
    {
        if (toDoList->head == toDoList->tail)
        {
            initToDoList(toDoList);
        }
        else if (task == toDoList->head)
        {
            toDoList->head = toDoList->head->next;
            toDoList->head->prev = NULL;
        }
        else if (task == toDoList->tail)
        {
            toDoList->tail = toDoList->tail->prev;
            toDoList->tail->next = NULL;
        }
        else
        {
            task->prev->next = task->next;
            task->next->prev = task->prev;
        }

        free(task);
        printf("\nA tarefa '%s' foi excluída com sucesso!\n", name);
    } 
    else 
    {
        printf("\nA tarefa '%s' não foi encontrada!\n", name);
    }
}

void printTask(Task *task) 
{
    printf("\n-> Nome: %s\n   Prioridade: %d\n   Entrega: %d/%d\n", 
            task->info->nome, task->info->prioridade, task->info->entrega.day, task->info->entrega.month);
}

void swap(Task *a, Task *b) 
{
    Info *aux = a->info;

    a->info = b->info;
    b->info = aux;
}

void bubbleSort(Task *head, Task *tail)
{
    for (Task *task = tail; task != NULL; task = task->prev) 
    {
        for (Task *next = task->next; next != NULL; next = next->next) 
        {
            if (strcmp(task->info->nome, next->info->nome) > 0) 
            {
                swap(task, next);
            }
        }
    }
}

void listTasks(ToDoList toDoList)
{
    printf("\nLista de Tarefas\n----------------\n");

    bubbleSort(toDoList.head, toDoList.tail);

    for (Task *task = toDoList.head; task != NULL; task = task->next)
    {
        printTask(task);
    } 
}

void queryTask(ToDoList *toDoList, char *name)
{   
    Task *searchedTask = getTaskByName(toDoList, name);

    if (searchedTask) {
        printTask(searchedTask);
    } else {
        printf("\nA tarefa '%s' não foi encontrada!\n", name);
    }
}

void upTask(ToDoList *toDoList, char *name)
{
    Task *task = getTaskByName(toDoList, name);

    if (task)
    {
        printf("\nDados atuais da tarefa: \n");
        printTask(task);

        printf("\nPrioridade (1- baixa; 2- média; 3- alta): ");
        scanf("%d", &task->info->prioridade);

        while (task->info->prioridade < 1 || task->info->prioridade > 3) {
            printf("\nDigite um valor válido para a prioridade: 1 (baixa), 2 (média) ou 3 (alta)\n");

            printf("\nPrioridade (1- baixa; 2- média; 3- alta): ");
            scanf("%d", &task->info->prioridade);
        }

        printf("Entrega (dd/mm): ");
        scanf("%d/%d", &task->info->entrega.day, &task->info->entrega.month);

        printf("\nA tarefa '%s' doi atualizada com sucesso!\n", name);
    } 
    else 
    {
        printf("\nA tarefa '%s' não foi encontrada!\n", name);
    }
}

void readFile(FILE *file, ToDoList *toDoList) 
{   
    Info *info;
    Task *task;

    while (!feof(file)) 
    {
        info = (Info *)malloc(sizeof(Info));

        fgets(info->nome, 50, file);
        info->nome[strcspn(info->nome, "\n")] = 0;

        fscanf(file, "%d\n", &info->prioridade);
        fscanf(file, "%d/%d\n", &info->entrega.day, &info->entrega.month);

        task = (Task *)malloc(sizeof(Task));

        task->info = info;
        task->prev = NULL;
        task->next = NULL;

        insTask(toDoList, task);
    }
}

void writeFile(ToDoList toDoList)
{
    FILE *file = fopen("data.txt", "wt");

    for (Task *task = toDoList.head; task != NULL; task = task->next) 
    {
        fprintf(file, "%s\n%d\n%d/%d\n", task->info->nome, task->info->prioridade, task->info->entrega.day, task->info->entrega.month);
    }

    fclose(file);
}

void clear(Task *head) 
{
    if (head->next == NULL)
    {   
        free(head->info);
        free(head);
        return;
    }

    clear(head->next);

    free(head->info);
    free(head);
}
int main()
{
    ToDoList toDoList;
    initToDoList(&toDoList);

    FILE *file = fopen("data.txt", "rt+");

    if (file) {
        readFile(file, &toDoList);
    }
    
    int op = 0;
    char name[50];

    while (op != EXIT)
    {
        op = menu();

        switch(op)
        {
            case 1 :
                insTask(&toDoList, createTask());
                printf("\nTarefa adicionada com sucesso!\n");

                break;

            case 2 :
                printf("\nNome da tarefa à ser deletada: ");

                scanf("\n");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;

                delTask(&toDoList, name);
                printf("\nTarefa deletada com sucesso!\n");
                break;

            case 3 :
                printf("\nNome da tarefa à ser editada: ");

                scanf("\n");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;

                upTask(&toDoList, name);
                break;
            
            case 4 :
                printf("\nNome da Tarefa: ");

                scanf("\n");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;

                queryTask(&toDoList, name);
                break;

            case 5 : 
                listTasks(toDoList);
                break;

            case 10 :
                writeFile(toDoList);

                clear(toDoList.head);
                initToDoList(&toDoList);
                break;

            default :
                printf("\nOpção Inválida!\n");
                break;
        }
    }
}