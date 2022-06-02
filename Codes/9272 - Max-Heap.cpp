#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int>> h;

    string cmd;
    while(cin >> cmd)
    {
        if(cmd == "PUSH")
        {
            int a;
            cin >> a;
            h.push(a);
        }
        else if(cmd == "POP")
        {
            h.pop();
        }
        else if(cmd == "TOP")
        {
            if(h.empty())
                cout << "Null\n";
            else
                cout << h.top() << endl;
        }
    }
}
