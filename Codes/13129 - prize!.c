#include <stdlib.h>

int ctr;

typedef struct Node
{
    int i;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head;

Node *createList(int n)
{
    Node *now, *prev;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
            head = now = (Node*)calloc(1, sizeof(Node));
        else
        {
            now = now->next = (Node*)calloc(1, sizeof(Node));
            now->prev = prev;
        }
        now->i = i;
        prev = now;
    }
    now->next = head;
    head->prev = now;
    return head;
}

void solveJosephus(int n, int k)
{
    ctr = n;
    Node *now = head;
    int start = 0;
    int winner[k];
    int idx = 0;
    int t = k;
    while(t--)
    {
        int x;
        scanf("%d", &x);
        int dir;
        if(x % 2 == 1)
            dir = 1;
        else
            dir = 2;
        if(start)
        {
            Node *temp = now;
            if(dir == 1)
                now = now->next;
            else
                now = now->prev;
            deleteNode(temp);
        }
        int step = x;
        step %= ctr;
        if(step == 0)
            step = x;
        step--;
        if(dir == 1)
        {
            while(step--)
                now = now->next;
        }
        else
        {
            while(step--)
                now = now->prev;
        }
        winner[idx++] = now->i;
        start = 1;
    }
    for(int i = 0; i < k; i++)
        printf("%d\n", winner[i]);
}

void deleteNode(Node *temp)
{
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    ctr--;
    return;
}
