#include <iostream>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int len = s.length();
        string word = "";
        int found = 0;
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] == ' ' && word != "")
            {
                if(found == 1)
                    cout << " ";
                int lenw = word.length();
                for(int i = lenw - 1; i >= 0; i--)
                    cout << word[i];
                word = "";
                found = 1;
            }
            else if(s[i] != ' ')
                word += s[i];
        }
        if(word != "")
        {
            if(found == 1)
                cout << " ";
            int lenw = word.length();
            for(int i = lenw - 1; i >= 0; i--)
                cout << word[i];
        }
        cout << endl;
    }
}
