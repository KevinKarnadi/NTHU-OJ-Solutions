#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

void insert_increase_list(Node** head, int val)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if(*head == NULL)
    {
        *head = temp;
        return;
    }
    Node *now = *head, *prev = NULL;
    while(now != NULL && now->data < val)
    {
        prev = now;
        now = now->next;
    }
    if(prev != NULL)
        prev->next = temp;
    else
        *head = temp;
    temp->next = now;
}
