#include<stdio.h>
int n,k,t,y;
int x[10],used[10];
void solve(int sum,int idxh,int N)
{
    if(N==n && idxh==k)
        y=1;
    else
    {
        for(int i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            if(sum+x[i]==t)
                solve(0,idxh+1,N+1);
            else if(sum+x[i]<t)
                solve(sum+x[i],idxh,N+1);
            used[i]=0;
        }
    }
    }
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&k);
        int total=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            total+=x[i];
            used[i]=0;
        }
        if(total%k==0)
        {
            t=total/k;
            y=0;
            solve(0,0,0);
            if(y)
                printf("True\n");
            else
                printf("False\n");
        }
        else
            printf("False\n");
    }
}
