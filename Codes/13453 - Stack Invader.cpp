#include <iostream>
#include <string>
using namespace std;

template<class T>
class BaseStack
{
public:
    BaseStack();
    ~BaseStack();
    bool empty();
    int size();
    T& top();
    void push(const T& item);
    void pop();
    char getitem(int lvl);
private:
    T* _stack;
    int _top;
    int _capacity;
};

template<class T>
class BaseQueue
{
public:
    BaseQueue();
    ~BaseQueue();
    bool empty();
    int size();
    T& front();
    void push(const T& item);
    void pop();
private:
    T* _queue;
    int _front, _rear;
    int _capacity;
};

void InitialzeStage(int W, int H);
void ShootNormal(int col, int W);
void ShootSpecial(int col, int W);
void FrontRow(int W);
void ShowResult(int W);
void deleteStage();

int WIDTH;
int HEIGHT;
int MAXLVL;
BaseStack<char> *lane;
BaseQueue<char> specials;

// class BaseStack

// Constructor
template<class T>
BaseStack<T>::BaseStack() {
    this->_stack = new T[2];
    this->_top = 0;
    this->_capacity = 2;
}

// Destructor
template<class T>
BaseStack<T>::~BaseStack() {
    delete [] _stack;
}

// Check if the stack is empty
template<class T>
bool BaseStack<T>::empty() {
    if(this->_top == 0)
        return true;
    return false;
}

// Return the size of the stack
template<class T>
int BaseStack<T>::size() {
    return this->_top;
}

// Return the top element
template<class T>
T& BaseStack<T>::top() {
    return this->_stack[this->_top];
}

// Insert a new element at top
template<class T>
void BaseStack<T>::push(const T& item) {
    if(item == '0') {  // Update _top
        while(!this->empty() && this->_stack[this->_top] == '_')
            this->pop();
    }
    else {
        if(this->_top == this->_capacity - 2) {
            int new_c = this->_capacity * 2 - 1;
            T* temp = new T[new_c];
            int len = this->size();
            for (int i = 1; i <= len; i++)
                 temp[i] = this->_stack[i];
            delete [] this->_stack;
            this->_stack = temp;
            this->_capacity = new_c;
        }
        this->_stack[++this->_top] = item;
    }
}

// Delete one element from top
template<class T>
void BaseStack<T>::pop() {
    this->_stack[this->_top--] = '_';
    if(this->_top < (this->_capacity - 1) / 4 - 1) {
        int new_c = (this->_capacity - 1) / 2 + 1;
        T* temp = new T[new_c];
        int len = this->size();
        for (int i = 1; i <= len; i++)
            temp[i] = this->_stack[i];
        delete [] this->_stack;
        this->_stack = temp;
        this->_capacity = new_c;
    }
}

template<class T>
char BaseStack<T>::getitem(int lvl) {
    return this->_stack[lvl];
}

// class BaseQueue

// Constructor
template<class T>
BaseQueue<T>::BaseQueue() {
    this->_queue = new T[1];
    this->_front = -1;
    this->_rear = -1;
    this->_capacity = 1;
}

// Destructor
template<class T>
BaseQueue<T>::~BaseQueue() {
    delete [] _queue;
}

// Check if the queue is empty
template<class T>
bool BaseQueue<T>::BaseQueue::empty() {
    if(this->_front == -1 && this->_rear == -1)
        return true;
    return false;
}

// Return the size of the queue
template<class T>
int BaseQueue<T>::size() {
    int len = this->_rear - this->_front + 1;
    if(this->empty())
        return 0;
    else if(this->_rear >= this->_front)
        return len;
    else
        return len + this->_capacity;
}

// Return the front element
template<class T>
T& BaseQueue<T>::front() {
    return this->_queue[this->_front];
}

// Insert a new element at rear
template<class T>
void BaseQueue<T>::push(const T& item) {
    if(this->size() == this->_capacity) {
        int new_c = this->_capacity * 2;
        T* temp = new T[new_c];
        int len = this->size();
        int fr = this->_front;
        for(int i = 0; i < len; i++)
            temp[i] = this->_queue[(fr + i) % this->_capacity];
        delete [] this->_queue;
        this->_queue = temp;
        this->_front = 0;
        this->_rear = len - 1;
        this->_capacity = new_c;
    }
    this->_rear = (this->_rear + 1) % this->_capacity;
    this->_queue[this->_rear] = item;
    if(this->_front == -1)
        this->_front = this->_rear;
}

