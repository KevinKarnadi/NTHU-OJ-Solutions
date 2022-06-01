#include<stdio.h>
#define swap(a,b){a^=b;b^=a;a^=b;}
char a[3][4];
char b[3][4];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int yes;
void solve(int y,int x,int k)
{
    if(y>=0 && y<3 && x>=0 && x<3)
    {
        int same=1;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(a[i][j]!=b[i][j])
                    same=0;
        if(same)
            yes=1;
        if(k>0)
        {
            for(int i=0;i<4;i++)
            {
                swap(a[y][x],a[y+dy[i]][x+dx[i]]);
                solve(y+dy[i],x+dx[i],k-1);
                swap(a[y][x],a[y+dy[i]][x+dx[i]]);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%d",&k);
        int y,x;
        for(int i=0; i<3; i++)
        {
            scanf("%s",a[i]);
            for(int j=0; j<3; j++)
            {
                if(a[i][j]=='x')
                {
                    y=i;
                    x=j;
                }
            }
        }
        for(int i=0; i<3; i++)
            scanf("%s",b[i]);
        yes=0;
        solve(y,x,k);
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
