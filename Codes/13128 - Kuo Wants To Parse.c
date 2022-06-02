#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //for isdigit()

typedef struct _Node
{
    int value;
    char OP;
    struct _Node *left;
    struct _Node *right;
} Node;

char expr[120];
int pos;
Node *head;

Node* Factor();
Node* Expr();
void PrefixPrint(Node* node);
Node* CreateNode(int value, char ch);

Node* Expr()
{
    Node *right = Factor();
    pos--;
    char c = expr[pos];
    Node *temp;
    if(pos < 0 || c == '(')
        temp = right;
    else
    {
        temp = CreateNode(NULL, c);
        temp->right = right;
        pos--;
        temp->left = Expr();
    }
    return temp;
}

Node* Factor()
{
    Node *temp;
    char c = expr[pos];
    if(c == ')')
    {
        pos--;
        temp = Expr();
    }
    else if(c >= '0' && c <= '9')
    {
        int val = getval();
        temp = CreateNode(val, 'N');
    }
    return temp;
}

int getval()
{
    int num = 0;
    int power = 0;
    while(expr[pos] >= '0' && expr[pos] <= '9')
    {
        num = num + (expr[pos] - '0') * pow(10, power);
        power++;
        pos--;
    }
    pos++;
    return num;
}

Node* CreateNode(int value, char ch)
{
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));

    if(ch == 'N')
    {
        newNode->value = value;
        newNode->OP = 'N';
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else
    {
        newNode->value = -1;
        newNode->OP = ch;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void PrefixPrint(Node* node)
{
    if(node->OP != 'N')
        printf("%c ", node->OP);
    else
        printf("%d ", node->value);

    if(node->left)
        PrefixPrint(node->left);
    if(node->right)
        PrefixPrint(node->right);
}

int main()
{
    while((scanf("%s", expr)) != EOF)
    {
        pos = strlen(expr) - 1;
        head = Expr();
        PrefixPrint(head);
        printf("\n");
        head = NULL;
    }

    return 0;
}
