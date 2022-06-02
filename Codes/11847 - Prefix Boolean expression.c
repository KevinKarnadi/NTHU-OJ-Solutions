#include<stdio.h>
#include<stdlib.h>

char s[40];
int idx;

typedef struct Node
{
    char i;
    struct Node *left;
    struct Node *right;
} Node;

Node *head = NULL;

Node *createTree()
{
    char c = s[idx];
    idx++;
    Node *temp = (Node*)calloc(1, sizeof(Node));
    if(c == '|' || c == '&')
    {
        temp->i = c;
        temp->left = createTree();
        temp->right = createTree();
    }
    else
    {
        temp->i = c;
    }
    return temp;
}

int eval(Node *x, int a, int b, int c, int d)
{
    if(x->i == '&')
    {
        int left = eval(x->left, a, b, c, d);
        int right = eval(x->right, a, b, c, d);
        if(left == 1 && right == 1)
            return 1;
        else
            return 0;
    }
    else if(x->i == '|')
    {
        int left = eval(x->left, a, b, c, d);
        int right = eval(x->right, a, b, c, d);
        if(left == 1 || right == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(x->i == 'A')
            return a;
        else if(x->i == 'B')
            return b;
        else if(x->i == 'C')
            return c;
        else if(x->i == 'D')
            return d;
    }
}

void printList(Node *x)
{
    printf("%c", x->i);

    if(x->left)
        printList(x->left);

    if(x->right)
        printList(x->right);
}

int main()
{
    scanf("%s", s);
    idx = 0;
    head = createTree();
    printf("0 0 0 0 %d\n", eval(head, 0, 0, 0, 0));
    printf("0 0 0 1 %d\n", eval(head, 0, 0, 0, 1));
    printf("0 0 1 0 %d\n", eval(head, 0, 0, 1, 0));
    printf("0 0 1 1 %d\n", eval(head, 0, 0, 1, 1));
    printf("0 1 0 0 %d\n", eval(head, 0, 1, 0, 0));
    printf("0 1 0 1 %d\n", eval(head, 0, 1, 0, 1));
    printf("0 1 1 0 %d\n", eval(head, 0, 1, 1, 0));
    printf("0 1 1 1 %d\n", eval(head, 0, 1, 1, 1));
    printf("1 0 0 0 %d\n", eval(head, 1, 0, 0, 0));
    printf("1 0 0 1 %d\n", eval(head, 1, 0, 0, 1));
    printf("1 0 1 0 %d\n", eval(head, 1, 0, 1, 0));
    printf("1 0 1 1 %d\n", eval(head, 1, 0, 1, 1));
    printf("1 1 0 0 %d\n", eval(head, 1, 1, 0, 0));
    printf("1 1 0 1 %d\n", eval(head, 1, 1, 0, 1));
    printf("1 1 1 0 %d\n", eval(head, 1, 1, 1, 0));
    printf("1 1 1 1 %d\n", eval(head, 1, 1, 1, 1));
}
