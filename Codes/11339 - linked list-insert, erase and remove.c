#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

int len = 0;

typedef struct node
{
    struct node *next;
    struct node *prev;
    unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val);
void do_E(Node **head,size_t begin_pos,size_t end_pos);
void do_P(Node  *head,size_t pos);
void do_R(Node **head,unsigned short val);
void do_S(Node  *head);

void do_I(Node **head,size_t pos,unsigned short val)
{
    if(pos > len)
        pos = len;
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp->val = val;
    if(pos == 0)
    {
        if(*head != NULL)
        {
            temp->next = *head;
            (*head)->prev = temp;
        }
        *head = temp;
    }
    else
    {
        int t = pos;
        Node *prev;
        Node *now = *head;
        while(t--)
        {
            prev = now;
            now = now->next;
        }
        prev->next = temp;
        temp->prev = prev;
        if(now != NULL)
        {
            temp->next = now;
            now->prev = temp;
        }
    }
    len++;
    return;
}

void do_E(Node **head,size_t begin_pos,size_t end_pos)
{
    if(*head == NULL)
        return;

    if(begin_pos > len)
        begin_pos = len;
    if(end_pos > len)
        end_pos = len;
    if(begin_pos == end_pos)
        return;

    int t = begin_pos;
    Node *now = *head;
    Node *prev = NULL;
    while(t--)
    {
        prev = now;
        now = now->next;
    }

    t = end_pos - begin_pos;
    while(t--)
    {
        if(now == NULL)
            break;
        Node *tofree = now;
        now = now->next;
        free(tofree);
        len--;
    }

    if(prev != NULL)
        prev->next = now;
    else
        *head = now;

    if(now != NULL)
        now->prev = prev;
    return;
}

void do_P(Node  *head,size_t pos)
{
    if(head == NULL)
        return;
    if(pos >= len)
        pos = len - 1;

    Node *now = head;
    int t = pos;
    while(t--)
        now = now->next;
    printf("%d ", now->val);

    return;
}

void do_R(Node **head,unsigned short val)
{
    if(*head == NULL)
        return;

    Node *now = *head;
    while(now != NULL)
    {
        Node *tofree = NULL;
        if(now->val == val)
        {
            tofree = now;
            if(now == *head)
                *head = (*head)->next;
            if(now->next)
                now->next->prev = now->prev;
            if(now->prev)
                now->prev->next = now->next;
            len--;
        }
        now = now->next;
        free(tofree);
    }
    return;
}

void do_S(Node  *head)
{
    Node *now = head;
    while(now != NULL)
    {
        printf("%d ", now->val);
        now = now->next;
    }
    return;
}
