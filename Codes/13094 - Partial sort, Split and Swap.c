#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

Node* Partial_sort(Node* head, int x)
{
    Node *head1 = NULL, *now1 = NULL;
    Node *head2 = NULL, *now2 = NULL;
    Node *now = head;
    while(now != NULL)
    {
        if(now->data < x)
        {
            if(head1 == NULL)
                head1 = now1 = (Node*)calloc(1, sizeof(Node));
            else
                now1 = now1->next = (Node*)calloc(1, sizeof(Node));
            now1->data = now->data;
        }
        else
        {
            if(head2 == NULL)
                head2 = now2 = (Node*)calloc(1, sizeof(Node));
            else
                now2 = now2->next = (Node*)calloc(1, sizeof(Node));
            now2->data = now->data;
        }
        now = now->next;
    }
    if(head1 == NULL)
    {
        now2->next = NULL;
        return head2;
    }
    else
    {
        if(head2 != NULL)
        {
            now1->next = head2;
            now2->next = NULL;
        }
        else
        {
            now1->next = NULL;
        }
        return head1;
    }
}

Node* Split_and_Swap(Node* head, int a, int b)
{
    Node *head1 = NULL, *now1 = NULL;
    Node *head2 = NULL, *now2 = NULL;
    Node *head3 = NULL, *now3 = NULL;
    Node *now = head;
    Node *tofree = NULL;
    for(int i = 0; now != NULL; i++, now = now->next)
    {
        tofree = now;
        if(i <= a)
        {
            if(head1 == NULL)
                head1 = now1 = (Node*)calloc(1, sizeof(Node));
            else
                now1 = now1->next = (Node*)calloc(1, sizeof(Node));
            now1->data = now->data;
        }
        else if(i >= b)
        {
            if(head3 == NULL)
                head3 = now3 = (Node*)calloc(1, sizeof(Node));
            else
                now3 = now3->next = (Node*)calloc(1, sizeof(Node));
            now3->data = now->data;
        }
        else
        {
            if(head2 == NULL)
                head2 = now2 = (Node*)calloc(1, sizeof(Node));
            else
                now2 = now2->next = (Node*)calloc(1, sizeof(Node));
            now2->data = now->data;
        }
        free(tofree);
    }
    Node *head4 = NULL, *now4 = NULL;
    now = head3;
    while(now != NULL)
    {
        if(head4 == NULL)
            head4 = now4 = now;
        else
            now4 = now4->next = now;
        now = now->next;
    }
    now = head2;
    while(now != NULL)
    {
        now4 = now4->next = now;
        now = now->next;
    }
    now = head1;
    while(now != NULL)
    {
        now4 = now4->next = now;
        now = now->next;
    }
    now4->next = NULL;
    return head4;
}
