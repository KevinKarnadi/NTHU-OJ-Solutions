#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string order[1001];
    int score[1001];
    for(int i = 0; i < n; i++)
    {
        string s;
        int c;
        cin >> s >> c;
        for(int j = 0; j <= i; j++)
        {
            if(score[j] < c)
            {
                for(int k = i; k > j; k--)
                {
                    order[k] = order[k-1];
                    score[k] = score[k-1];
                }
                order[j] = s;
                score[j] = c;
                break;
            }
            else if(j == i)
            {
                order[j] = s;
                score[j] = c;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << order[i] << endl;
}
