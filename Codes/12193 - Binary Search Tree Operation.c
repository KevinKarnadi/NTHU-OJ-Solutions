#include<stdio.h>
#include<stdlib.h>

int d[10001];
int max;
int sum;
int ctr;

typedef struct Node
{
    int i;
    struct Node *left;
    struct Node *right;
} Node;

Node *head = NULL;

void GetMax(Node *x, int lvl)
{
    if(lvl > max)
        max = lvl;

    if(x->left)
        GetMax(x->left, lvl + 1);
    if(x->right)
        GetMax(x->right, lvl + 1);
}

void P(Node *x)
{
    if(x->left)
        P(x->left);

    printf("%d ", x->i);

    if(x->right)
        P(x->right);
}

void S(Node *x, int lvl, int maxlvl)
{
    if(lvl > maxlvl)
        return;
    if(lvl == maxlvl)
    {
        sum += x->i;
        ctr++;
        return;
    }
    if(x->left)
        S(x->left, lvl + 1, maxlvl);
    if(x->right)
        S(x->right, lvl + 1, maxlvl);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(d[x])
            continue;
        Node *temp = (Node*)calloc(1, sizeof(Node));
        temp->i = x;
        if(i == 0)
        {
            head = temp;
        }
        else
        {
            Node *now = head;
            while(1)
            {
                if(x < now->i)
                {
                    if(now->left)
                        now = now->left;
                    else
                        break;
                }
                else
                {
                    if(now->right)
                        now = now->right;
                    else
                        break;
                }
            }
            if(x < now->i)
                now->left = temp;
            else
                now->right = temp;
        }
        d[x] = 1;
    }
    max = 0;
    if(head != NULL)
        GetMax(head, 1);
    int m;
    scanf("%d", &m);
    while(m--)
    {
        char cmd[20];
        scanf("%s", cmd);
        if(cmd[0] == 'P')
        {
            if(head == NULL)
                printf("NULL");
            else
                P(head);
            printf("\n");
        }
        else if(cmd[0] == 'G')
            printf("%d\n", max);
        else if(cmd[0] == 'S')
        {
            int lvl;
            scanf("%d", &lvl);
            if(lvl > max || lvl == 0)
                printf("0\n");
            else
            {
                sum = 0;
                S(head, 1, lvl);
                printf("%d\n", sum);
            }
        }
        else if(cmd[0] == 'A')
        {
            int lvl;
            scanf("%d", &lvl);
            if(lvl > max || lvl == 0)
                printf("0\n");
            else
            {
                sum = 0;
                ctr = 0;
                S(head, 1, lvl);
                printf("%.3f\n", (float)sum/ctr);
            }
        }
    }
}
