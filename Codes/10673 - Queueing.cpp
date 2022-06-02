#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string cmd;
    queue<string> q;
    while(cin >> cmd)
    {
        if(cmd == "Push")
        {
            string name;
            cin >> name;
            q.push(name);
        }
        else if(cmd == "Pop")
        {
            if(!q.empty())
                q.pop();
        }
        else if(cmd == "Front")
        {
            if(q.empty())
                cout << "empty" << endl;
            else
                cout << q.front() << endl;
        }
    }
}
