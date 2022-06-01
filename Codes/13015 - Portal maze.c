#include<stdio.h>
int R,C;
char p[300][301];
int v[300][300];
int yp[26],xp[26];
int yes;
void solve(int y,int x)
{
    if(y>=0 && y<R && x>=0 && x<C && p[y][x]!='#')
    {
        v[y][x]=0;
        if(p[y][x]=='&')
            yes=1;
        else if(p[y][x]>='a' && p[y][x]<='z')
            solve(yp[p[y][x]-'a'],xp[p[y][x]-'a']);
        else if(yes==0)
        {
            if(v[y-1][x])
                solve(y-1,x);
            if(v[y][x+1])
                solve(y,x+1);
            if(v[y+1][x])
                solve(y+1,x);
            if(v[y][x-1])
                solve(y,x-1);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&R,&C);
        int y,x;
        for(int i=0;i<R;i++)
        {
            scanf("%s",p[i]);
            for(int j=0;j<C;j++)
            {
                v[i][j]=1;
                if(p[i][j]=='$')
                {
                    y=i;
                    x=j;
                }
                else if(p[i][j]>='A' && p[i][j]<='Z')
                {
                    yp[p[i][j]-'A']=i;
                    xp[p[i][j]-'A']=j;
                }
            }
        }
        yes=0;
        solve(y,x);
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
