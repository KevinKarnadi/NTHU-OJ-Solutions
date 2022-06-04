#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string word = "";
    for(int i = 0; i < s.length()+1; i++)
    {
        if(s[i] == ' ' || s[i] == '\0')
        {
            if(word == "")
                continue;
            cout << word << endl;
            word = "";
        }
        else
            word += s[i];
    }
}
