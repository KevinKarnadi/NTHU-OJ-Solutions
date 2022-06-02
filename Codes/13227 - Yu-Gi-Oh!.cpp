#include <iostream>
#include <map>
using namespace std;

map<long long, long long> cnt;
long long ace = -1;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long x;
        cin >> x;
        if(cnt.find(x) == cnt.end())
            cnt.insert(pair<long long, long long>(x, 0));
        cnt[x]++;
        if(ace == -1 || cnt[x] > cnt[ace] || (cnt[x] == cnt[ace] && x > ace))
            ace = x;

        cout << ace << endl;
    }
}
