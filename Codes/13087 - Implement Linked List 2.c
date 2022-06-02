#include <stdio.h>
#include <stdlib.h>
#define swap(a, b){a^=b^=a^=b;}

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
            start = now = (Node*)calloc(1, sizeof(Node));
        else
            now = now->next = (Node*)calloc(1, sizeof(Node));
        now->data = a[i];
    }
    return start;
}

void push_front(Node** head, int val)
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
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
            start = now = (Node*)calloc(1, sizeof(Node));
        else
            now = now->next = (Node*)calloc(1, sizeof(Node));
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
        idx1--;
        idx2--;
        now = now->next;
    }
    swap(c1->data, c2->data);
}

void ReverseList(Node** head)
{
    Node *temp = NULL;
    Node *temphead = NULL;
    while(*head != NULL)
    {
        temp = (Node*)calloc(1, sizeof(Node));
        temp->data = (*head)->data;
        temp->next = temphead;
        temphead =  temp;
        *head = (*head)->next;
    }
    *head = temp;
}

void ShiftListByK(Node ** head, int k)
{
    Node *now = *head;
    int len = 0;
    while(now != NULL)
    {
        len++;
        now = now->next;
    }
    Node *head1 = NULL;
    Node *head2;
    k = k % len;
    if(k == 0)
    {
        return;
    }
    head2 = *head;
    now = *head;
    for(int i = 0; i < len; i++, now = now->next)
    {
        if(i == len - k)
            head1 = now;
    }

    Node *tail1 = NULL;
    Node *now1 = head1;
    while(now1 != NULL)
    {
        tail1 = now1;
        now1 = now1->next;
    }
    tail1->next = head2;

    Node *tail2 = NULL;
    Node *now2 = head2;
    int ctr = len - k;
    while(ctr > 0)
    {
        tail2 = now2;
        now2 = now2->next;
        ctr--;
    }
    tail2->next = NULL;
    *head = head1;
}
