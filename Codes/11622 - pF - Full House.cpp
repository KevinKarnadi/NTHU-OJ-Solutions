#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string A = "z", B = "z";
        int cntA = 0, cntB = 0;
        for(int i = 0; i < 5; i++)
        {
            string card;
            cin >> card;
            if(A == "z" && card != B)
                A = card;
            else if(B == "z" && card != A)
                B = card;
            if(card == A)
                cntA++;
            else if(card == B)
                cntB++;
        }
        if((cntA == 2 && cntB == 3) ||
           (cntA == 3 && cntB == 2))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
