#include<stdio.h>
#define max(a,b) (a>b ? a:b)
int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int dp[100];
    long long max=0;
    for(int i=0;i<n;i++)
    {
        if(i<2)
            dp[i]=arr[i];
        else if(i==2)
            dp[i]=arr[i]+arr[i-2];
        else
            dp[i]=arr[i]+max(dp[i-2],dp[i-3]);
        if(dp[i]>max)
            max=dp[i];
    }
    printf("%lld ",max);
}
