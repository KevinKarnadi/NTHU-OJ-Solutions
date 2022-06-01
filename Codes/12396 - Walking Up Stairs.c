#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long x[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
        {
            x[i]=1;
        }
        else
        {
            x[i]=x[i-1]+x[i-3];
        }
    }
    printf("%llu\n",x[n]);
    return 0;
}
