#include<stdio.h>
int arr[100000];
int cmp(const void* x, const void* y)
{
    int a = *(int*)x;
    int b = *(int*)y;
    return a - b;
}
typedef struct node
{
    int val;
    struct node* next;
}node;
node* create(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);
    qsort(arr,N,sizeof(int),cmp);

    node *px, *py, *now;
    px = py = now = create(NULL);
    for(int i=0;i<N;i++)
        now = now->next = create(arr[i]);
    node *end = now->next = create(NULL);

    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int M;
        scanf("%d", &M);
        if(M==1)
        {
            int x;
            scanf("%d", &x);
            while(px->next != end && px->next->val < x)
                px = px->next;
            if(px->next->val == x)
            {
                node* tofree = px->next;
                px->next = px->next->next;
                free(tofree);
            }
        }
        else
        {
            int y;
            scanf("%d", &y);
            while(py->next != end && py->next->val < y)
                py = py->next;
            if(py->next->val == y)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
