#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    struct _Node *prev;
    struct _Node *next;
    int val;
    int tag;
} Node;

int n, k, q;
Node *head = NULL;
Node *tail;
Node *mid;

int ctr = 0;
int tanoshi = 0;

void push(int x);
void pop();
void programming_tanoshi();
void KuoYangTeTe();

void push(int x)
{
    ctr++;
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp->val = x;
    temp->tag = tanoshi;
    if(head == NULL)
    {
        head = temp;
        mid = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        if(ctr % 2 == 1)
            mid = mid->next;
    }
    return;
}

void pop()
{
    Node *newmid;
    if(ctr % 2 == 1)
        newmid = mid->prev;
    else
        newmid = mid->next;
    if(mid->prev)
        mid->prev->next = mid->next;
    if(mid->next)
        mid->next->prev = mid->prev;
    mid = newmid;
    ctr--;
    return;
}

void programming_tanoshi()
{
    tanoshi++;
    return;
}

void KuoYangTeTe()
{
    Node *now = head;
    while(now != NULL)
    {
        if(now->tag < tanoshi)
            now->val %= k;
        now = now->next;
    }
    return;
}
