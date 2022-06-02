#include <iostream>
#include <math.h>
#include "function.h"
using namespace std;

Array_MAX_HEAP::Array_MAX_HEAP() : MAX_HEAP() {}

void Array_MAX_HEAP::PUSH(const int &a)
{
    Count++;
    array[Count] = a;
    for(int i = Count; i / 2 >= 1; i /= 2)
    {
        if(array[i] > array[i / 2])
        {
            int temp = array[i];
            array[i] = array[i / 2];
            array[i / 2] = temp;
        }
        else
            break;
    }
}

int Array_MAX_HEAP::MAX() const
{
    if(Count == 0)
        return -1;
    else
        return array[1];
}

int Array_MAX_HEAP::POP()
{
    if(Count == 0)
        return -1;
    int ret = array[1];
    array[1] = array[Count];
    Count--;
    int idx = 1;
    for(int i = 1; i * 2 <= Count; i = idx)
    {
        if((i * 2) + 1 <= Count)
        {
            if(array[i * 2] >= array[(i * 2) + 1])
                idx = i * 2;
            else
                idx = (i * 2) + 1;
        }
        else
            idx = i * 2;
        if(array[i] < array[idx])
        {
            int temp = array[i];
            array[i] = array[idx];
            array[idx] = temp;
        }
        else
            break;
    }
    return ret;
}

List_MAX_HEAP::List_MAX_HEAP() : MAX_HEAP()
{
    root = nullptr;
}

void List_MAX_HEAP::PUSH(const int &a)
{
    Count++;
    ListNode *temp = new ListNode(a);
    if(root == nullptr)
    {
        root = temp;
    }
    else
    {
        ListNode *cur = temp;
        ListNode *par = findparent(Count, root);
        if(par->left == nullptr)
        {
            par->left = cur;
            cur->parent = par;
        }
        else
        {
            par->right = cur;
            cur->parent = par;
        }
        while(cur->parent != nullptr)
        {
            if(cur->parent->value < cur->value)
            {
                int temp = cur->value;
                cur->value = cur->parent->value;
                cur->parent->value = temp;
                cur = cur->parent;
            }
            else
                break;
        }
    }
}

int List_MAX_HEAP::MAX() const
{
    if(Count == 0)
        return -1;
    else
        return root->value;
}

int List_MAX_HEAP::POP()
{
    if(Count == 0)
        return -1;
    int ret = root->value;
    if(Count == 1)
    {
        root = nullptr;
        delete root;
        Count--;
    }
    else
    {
        ListNode *cur = nullptr;
        ListNode *par = findparent(Count, root);
        if(par->right != nullptr)
        {
            cur = par->right;
            par->right = nullptr;
        }
        else
        {
            cur = par->left;
            par->left = nullptr;
        }
        root->value = cur->value;
        cur = nullptr;
        delete cur;
        Count--;
        cur = root;
        while(cur->left != nullptr || cur->right != nullptr)
        {
            int dir;
            if(cur->left != nullptr && cur->right != nullptr)
            {
                if(cur->left->value >= cur->right->value)
                    dir = 1;
                else
                    dir = 2;
            }
            else
                dir = 1;

            if(dir == 1)
            {
                if(cur->value < cur->left->value)
                {
                    int temp = cur->value;
                    cur->value = cur->left->value;
                    cur->left->value = temp;
                    cur = cur->left;
                }
                else
                    break;
            }
            else
            {
                if(cur->value < cur->right->value)
                {
                    int temp = cur->value;
                    cur->value = cur->right->value;
                    cur->right->value = temp;
                    cur = cur->right;
                }
                else
                    break;
            }
        }
    }
    return ret;
}

void List_MAX_HEAP::deleteTree(ListNode *root)
{
    if(root->left)
        List_MAX_HEAP::deleteTree(root->left);
    if(root->right)
        List_MAX_HEAP::deleteTree(root->right);
    delete root;
}
