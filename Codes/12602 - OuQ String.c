#include<stdio.h>
#define ll long long

ll k, l, r;
ll len[51];
ll idx;

void solve(int k)
{
    if(idx + len[k] <= l)
    {
        idx += len[k];
        return;
    }
    if(k == 1)
    {
        if(idx >= l && idx <= r)
            printf("O");
        idx++;
        if(idx >= l && idx <= r)
            printf("u");
        idx++;
        if(idx >= l && idx <= r)
            printf("Q");
        idx++;
    }
    else
    {
        if(idx >= l && idx <= r)
            printf("O");
        idx++;

        if(idx <= r)
            solve(k - 1);

        if(idx >= l && idx <= r)
            printf("u");
        idx++;

        if(idx <= r)
            solve(k - 1);

        if(idx >= l && idx <= r)
            printf("Q");
        idx++;
    }
}

int main()
{
    len[1] = 3;
    for(int i = 2; i <= 50; i++)
        len[i] = 3 + 2*len[i - 1];

    while(scanf("%lld %lld %lld", &k, &l, &r) != EOF)
    {
        idx = 0;
        solve(k);
        printf("\n");
    }
}
