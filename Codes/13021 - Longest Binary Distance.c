#include<stdio.h>

int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        unsigned long long n;
        scanf("%llu", &n);
        int start = 0;
        int cnt = 0;
        int max = 0;
        int one = 0;
        while(n != 0)
        {
            int mod = n % 2;
            if(mod == 1)
            {
                start = 1;
                one++;
                cnt = 0;
            }
            else if(mod == 0 && start)
            {
                cnt++;
                if(cnt > max)
                    max = cnt;
            }
            n /= 2;
        }
        if(one < 2)
            printf("-1\n");
        else
            printf("%d\n", max);
    }
}
