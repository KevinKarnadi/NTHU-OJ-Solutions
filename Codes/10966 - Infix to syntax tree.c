#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node
{
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode *EXPR()
{
    BTNode *right = FACTOR();
    pos--;
    BTNode *temp;
    if(pos < 0 || expr[pos] == '(')
        temp = right;
    else
    {
        char c = expr[pos];
        temp = makeNode(c);
        temp->right = right;
        pos--;
        temp->left = EXPR();
    }
    return temp;
}

BTNode* FACTOR()
{
    char c = expr[pos];
    BTNode *temp;
    if(c == ')')
    {
        pos--;
        temp = EXPR();
    }
    else
        temp = makeNode(c);
    return temp;
}

BTNode* makeNode(char c)
{
    BTNode *temp = (BTNode*)calloc(1, sizeof(BTNode));
    for(int i = 0; i < 6; i++)
        if(sym[i] == c)
            temp->data = i;
    return temp;
}
