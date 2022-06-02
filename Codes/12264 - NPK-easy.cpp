#include <iostream>
using namespace std;

typedef struct Node
{
    int id;
    Node *next;
    Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *_0 = NULL;
Node *_1 = NULL;
Node *_2 = NULL;

void enq(int x)
{
    Node *temp = new Node;
    temp->id = x;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        if(x % 3 == 0)
        {
            _0 = temp;
        }
        else if(x % 3 == 1)
        {
            _1 = temp;
        }
        else if(x % 3 == 2)
        {
            _2 = temp;
        }
    }
    else
    {
        if(x % 3 == 0)
        {
            if(_0 != NULL)
            {
                if(_0->next != NULL)
                {
                    temp->next = _0->next;
                    _0->next->prev = temp;
                }
                temp->prev = _0;
                _0->next = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            _0 = temp;
        }
        else if(x % 3 == 1)
        {
            if(_1 != NULL)
            {
                if(_1->next != NULL)
                {
                    temp->next = _1->next;
                    _1->next->prev = temp;
                }
                temp->prev = _1;
                _1->next = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            _1 = temp;
        }
        else if(x % 3 == 2)
        {
            if(_2 != NULL)
            {
                if(_2->next != NULL)
                {
                    temp->next = _2->next;
                    _2->next->prev = temp;
                }
                temp->prev = _2;
                _2->next = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            _2 = temp;
        }
    }
    if(temp->next == NULL)
        tail = temp;
}

int deq()
{
    int ret = head->id;
    Node *temp = head->next;
    if(_0 == head)
        _0 = NULL;
    else if(_1 == head)
        _1 = NULL;
    else if(_2 == head)
        _2 = NULL;
    if(head->next != NULL)
        head->next->prev = NULL;
    head = NULL;
    delete head;
    head = temp;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "ENQUEUE")
        {
            int x;
            cin >> x;
            enq(x);
        }
        else
        {
            cout << deq() << endl;
        }
    }
}
