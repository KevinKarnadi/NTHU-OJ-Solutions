#include<stdio.h>
int r,c;
char p[100][101];
int v[100][100];
int total,min;
void solve(int y,int x,int step)
{
    if(y>=0 && y<r && x>=0 && x<c && p[y][x]!='#' && v[y][x])
    {
        if(p[y][x]=='F')
        {
            total++;
            if(min==0 || step<min)
            {
                min=step;
            }
            return;
        }
        v[y][x]=0;
        solve(y-1,x,step+1);
        solve(y,x+1,step+1);
        solve(y+1,x,step+1);
        solve(y,x-1,step+1);
        v[y][x]=1;
    }
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&r,&c);
        int y,x;
        for(int i=0;i<r;i++)
        {
            scanf("%s",p[i]);
            for(int j=0;j<c;j++)
            {
                v[i][j]=1;
                if(p[i][j]=='S')
                {
                    y=i;
                    x=j;
                }
            }
        }
        total=0;
        min=0;
        solve(y,x,0);
        if(total==0)
            printf("0 -1\n");
        else
            printf("%d %d\n",total,min);
    }
}
