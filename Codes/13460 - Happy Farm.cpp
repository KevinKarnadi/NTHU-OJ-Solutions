#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "function.h"
using namespace std;


template<class T>
Node<T>::Node(T x,T y,T fence) {
    this->x = x;
    this->y = y;
    this->fence = fence;
    this->next = nullptr;
}

template<class T>
T Node<T>::compare(T x,T y) {
    if(this->y > y)
        return 1;
    else if(this->y == y) {
        if(this->x > x)
            return 1;
        else if(this->x == x)
            return 0;
        else if(this->x > x)
            return -1;
    }
    else if(this->y < y)
        return -1;
}


template<class T>
LinkedList<T>::LinkedList() {
    this->first = nullptr;
    this->length = 0;
}

template<class T>
void LinkedList<T>::insert(T x, T y,T fence) {
    Node<T>* newNode = new Node<T>(x, y, fence);
    if(this->length == 0) {
        this->first = newNode;
    }
    else {
        Node<T>* temp = this->first;
        Node<T>* prev = nullptr;
        while(temp != nullptr) {
            float dist = temp->compare(newNode->x, newNode->y);
            if(dist > 0)
                break;
            else if(dist == 0) {
                if(temp->fence == 0)
                    temp->fence = fence;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp == this->first)
            this->first = newNode;
        if(prev != nullptr)
            prev->next = newNode;
        newNode->next = temp;
    }
    this->length++;
}

template<class T>
void LinkedList<T>::deletion(T x, T y) {
    Node<T>* temp = this->first;
    Node<T>* prev = nullptr;
    while(temp != nullptr) {
        float dist = temp->compare(x, y);
        if(dist > 0)
            return;
        else if(temp->x == x && temp->y == y) {
            if(temp->fence == 1)
                return;
            if(temp == this->first)
                this->first = temp->next;
            if(prev != nullptr)
                prev->next = temp->next;
            delete temp;
            this->length--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

template<class T>
void LinkedList<T>::show() {
    Node<T>* temp = this->first;
    while(temp != nullptr) {
        cout << "(" << temp->x << "," << temp->y << ")" << "\n";
        temp = temp->next;
    }
}


LinkedList<long long> farm;


void plant(long long x,long long y,int withFence) {
    farm.insert(x, y, withFence);
}

void thief(long long x,long long y) {
    farm.deletion(  x, y-1);
    farm.deletion(x-1,   y);
    farm.deletion(  x,   y);
    farm.deletion(x+1,   y);
    farm.deletion(  x, y+1);
}

void superThief(long long x,long long y) {
    farm.deletion(x-1, y-1);
    farm.deletion(  x, y-1);
    farm.deletion(x+1, y-1);
    farm.deletion(x-1,   y);
    farm.deletion(  x,   y);
    farm.deletion(x+1,   y);
    farm.deletion(x-1, y+1);
    farm.deletion(  x, y+1);
    farm.deletion(x+1, y+1);
}

void display() {
    cout << "Display" << "\n";
    farm.show();
}
