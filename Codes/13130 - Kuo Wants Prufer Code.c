#include<stdio.h>

int n;
int a[5000], b[5000];
int ctr[5001];

typedef struct Node
{
    int i;
    int n;
    int dead;
    struct Node **next;
} Node;

Node *ptr[5001];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        ctr[a[i]]++;
        ctr[b[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        ptr[i] = (Node*)calloc(1, sizeof(Node));
        ptr[i]->i = i;
        ptr[i]->n = 0;
        ptr[i]->dead = 0;
        ptr[i]->next = (Node**)calloc(ctr[i], sizeof(Node*));
    }
    for(int i = 1; i < n; i++)
    {
        ptr[a[i]]->next[ptr[a[i]]->n++] = ptr[b[i]];
        ptr[b[i]]->next[ptr[b[i]]->n++] = ptr[a[i]];
    }
    int t = n - 2;
    while(t)
    {
        for(int i = 1; i <= n; i++)
        {
            if(ptr[i]->dead || ptr[i]->n > 1)
                continue;

            for(int j = 0; j < ctr[ptr[i]->i]; j++)
            {
                if(ptr[i]->next[j]->dead)
                    continue;

                ptr[i]->next[j]->n--;
                printf("%d ", ptr[i]->next[j]->i);
                break;
            }
            ptr[i]->dead = 1;
            t--;
            break;
        }
    }
    printf("\n");
}
