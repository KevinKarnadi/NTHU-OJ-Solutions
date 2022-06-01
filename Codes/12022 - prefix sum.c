#include<stdio.h>

int main()
{
    int n,num;
    scanf("%d",&n);
    unsigned long long sum[n];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        sum[i]=sum[i-1]+num;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        unsigned long long ans=sum[r]-sum[l-1];
        printf("%llu\n",ans);
    }
    return 0;
}
