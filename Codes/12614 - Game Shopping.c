#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int c[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int x[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &x[i]);

    int ans = 0;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(c[i] <= x[idx])
        {
            ans++;
            idx++;
        }
    }
    printf("%d\n", ans);
}
