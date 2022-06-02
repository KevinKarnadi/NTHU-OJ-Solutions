#include<stdio.h>
#include<stdlib.h>

char s[260];
int pos;

typedef struct Node
{
    char i;
    struct Node *left;
    struct Node *right;
} Node;

Node *head = NULL;

Node *EXPR();
Node *FACTOR();
Node *makeNode(char c);

Node *EXPR()
{
    Node *right = FACTOR();
    pos--;
    Node *temp;
    char c = s[pos];
    if(pos < 0 || c == '(')
        temp = right;
    else
    {
        temp = makeNode(c);
        temp->right = right;
        pos--;
        temp->left = EXPR();
    }
    return temp;
}

Node *FACTOR()
{
    char c = s[pos];
    Node *temp;
    if(c == ')')
    {
        pos--;
        temp = EXPR();
    }
    else
        temp = makeNode(c);
    return temp;
}

Node *makeNode(char c)
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp->i = c;
    return temp;
}

void printList(Node *x)
{
    if(x->left)
        printList(x->left);

    printf("%c", x->i);

    if(x->right)
    {
        if(x->right->i == '&' || x->right->i == '|')
        {
            printf("(");
            printList(x->right);
            printf(")");
        }
        else
            printList(x->right);
    }
}

int main()
{
    scanf("%s", s);
    pos = strlen(s) - 1;
    head = EXPR();
    printList(head);
}
