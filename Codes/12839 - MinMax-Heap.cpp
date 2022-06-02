#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int, less<int>> s;
    multiset<int, less<int>>::iterator itr;

    string cmd;
    while(cin >> cmd)
    {
        if(cmd == "PUSH")
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        else if(cmd == "POPMIN")
        {
            if(!s.empty())
                s.erase(s.begin());
        }
        else if(cmd == "POPMAX")
        {
            if(!s.empty())
                s.erase(--s.end());
        }
        else if(cmd == "MIN")
        {
            if(s.empty())
                cout << "Null\n";
            else
                cout << *s.begin() << endl;
        }
        else if(cmd == "MAX")
        {
            if(s.empty())
                cout << "Null\n";
            else
                cout << *s.rbegin() << endl;
        }
        else if(cmd == "CLEAR")
        {
            s.clear();
        }
    }
}
