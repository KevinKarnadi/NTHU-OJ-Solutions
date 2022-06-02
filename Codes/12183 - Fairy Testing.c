#include<stdio.h>
#include<stdlib.h>

char s[1000000];
int idx;
int ans;

typedef struct Node
{
    char i;
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *var[100001];

Node *createTree(Node *prev)
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
    char c = s[idx];
    if(c == '[')
    {
        temp->i = NULL;
        temp->val = 0;
        temp->prev = prev;
        idx++;
        var[getval()] = temp;
    }
    else
    {
        temp->i = c;
        temp->val = 0;
        temp->prev = prev;
        idx++;
        temp->left = createTree(temp);
        temp->right = createTree(temp);
    }
    return temp;
}

int getval()
{
    int num = 0;
    while(s[idx] != ']')
    {
        num = num * 10 + (s[idx] - '0');
        idx++;
    }
    idx++;
    return num;
}

int eval(Node *x)
{
    if(x->i == NULL)
    {
        if(x->prev)
            return eval(x->prev);
        else
            return x->val;
    }
    else if(x->i == '|')
    {
        int newval;
        if(x->left->val == 1 || x->right->val == 1)
            newval = 1;
        else
            newval = 0;

        if(newval == x->val)
            return ans;
        else
        {
            x->val = newval;
            if(x->prev)
                return eval(x->prev);
            else
                return x->val;
        }
    }
    else if(x->i == '&')
    {
        int newval;
        if(x->left->val == 1 && x->right->val == 1)
            newval = 1;
        else
            newval = 0;

        if(newval == x->val)
            return ans;
        else
        {
            x->val = newval;
            if(x->prev)
                return eval(x->prev);
            else
                return x->val;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s", s);
        idx = 0;
        head = createTree(NULL);
        ans = 0;
        while(m--)
        {
            int x;
            scanf("%d", &x);
            var[x]->val = (var[x]->val + 1) % 2;
            ans = eval(var[x]);
            printf("%d\n", ans);
        }
    }
}
