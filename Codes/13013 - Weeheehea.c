#include<stdio.h>
#define ull unsigned long long
int main()
{
    char x[11];
    ull ctr[50000];
    for(int i=0;i<50000;i++)
    {
        ctr[i]=0;
    }
    ull t;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%s",x);
        int power=0;
        ull sum=0;
        for(int i=9;i>=0;i--)
        {
            if(x[i]=='x')
                sum+=2*pow(3,power++);
            else
                sum+=(x[i]-'0')*pow(3,power++);
        }
        ctr[sum]++;
    }
    ull ans=0;
    for(int i=0;i<50000;i++)
        if(ctr[i]>0)
            ans++;
    printf("%llu\n",ans);
}
