#include<stdio.h>
#define ll long long

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll ans = 0;
        for(ll i = 9; i <= b; i = i * 10 + 9)
            ans++;
        ans *= a;
        printf("%lld\n", ans);
    }
}
