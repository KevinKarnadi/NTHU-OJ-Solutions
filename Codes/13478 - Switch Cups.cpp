#include <iostream>
#include <string>
#include <cstdlib>
#include "function.h"
using namespace std;

void LinkedList::reverse(int left, int right) {
    Node* curr = head;
    Node* prev = NULL;

    int idx = 1;
    while(curr != nullptr && idx < left) {
        prev = curr;
        curr = curr->next;
        idx++;
    }

    Node* _head = curr;
    Node* _tail = nullptr;

    while(curr != nullptr && idx <= right) {
        Node* temp = curr->next;
        curr->next = _tail;
        _tail = curr;
        curr = temp;
        idx++;
    }

    if(_head != nullptr)
        _head->next = curr;
    if(prev != nullptr)
        prev->next = _tail;
    else
        head = _tail;
}
