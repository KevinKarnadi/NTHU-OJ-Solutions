#include<stdio.h>
int n;
int v[3][20];
int total=0;
void solve(int y,int x,int fill)
{
    if(fill==3*n)
    {
        total++;
        return;
    }
    if(y>=0 && y<3 && x>=0 && x<n)
    {
        if(v[y][x])
        {
            if(x<n-1 && v[y][x+1])
            {
                v[y][x]=0;
                v[y][x+1]=0;
                if(x==n-2)
                    solve(y+1,0,fill+2);
                else
                    solve(y,x+1,fill+2);
                v[y][x]=1;
                v[y][x+1]=1;
            }
            if(y<2 && v[y+1][x])
            {
                v[y][x]=0;
                v[y+1][x]=0;
                if(x==n-1)
                    solve(y+1,0,fill+2);
                else
                    solve(y,x+1,fill+2);
                v[y][x]=1;
                v[y+1][x]=1;
            }
        }
        else
        {
            if(x==n-1)
                solve(y+1,0,fill);
            else
                solve(y,x+1,fill);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            v[i][j]=1;
        }
    }
    solve(0,0,0);
    printf("%d\n",total);
}
