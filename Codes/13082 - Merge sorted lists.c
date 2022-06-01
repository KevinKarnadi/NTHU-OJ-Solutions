#include<stdlib.h>
#define swap(a, b){int temp = a; a = b; b = temp;}

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

Node* Merge_lists(Node* a, Node* b)
{
    Node *head = NULL, *now = NULL;
    sort(a);
    sort(b);
    while(a != NULL || b != NULL)
    {
        if(head == NULL)
            head = now = malloc(sizeof(Node));
        else
        {
            while(a != NULL && a->data == now->data)
                a = a->next;
            while(b != NULL && b->data == now->data)
                b = b->next;
            if(a == NULL && b == NULL)
                break;
            now = now->next = malloc(sizeof(Node));
        }

        int c;
        if(a != NULL && b != NULL)
        {
            if(a->data <= b->data)
                c = 1;
            else
                c = 2;
        }
        else if(a == NULL)
            c = 2;
        else if(b == NULL)
            c = 1;

        if(c == 1)
            now->data = a->data;
        else if(c == 2)
            now->data = b->data;
    }
    return head;
}

void sort(Node* a)
{
    for(Node* i = a; i != NULL; i = i->next)
        for(Node* j = i->next; j != NULL; j = j->next)
            if(i->data > j->data)
                swap(i->data, j->data);
}
