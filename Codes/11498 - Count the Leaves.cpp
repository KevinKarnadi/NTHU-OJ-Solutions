#include <iostream>
using namespace std;

int main()
{
    int n;
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        bool isLeaf[1001] = {false};
        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            isLeaf[x] = false;
            isLeaf[y] = true;
        }
        int temp;
        cin >> temp;

        int cnt = 0;
        for(int i = 1; i <= 1000; i++)
        {
            if(isLeaf[i])
                cnt++;
        }
        cout << cnt << endl;
    }
}
