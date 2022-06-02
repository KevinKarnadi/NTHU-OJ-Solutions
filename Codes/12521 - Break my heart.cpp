#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int, less<int>> s;
    set<int, less<int>>::iterator itr;

    int n;
    cin >> n;
    while(n--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "insert")
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        else if(cmd == "print")
        {
            for(itr = s.begin(); itr != s.end(); itr++)
            {
                if(itr == --s.end())
                    cout << *itr << endl;
                else
                    cout << *itr << ' ';
            }
        }
        else if(cmd == "min")
        {
            if(!s.empty())
                cout << *(s.begin()) << endl;
        }
        else if(cmd == "range_erase")
        {
            int l, r;
            cin >> l >> r;
            s.erase(s.lower_bound(l), s.upper_bound(r));
        }
    }
}
