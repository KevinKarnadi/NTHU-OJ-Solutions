#include<stdio.h>
int n;
int p[10][10];
int posrow[10];
long long ans=-10e9;
void solve(int idx,long long val)
{
    if(idx==n)
    {
        if(val>ans)
            ans=val;
        return;
    }
    for(int i=0;i<n;i++)
    {
        int yes=1;
        for(int j=0;j<idx;j++)
        {
            if(posrow[j]==i || j+posrow[j]==idx+i || j-posrow[j]==idx-i)
                yes=0;
        }
        if(yes)
        {
            posrow[idx]=i;
            solve(idx+1,val+p[idx][i]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&p[i][j]);
    solve(0,0);
    if(ans==-10e9)
        printf("no solution\n");
    else
        printf("%lld\n",ans);
}
