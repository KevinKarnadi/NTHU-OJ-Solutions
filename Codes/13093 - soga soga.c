#include<stdio.h>

typedef struct node
{
    int i;
    struct node *l, *r;
}node;

node *head, *now, *prev, *mid;

node* create(int val, node *prev)
{
    node *temp = (node*)calloc(1, sizeof(node));
    temp->i = val;
    temp->l = prev;
    temp->r = NULL;
    return temp;
}

int main()
{
    int N;
    scanf("%d", &N);
    head = now = prev = mid = NULL;
    for(int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        if(head == NULL)
            head = now = create(num, prev);
        else
            now = now->r = create(num, prev);
        prev = now;
        if(i == (N+1)/2)
            mid = now;
    }
    int Q;
    scanf("%d", &Q);
    now = head;
    while(Q--)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            int dir;
            scanf("%d", &dir);
            if(dir == 1)
                now = now->r;
            else if(dir == -1)
                now = now->l;
        }
        else if(op == 2)
        {
            printf("%d\n", now->i);
        }
        else if(op == 3)
        {
            if(now == mid)
                now = now->r;
            if(mid->l != NULL)
            {
                mid->l->r = mid->r;
                mid->r->l = mid->l;
            }
            if(N % 2 == 0)
                mid = mid->r;
            else
                mid = mid->l;
            N--;
        }
    }
}
