#include <iostream>
#include <string>
using namespace std;

int ctr = 0;

struct Node
{
    Node *prev;
    Node *next;
    int val;
    int tag;
};

class KuoYangPresent
{
public:
    KuoYangPresent(int k);
    void Push(int x);
    void Pop();
    void ProgrammingTanoshi();
    void KuoYangTeTe();
    void PrintList();
private:
    Node *head, *mid, *tail;
    int sz, k;
};

KuoYangPresent::KuoYangPresent(int k)
{
    sz = 0;
    this->k = k;
    head = NULL;
    mid = NULL;
    tail = NULL;
}

void KuoYangPresent::Push(int x)
{
    sz++;
    Node *temp = new Node;
    temp->val = x;
    temp->tag = ctr;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        mid = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        if(sz % 2 == 1)
            mid = mid->next;
    }
}

void KuoYangPresent::Pop()
{
    sz--;
    if(mid->prev)
        mid->prev->next = mid->next;
    if(mid->next)
        mid->next->prev = mid->prev;
    if(sz % 2 == 1)
        mid = mid->next;
    else
        mid = mid->prev;
}

void KuoYangPresent::ProgrammingTanoshi()
{
    ctr++;
}

void KuoYangPresent::KuoYangTeTe()
{
    Node *now = head;
    while(now != NULL)
    {
        if(now->tag < ctr)
            now->val %= k;
        now = now->next;
    }
}

void KuoYangPresent::PrintList()
{
    Node *now = head;
    while(now != NULL)
    {
        cout << now->val << ' ';
        now = now->next;
    }
    cout << endl;
}
