#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num;
    unsigned long long x[10001]={0};
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num);
        x[num]++;
    }
    unsigned long long ans=0;
    for(int i=0; i<10001; i++)
    {
        ans=ans+x[i]*(x[i]-1)/2;
    }
    printf("%llu\n",ans);
    return 0;
}
