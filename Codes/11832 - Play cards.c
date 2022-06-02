#include<stdio.h>

typedef struct Card
{
    int i;
    struct Card *next;
} Card;

Card *head = NULL, *now;

void Add(int idx, int num)
{
    Card *temp = (Card*)calloc(1, sizeof(Card));
    if(idx == 0)
    {
        temp->i = num;
        temp->next = head;
        head = temp;
    }
    else
    {
        now = head;
        Card *prev;
        while(idx--)
        {
            prev = now;
            now = now->next;
        }
        prev->next = temp;
        temp->i = num;
        temp->next = now;
    }
    return;
}

void Cut(int a, int b)
{
    if(a == 0)
        return;

    now = head;
    Card *prev1;
    int ctr = a;
    while(ctr--)
    {
        prev1 = now;
        now = now->next;
    }
    Card *newhead = now;

    Card *prev2;
    ctr = b;
    while(ctr--)
    {
        prev2 = now;
        now = now->next;
    }
    prev2->next = head;
    prev1->next = now;
    head = newhead;
    return;
}

void printList()
{
    now = head;
    while(now != NULL)
    {
        printf("%d\n", now->i);
        now = now->next;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if(head == NULL)
            head = now = (Card*)calloc(1, sizeof(Card));
        else
            now = now->next = (Card*)calloc(1, sizeof(Card));
        now->i = x;
    }
    while(m--)
    {
        char cmd[4];
        scanf("%s", cmd);
        if(cmd[0] == 'A')
        {
            int idx, num;
            scanf("%d %d", &idx, &num);
            Add(idx, num);
        }
        else if(cmd[0] == 'C')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            Cut(a, b);
        }
    }
    printList();
}
