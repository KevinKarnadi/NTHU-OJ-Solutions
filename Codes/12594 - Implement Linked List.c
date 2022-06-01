#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

Node* createList(int *a, int size)
{
    Node *start = NULL, *now = NULL;
    for(int i = 0; i < size; i++)
    {
        if(i == 0)
            start = now = calloc(1, sizeof(Node));
        else
            now = now->next = calloc(1, sizeof(Node));
        now->data = a[i];
    }
    return start;
}

void push_front(Node** head, int val)
{
    Node *temp = calloc(1, sizeof(Node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

Node* copyList(Node* head)
{
    Node *start = NULL, *now = NULL;
    while(head != NULL)
    {
        if(start == NULL)
            start = now = calloc(1, sizeof(Node));
        else
            now = now->next = calloc(1, sizeof(Node));
        now->data = head->data;
        head = head->next;
    }
    return start;
}

void deleteElementByIdx(Node** head, int idx)
{
    Node *now = *head, *prev = NULL, *tofree = NULL;
    if(idx == 0)
    {
        tofree = now;
        *head = (*head)->next;
    }
    else
    {
        while(idx-- && now != NULL)
        {
            prev = now;
            now = now->next;
        }
        if(now == NULL)
            return;
        tofree = now;
        prev->next = now->next;
    }
    free(tofree);
}

void SwapElementByIdx(Node** head, int idx1, int idx2)
{
    Node *now = *head;
    Node *c1 = NULL, *c2 = NULL;
    while((idx1 >= 0 || idx2 >= 0) && now != NULL)
    {
        if(idx1 == 0)
            c1 = now;
        if(idx2 == 0)
            c2 = now;
        now = now->next;
        idx1--;
        idx2--;
    }
    swap(c1->data, c2->data);
}
