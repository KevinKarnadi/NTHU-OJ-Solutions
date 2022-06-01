#include<stdio.h>
int n,m;
int p[22][22];
int dy[5]={0,1,0,-1,0};
int dx[5]={0,0,1,0,-1};
long long ans=1e9;
int check()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(p[i][j]==0)
                return 0;
    return 1;
}
void solve(int y,int x,long long cnt)
{
    for(int i=0;i<2;i++)
    {
        if(i)
            turn(y,x);
        if(y==n && x==m)
        {
            if(check() && cnt+i<ans)
                ans=cnt+i;
        }
        else if(x==m)
            solve(y+1,1,cnt+i);
        else
            solve(y,x+1,cnt+i);
        if(i)
            turn(y,x);
    }
}
void turn(int y,int x)
{
    for(int i=0;i<5;i++)
        p[y+dy[i]][x+dx[i]]=(p[y+dy[i]][x+dx[i]]+1)%2;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&p[i][j]);
    solve(1,1,0);
    if(ans==1e9)
        printf("no solution\n");
    else
        printf("%lld\n",ans);
}
