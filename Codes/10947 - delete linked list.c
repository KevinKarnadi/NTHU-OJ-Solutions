#include <stdlib.h>
#include <stdio.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node **head, int idx)
{
    Node *now = *head, *prev = NULL, *tofree = NULL;
    if(idx == 1)
    {
        *head = now->next;
        tofree = now;
        free(tofree);
        return;
    }
    else
    {
        idx--;
        while(idx-- && now != NULL)
        {
            prev = now;
            now = now->next;
            tofree = now;
        }
        if(now != NULL)
            prev->next = now->next;
        else
            prev->next = NULL;
        free(tofree);
        return;
    }
}

Node* createList()
{
    int x;
    Node *head = NULL, *now = NULL;
    while(1)
    {
        scanf("%d", &x);
        if(x == -1)
            break;
        if(head == NULL)
            head = now = (Node*)malloc(sizeof(Node));
        else
            now = now->next = (Node*)malloc(sizeof(Node));
        now->data = x;
    }
    now->next = NULL;
    return head;
}
