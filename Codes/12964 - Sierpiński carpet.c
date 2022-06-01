#include<stdio.h>
int n;
int sz;
char p[2187][2187];
void solve(int sz, int y, int x)
{
    if(sz<3)
        return;
    int block=sz/3;
    for(int i=y+block;i<y+block*2;i++)
        for(int j=x+block;j<x+block*2;j++)
            p[i][j]='#';
    for(int i=y;i<=y+block*2;i+=block)
        for(int j=x;j<=x+block*2;j+=block)
            if(i!=block || j!=block)
                solve(block,i,j);
}
int main()
{
    scanf("%d",&n);
    sz=pow(3,n);
    for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            p[i][j]='.';
    solve(sz,0,0);
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
            printf("%c",p[i][j]);
        printf("\n");
    }
}
