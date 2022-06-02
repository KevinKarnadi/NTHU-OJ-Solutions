#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int i;
    struct Node *left;
    struct Node *right;
} Node;

Node *tree_head = NULL;

void add_node(int a)
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
    if(tree_head == NULL)
    {
        temp->i = a;
        tree_head = temp;
    }
    else
    {
        Node *now = tree_head;
        while(1)
        {
            if(a < now->i)
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
        temp->i = a;
        if(a < now->i)
            now->left = temp;
        else
            now->right = temp;
    }
    return;
}

void showtree(Node *x)
{
    if(x->left)
        showtree(x->left);

    printf("%d ", x->i);

    if(x->right)
        showtree(x->right);
}
