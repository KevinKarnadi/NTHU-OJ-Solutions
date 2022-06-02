#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void insert_decreasing_list(Node** max, int val)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if(max == NULL)
    {
        *max = temp;
        return;
    }
    Node *pos = *max, *prev = NULL;
    while(pos != NULL && pos->data > val)
    {
        prev = pos;
        pos = pos->next;
    }
    if(prev != NULL)
        prev->next = temp;
    else
        *max = temp;
    temp->next = pos;
}
