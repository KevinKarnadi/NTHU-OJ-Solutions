#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    deque<int> q;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(i >= l)
        {
            if(ans == *q.begin())
            {
                ans = *++q.begin();
                deque<int>::iterator itr;
                for(itr = ++q.begin(); itr != q.end(); itr++)
                {
                    if(*itr > ans)
                        ans = *itr;
                }
            }
            q.pop_front();
        }
        q.push_back(x);
        if(x > ans)
            ans = x;

        if(i >= l - 1)
            cout << ans << ' ';
    }
    cout << '\n';
}
