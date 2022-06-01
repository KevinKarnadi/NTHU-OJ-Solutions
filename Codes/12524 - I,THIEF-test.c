#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int dp[100];
    int from[100];
    dp[0]=arr[0];
    from[0]=-2;
    dp[1]=arr[1]>arr[0] ? arr[1]:arr[0];
    from[1]=arr[1]>arr[0] ? -1:0;
    for(int i=2;i<n;i++)
    {
        if(dp[i-1] > arr[i]+dp[i-2])
        {
            dp[i]=dp[i-1];
            from[i]=i-1;
        }
        else
        {
            dp[i]=arr[i]+dp[i-2];
            from[i]=i-2;
        }
    }
    int ctr=0;
    int ans[100];
    for(int i=n-1;i>=0;i--)
    {
        if(from[i]==i-2)
        {
            ans[ctr++]=i+1;
            i--;
        }
    }
    for(int i=ctr-1;i>=0;i--)
    {
        printf("%d ",ans[i]);
    }
}
