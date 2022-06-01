#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char p[n][m];
    for(int i=0; i<n; i++)
    {
        scanf("%s",&p[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int x,y=0;
        scanf("%d",&x);
        x--;
        int start=1;
        while(start)
        {
            if(p[y][x]=='/')
            {
                if(x==0)
                {
                    printf("Left!\n");
                    start=0;
                }
                else if(p[y][x-1]=='/')
                {
                    y++;
                    x--;
                    if(y==n-1)
                    {
                        printf("Position: %d\n",x);
                        start=0;
                    }
                }
                else
                {
                    printf("Stuck QQ\n");
                    start=0;
                }
            }
            else if(p[y][x]=='\\')
            {
                if(x==m-1)
                {
                    printf("Right!\n");
                    start=0;
                }
                else if(p[y][x+1]=='\\')
                {
                    y++;
                    x++;
                    if(y==n-1)
                    {
                        printf("Position: %d\n",x);
                        start=0;
                    }
                }
                else
                {
                    printf("Stuck QQ\n");
                    start=0;
                }
            }
        }
    }
    return 0;
}
