#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isOpening(char c)
{
    if(c == '{' || c == '[' || c == '(' || c == '<')
        return 1;
    else
        return 0;
}

int isClosing(char c)
{
    if(c == '}' || c == ']' || c == ')' || c == '>')
        return 1;
    else
        return 0;
}

int match(char prev, char c)
{
    if(prev == '{' && c == '}')
        return 1;
    else if(prev == '[' && c == ']')
        return 1;
    else if(prev == '(' && c == ')')
        return 1;
    else if(prev == '<' && c == '>')
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        int ctr = 0;
        stack<char> q;
        for(int idx = 0; idx < s.length(); idx++)
        {
            char c = s[idx];
            if(isOpening(c))
            {
                q.push(c);
                ctr++;
            }
            else if(isClosing(c))
            {
                if(!q.empty() && match(q.top(), c))
                    q.pop();
                ctr--;
            }
        }
        int valid;
        if(q.size() == 0 && ctr == 0)
            valid = 1;
        else
            valid = 0;
        if(valid)
            cout << "Case " << i << ": Yes\n";
        else
            cout << "Case " << i << ": No\n";
    }
}
