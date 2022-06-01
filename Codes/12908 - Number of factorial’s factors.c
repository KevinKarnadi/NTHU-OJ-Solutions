#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int p[n];
    int ctr=0;
    for(int i=2; i<=n; i++)
    {
        int prime=1;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                prime=0;
            }
        }
        if(prime)
        {
            p[ctr]=i;
            ctr++;
        }
    }
    unsigned long long ans=1;
    for(int i=0;i<ctr;i++)
    {
        int cnt=0;
        int power=1;
        while(n/pow(p[i],power)!=0)
        {
            cnt+=n/pow(p[i],power);
            power++;
        }
        ans=ans*(cnt+1);
    }
    printf("%llu",ans);
    return 0;
}
