#include <stdlib.h>
#include <stdio.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

Node* createReversedList()
{
    int val;
    Node *head = NULL, *now = NULL;
    while(1)
    {
        scanf("%d", &val);
        if(val == -1)
            return head;
        now = (Node*)malloc(sizeof(Node));
        now->data = val;
        now->next = head;
        head = now;
    }
}
