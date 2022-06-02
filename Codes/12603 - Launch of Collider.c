#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char dir[n];
    scanf("%s", dir);

    long long x;
    long long prev = NULL;
    long long ans = NULL;
    for(int i = 0; i < n; i++)
    {
        long long dist;
        scanf("%lld", &x);
        if(dir[i] == 'R')
            prev = x;
        else
        {
            if(prev != NULL)
            {
                dist = (x - prev) / 2;
                if(ans == NULL || dist < ans)
                    ans = dist;
            }
        }
    }
    printf("%d\n", ans == NULL ? -1 : ans);
}
