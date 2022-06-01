#include<stdio.h>

typedef struct node
{
    int i;
    int n;
    struct node **next;
}node;

int n;
int x[100001], y[100001];
int cnt[100001];
node *ptr[100001];

int find(int num, int last)
{
    int ret = 1;
    for(int i = 0; i < ptr[num]->n; i++)
    {
        if(ptr[num]->next[i]->i == last)
            continue;
        ret += find(ptr[num]->next[i]->i, num);
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        cnt[x[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        ptr[i] = (node*)calloc(1, sizeof(node));
        ptr[i]->i = i;
        ptr[i]->n = 0;
        ptr[i]->next = (node**)calloc(cnt[i], sizeof(node*));
    }
    for(int i = 1; i < n; i++)
    {
        ptr[x[i]]->next[ptr[x[i]]->n++] = ptr[y[i]];
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d%c", find(i, 0) - 1, i == n ? '\n' : ' ');
    }
}
