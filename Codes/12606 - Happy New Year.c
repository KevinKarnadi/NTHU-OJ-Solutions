#include<stdio.h>
#define ll long long

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n;
    scanf("%d", &n);

    ll s, x[n];
    scanf("%lld", &s);
    for(int i = 0; i < n; i++)
        scanf("%lld", &x[i]);
    qsort(x, n, sizeof(ll), cmp);

    ll ans = 0;
    ll prev = s;
    for(int i = 0; i < n; i++)
    {
        ans += abs(prev - x[i]);
        prev = x[i];
    }
    ans += abs(prev - s);

    printf("%lld\n", ans);
}
