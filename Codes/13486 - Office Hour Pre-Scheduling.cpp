#include <iostream>
#include <string>
#include <vector>
#include "function.h"
typedef unsigned int u32;
using namespace std;


// Class Node


// Constructor
Node::Node(std::string id, u32 time) {
    this->id = id;
    this->time = time;
}

// return time of the node
u32 Node::get_time() {
    return this->time;
}

// return id of the node
std::string Node::get_id() {
    return this->id;
}

// set time of the node
void Node::set_time(u32 time) {
    this->time = time;
}


// Class BinaryHeap


// get index of parent of node at index idx.
template<class T>
u32 BinaryHeap<T>::parent_idx(u32 idx) {
    return (idx - 1) / 2;
}

// get index of left child of node at index idx.
template<class T>
u32 BinaryHeap<T>::left_idx(u32 idx) {
    return (idx * 2) + 1;
}

// get index of right child of node at index idx.
template<class T>
u32 BinaryHeap<T>::right_idx(u32 idx) {
    return (idx * 2) + 2;
}

// heapify from idx to root.
template<class T>
void BinaryHeap<T>::heapify_up(int idx) {  // For insertions
    while(idx >= 0) {
        if(idx == 0)
            break;
        u32 par_idx = this->parent_idx(idx);
        if(this->heap[idx] < this->heap[par_idx])
            swap(this->heap[idx], this->heap[par_idx]);
        else if(this->heap[idx] == this->heap[par_idx]) {
            if(this->heap[idx].get_id() < this->heap[par_idx].get_id())
                swap(this->heap[idx], this->heap[par_idx]);
            else
                break;
        }
        else
            break;
        idx = par_idx;
    }
}

// heapify from idx to leaf.
template<class T>
void BinaryHeap<T>::heapify_down(int idx) {  // For deletions
    u32 l = this->left_idx(idx);
    u32 r = this->right_idx(idx);
    int smallest = idx;
    if(l < this->size() && this->heap[l] < this->heap[smallest])
        smallest = l;
    else if(l < this->size() && this->heap[l] == this->heap[smallest]) {
        if(this->heap[l].get_id() < this->heap[smallest].get_id())
            smallest = l;
    }
    if(r < this->size() && this->heap[r] < this->heap[smallest])
        smallest = r;
    else if(r < this->size() && this->heap[r] == this->heap[smallest]) {
        if(this->heap[r].get_id() < this->heap[smallest].get_id())
            smallest = r;
    }
    if(smallest != idx) {
        swap(this->heap[idx], this->heap[smallest]);
        this->heapify_down(smallest);
    }
}

// get number of element in heap.
template<class T>
u32 BinaryHeap<T>::size() {
    return this->heap.size();
}

// insert element to heap.
template<class T>
void BinaryHeap<T>::insert(T element) {
    this->heap.push_back(element);
    this->heapify_up(this->size() - 1);
}

// remove minimum element from heap.
template<class T>
void BinaryHeap<T>::del_min() {
    this->heap[0] = this->heap[this->size() - 1];
    this->heap.pop_back();
    this->heapify_down(0);
}

// get minimum element from heap.
template<class T>
T BinaryHeap<T>::get_min() {
    return this->heap[0];
}


// class Manager


// Check if a task that takes $costTime time units can be completed before time $deadLine
template<class T>
int Manager<T>::finish_in_time(u32 costTime,u32 deadLine) {
    return (this->taQue.heap[0] + costTime) - deadLine;
}

template<class T>
Manager<T>::Manager() {
    this->endTime = -1;
}

// To handle the SET_ENDTIME instruction
template<class T>
void Manager<T>::cmd_set_endTime(u32 endTime) {  // time complexity: O(n)
    bool success = true;
    for(int i = 0; i < this->taQue.size(); i++) {
        if(this->taQue.heap[i] > endTime) {
            success = false;
            break;
        }
    }
    if(success)
        this->endTime = endTime;
    if(success)
        cout << "SET_ENDTIME SUCCESS" << "\n";
    else
        cout << "SET_ENDTIME FAIL" << "\n";
}