// Delete one element from front
template<class T>
void BaseQueue<T>::pop() {
    this->_queue[this->_front] = '0';
    if(this->size() == 1) {
        this->_front = -1;
        this->_rear = -1;
    }
    else {
        this->_front = (this->_front + 1) % this->_capacity;
        if(this->size() < (this->_capacity / 4) - 1) {
            int new_c = this->_capacity / 2;
            T* temp = new T[new_c];
            int len = this->size();
            int fr = this->_front;
            for(int i = 0; i < len; i++)
                temp[i] = this->_queue[(fr + i) % this->_capacity];
            delete [] this->_queue;
            this->_queue = temp;
            this->_front = 0;
            this->_rear = len - 1;
            this->_capacity = new_c;
        }
    }
}

// Game Functions

// Loading the stage
void InitialzeStage(int W, int H) {
    WIDTH = W;
    HEIGHT = H;
    lane = new BaseStack<char>[W];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char n;
            cin >> n;
            lane[j].push(n);
        }
    }
    for(int i = 0; i < W; i++)
        lane[i].push('0');
}

// Function for shooting a normal bullet
void ShootNormal(int col, int W) {
    if((col < 0 || col >= W) || lane[col].empty())
        return;
    char killed = lane[col].top();
    lane[col].pop();
    lane[col].push('0');
    if(killed == '2')
        specials.push('2');
    else if(killed == '3')
        specials.push('3');
    else if(killed == '4')
        specials.push('4');
    else if(killed == '5') {
        int c = col - 2;
        int p = 0;
        for(int i = (c < 0) ? 0 : c; i <= col + 2 && i < W; i++) {
            if(lane[i].size() > p)
                p = lane[i].size();
        }
        for(int i = (c < 0) ? 0 : c; i <= col + 2 && i < W; i++) {
            for(int j = lane[i].size() + 1; j <= p; j++)
                lane[i].push('_');
            for(int j = 0; j < 3; j++)
                lane[i].push('1');
        }
    }
}

// Function for shooting a special bullet
void ShootSpecial(int col, int W) {
    if((col < 0 || col >= W) || specials.empty())
        return;
    char sp = specials.front();
    specials.pop();
    if(sp == '2') {
        int c = col - 2;
        for(int i = (c < 0) ? 0 : c; i <= col + 2 && i < W; i++)
            ShootNormal(i, W);
    }
    else if(sp == '3') {
        for(int i = 0; i < 3; i++)
            ShootNormal(col, W);
    }
    else if(sp == '4') {
        int enemy = lane[col].top();
        while(lane[col].top() == enemy)
            ShootNormal(col, W);
    }
}

// Function that show the front row of the current stage
// Here, as the description on the OJ, you need to find the maximum level that contains any enemy.
// print the enemy types at that level for each column.
// print a underline "_" for a column that does not have a enemy at that level.
void FrontRow(int W) {
    int highest = 0;
    for(int i = 0; i < W; i++) {
        if(lane[i].size() > highest)
            highest = lane[i].size();
    }
    MAXLVL = highest;
    cout << "FRONT_ROW, LEVEL:" << MAXLVL << endl;
    if(MAXLVL == 0)
        return;
    for(int i = 0; i < W; i++) {
        if(lane[i].size() == MAXLVL)
            cout << lane[i].top();
        else
            cout << '_';
        if(i < W - 1)
            cout << ' ';
    }
    cout << endl;
}

// Print the end result of the stage.
void ShowResult(int W) {
    int highest = 0;
    for(int i = 0; i < W; i++) {
        if(lane[i].size() > highest)
            highest = lane[i].size();
    }
    MAXLVL = highest;
    cout << "END_RESULT:" << endl;
    for(int i = 1; i <= MAXLVL; i++) {
        for(int j = 0; j < W; j++) {
            if(lane[j].size() >= i)
                cout << lane[j].getitem(i);
            else
                cout << '_';
            if(j < W - 1)
                cout << ' ';
        }
        cout << endl;
    }
}

// free the memory that allocated in the program.
void deleteStage() {
    delete [] lane;
}
