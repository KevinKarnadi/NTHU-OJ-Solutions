#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length();
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
        if(i - 1 >= 0 && s[i] == s[i - 1])
        {
            ans++;
            s[i] = 'X';
        }
        else if(i - 2 >= 0 && s[i] == s[i - 2])
        {
            ans++;
            s[i] = 'X';
        }
    }
    cout << ans << endl;
}
