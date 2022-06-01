#include <stdio.h>
#include <stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}

typedef struct
{
    void (*func)(void *);
    void *argument;
} Task;
typedef struct
{
    int* arr;
    int lower;
    int upper;
} Data;
typedef struct
{
    Task **tasks;
    int size;
} Task_List;

void job1(void* argument)  // reverse
{
    Data* data = (Data*)argument;
    for(int i = data->lower, j = data->upper; i <= j; i++, j--)
        swap(data->arr[i], data->arr[j]);
}

void job2(void* argument)  // minus
{
    Data* data = (Data*)argument;
    for(int i = data->lower; i <= data->upper; i++)
        data->arr[i] = -data->arr[i];
}

void job3(void* argument)  // double
{
    Data* data = (Data*)argument;
    for(int i = data->lower; i <= data->upper; i++)
        data->arr[i] = 2*data->arr[i];
}

void initTask(Task* task, void(*func)(void*),void* argument)
{
    task->func = func;
    task->argument = argument;
}

void executeTasks(Task_List *task_list)
{
    for(int i = 0; i < task_list->size; i++)
        task_list->tasks[i]->func(task_list->tasks[i]->argument);
}