// To handle the ADD_TASK instruction
template<class T>
void Manager<T>::cmd_add_task(string taskName, u32 costTime) {  // time complexity: O(log n)
    bool success = false;
    if(this->taQue.size() == 0) {
        cout << "ADD_TASK " << taskName << ": FAIL" << "\n";
        return;
    }
    Node TA = this->taQue.get_min();
    u32 time = TA.get_time() + costTime;
    if(this->endTime == -1 || time <= this->endTime) {
        success = true;
        TA.set_time(time);
        this->taQue.del_min();
        this->taQue.insert(TA);
    }
    if(success)
        cout << "ADD_TASK " << taskName << ": " << TA << "\n";
    else
        cout << "ADD_TASK " << taskName << ": FAIL" << "\n";
}

// To handle the ADD_TA instruction
template<class T>
void Manager<T>::cmd_add_ta(std::string id, u32 begin) {  // time complexity: O(log n)
    bool success = false;
    if(this->endTime == -1 || begin < this->endTime) {
        success = true;
        Node newNode = Node(id, begin);
        this->taQue.insert(newNode);
    }
    if(success)
        cout << "ADD_TA SUCCESS" << "\n";
    else
        cout << "ADD_TA FAIL" << "\n";
}

// To handle the CHECK_INTIME instruction
template<class T>
void Manager<T>::cmd_check_schedule(u32 costTime,u32 deadLine) {  // time complexity: O(log n)
    if(this->taQue.size() == 0)
        cout << "CHECK_SCHEDULE: NO TA WARNING!" << "\n";
    else {
        u32 totalTime = this->taQue.heap[0].get_time() + costTime;
        if(totalTime < deadLine && totalTime < this->endTime)
            cout << "CHECK_SCHEDULE: CAN FINISH!" << "\n";
        else
            cout << "CHECK_SCHEDULE: OVERTIME WARNING!" << "\n";
    }
}

// To print out the final output required by the program
template<class T>
void Manager<T>::result() {
    cout << "NUMBER_TA: " << this->taQue.size() << "\n";
    if(this->taQue.size() > 0)
        cout << "EARLIEST FINISH TA: " << this->taQue.heap[0] << "\n";
}


// Operator Overloading


bool operator== (Node& node1, Node& node2) {
    return node1.get_time() == node2.get_time();
}

bool operator== (Node& node1, u32 time) {
    return node1.get_time() == time;
}

bool operator!= (Node& node1, Node& node2) {
    return node1.get_time() != node2.get_time();
}

bool operator!= (Node& node1, u32 time) {
    return node1.get_time() != time;
}

bool operator< (Node& node1, Node& node2) {
    if(node1.get_time() == node2.get_time()){
        return node1.get_id() < node2.get_id();
    }
    return node1.get_time() < node2.get_time();
}

bool operator< (Node& node1, u32 time) {
    return node1.get_time() < time;
}

bool operator> (Node& node1, Node& node2) {
    if(node1.get_time() == node2.get_time()){
        return node1.get_id() > node2.get_id();
    }
    return node1.get_time() > node2.get_time();
}

bool operator> (Node& node1, u32 time) {
    return node1.get_time() > time;
}

bool operator<= (Node& node1, Node& node2) {
    return node1.get_time() <= node2.get_time();
}

bool operator<= (Node& node1, u32 time) {
    return node1.get_time() <= time;
}

bool operator>= (Node& node1, Node& node2) {
    return node1.get_time() >= node2.get_time();
}

bool operator>= (Node& node1, u32 time) {
    return node1.get_time() >= time;
}

void operator+= (Node& node1,u32 time) {
    node1.set_time(node1.get_time() + time);
}

ostream& operator<<(ostream& os, Node& n) {
    os << n.id << " AT " << n.time;
    return os;
}


template Manager<Node>::Manager();
template void Manager<Node>::cmd_set_endTime(u32 endTime);
template void Manager<Node>::cmd_check_schedule(u32 costTime,u32 deadLine);
template void Manager<Node>::cmd_add_task(string taskName,u32 costTime);
template void Manager<Node>::cmd_add_ta(std::string id, u32 begin);
template void Manager<Node>::result();
